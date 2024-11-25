#include "pantalla final.h"

PantallaFinal::PantallaFinal(RenderWindow* App, int score) : App(App), score(score) {}
PantallaFinal::PantallaFinal() : App(nullptr), score(0) {}
void PantallaFinal::cargarAssets() {
    //cargamos todos los recuros graficos, creamos los sprites y posicionamos
    backgroundTexture.loadFromFile("../../Assets/fondo.png");
    background.setTexture(backgroundTexture);
    gameOverTexture.loadFromFile("../../Assets/game over.png");
    gameOver.setTexture(gameOverTexture);
    gameOver.setPosition(100, 100);

    //cargamos la fuente que queremos utilizar
    font.loadFromFile("../../Tipografía/Montserrat-SemiBold.ttf");

    //configuramos cada texto
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(Color::Black);
    scoreText.setString("Puntaje final: " + to_string(score));
    scoreText.setPosition(325, 350);

    exitText.setFont(font);
    exitText.setCharacterSize(20);
    exitText.setFillColor(Color::Red);
    exitText.setString("Presiona ESC para salir");
    exitText.setPosition(315, 500);
}

void PantallaFinal::run() {
    while (App->isOpen()) {
        Event event;
        while (App->pollEvent(event)) {
            switch (event.type) {
            case Event::Closed:
                    App->close();
                    break;
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                App->close();
            }
        }
        //dibujamos todo
        App->clear();
        App->draw(background);
        App->draw(gameOver);
        App->draw(scoreText);
        App->draw(exitText);
        App->display();
    }
}
