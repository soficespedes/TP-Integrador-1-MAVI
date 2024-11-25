#include "juego.h"

Juego::Juego(RenderWindow* App) : App(App) {}

void Juego::cargarAssets() {
    //cargamos la textura del fondo
    backgroundTex.loadFromFile("../../Assets/fondo.png");
    background.setTexture(backgroundTex);

    //cargamos las texturas de las clases correspondientes
    crosshair.cargarAssets();
    angel.cargarAssets();
    orangeDemon = new OrangeDemon("../../Assets/or_demonio.png");
    currentDemon = new Demon("../../Assets/demonio.png");

    //cargamos la fuente del texto
    font.loadFromFile("../../Tipografía/Montserrat-SemiBold.ttf");

   //configuramos los textos
    exitText.setFont(font);
    exitText.setString("Presiona ESC para salir");
    exitText.setCharacterSize(16);
    exitText.setFillColor(Color::Red);
    exitText.setPosition(10, 10);
  
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(Color::Black);
    scoreText.setPosition(650, 10);
    scoreText.setString("Demonios abatidos: 0");
   
    lifeText.setFont(font);
    lifeText.setCharacterSize(24);
    lifeText.setFillColor(Color::Green);
    lifeText.setPosition(10, 650);
    lifeText.setString("Vidas: " + to_string(crosshair.getLives()));
}
//ejecutamos el bucle principal
void Juego::run() {
    App->setMouseCursorVisible(false); //ocultamos el cursor del mouse
    Clock angelClock; //controlamos el tiempo de aparición de ángeles
    Clock gameClock; //para calcular el tiempo transcurrido entre cuadros
    Clock spawnClock; //controlamos el tiempo de aparición de demonios
    int score = 0; //la puntuacion comienza en 0
  
    while (App->isOpen()) {
        float deltaTime = gameClock.restart().asSeconds(); 
        Event event;
        while (App->pollEvent(event)) {
            switch (event.type) {
            case Event::Closed:
                App->close();
                break;
            }
            if (event.key.code == Keyboard::Escape) {
                App->close(); 
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                //obtenemos la posicion del clic
                Vector2f mousePosition = App->mapPixelToCoords(Mouse::getPosition(*App));

                //verificamos si el clic es sobre el demonio
                if (currentDemon && currentDemon->isHit(mousePosition)) {
                    currentDemon->teleport();//teletransportamos al demonio
                    score++;  //aumentamos la puntuación y actualizamos el texto
                    scoreText.setString("Demonios abatidos: " + to_string(score));
                }
                //verificamos si el clic es sobre el demonio naranja
                if (orangeDemonActive && orangeDemon->isHit(mousePosition)) {
                    score ++; //aumentamos la puntuación
                    scoreText.setString("Demonios abatidos: " + to_string(score));
                    orangeDemonActive = false; //desactivamos (desaparece) el demonio naranja
                }
                //verificamos si el clic es sobre el angel 
                if (angel.isHit(mousePosition)) {
                    angelesDisparados++;
                    crosshair.reduceLife(); //si es asi, reducimos la vida y actualizamos el texto
                    lifeText.setString("Vidas: " + to_string(crosshair.getLives()));

                    //termina el juego si las vidas llegan a 0
                    if (crosshair.getLives() == 0) {
                        int finalScore = score - (angelesDisparados * 2);                   
                        PantallaFinal pantallaFinal(App, finalScore);
                        pantallaFinal.cargarAssets();
                        pantallaFinal.run();
                        return;
                    }
                }
            }
        }
        //controlamos la aparición del demonio naranja
        if (!orangeDemonActive && orangeDemonClock.getElapsedTime().asSeconds() > orangeDemonAppearDelay) {
            orangeDemon->teleport(); //se teletransporta a una nueva posición
            orangeDemon->resetVisibilityTimer(); //se reinicia el temporizador
            orangeDemonActive = true; //se activa el demonio naranja
            orangeDemonClock.restart(); //se reinicia el temporizador de aparición
        }

        //actualizamos el tiempo en pantalla del demonio naranja
        if (orangeDemonActive) {
            orangeDemon->update(deltaTime); //incrementa el temporizador interno

            //si el demonio naranja excede el tiempo máximo, desaparece y resta una vida
            if (orangeDemon->shouldDisappear()) {
                crosshair.reduceLife(); //reduce una vida
                lifeText.setString("Vidas: " + to_string(crosshair.getLives()));
                orangeDemonActive = false; //desactivar (desaparece) el demonio naranja

                if (crosshair.getLives() == 0) {
                    int finalScore = score - (angelesDisparados * 2);
                    PantallaFinal pantallaFinal(App, finalScore);
                    pantallaFinal.cargarAssets();
                    pantallaFinal.run();
                    return; //salir del bucle principal
                }
            }
        }
        //aparece un nuevo angel cada 2 segundos
        if (angelClock.getElapsedTime().asSeconds() > angelAppearDelay) {
            angel.spawn(); //hacer que el angel aparezca
            angelClock.restart(); //reiniciamos el contador
        }
        //obtenemos la posición del mouse
        Vector2f mousePosition = App->mapPixelToCoords(Mouse::getPosition(*App));

        //actualizamos el crosshair
        crosshair.update(mousePosition);

        //dibujamos la escena
        App->clear();
        App->draw(background);//fondo
        if (currentDemon) {
            currentDemon->draw(*App); //demonio rojo
        }
        if (orangeDemonActive) { //demonio naranja 
            orangeDemon->draw(*App);
        }
        angel.draw(*App); //angel
        crosshair.draw(*App); //crosshair
        App->draw(scoreText); //texto de puntuación
        App->draw(exitText); //texto de salida
        App->draw(lifeText); //texto de vida
        App->display();
    }
    //liberamos memoria
    if (currentDemon) {
        delete currentDemon;
        currentDemon = nullptr;
    }
    if (orangeDemon) {
        delete orangeDemon;
        orangeDemon = nullptr;
    }
}
    