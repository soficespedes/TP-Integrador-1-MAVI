#include "menu.h"
#include "lib.h"
Menu::Menu (RenderWindow* App) : App(App), showInstructions(false){} //se inicializa el programa con el booleano en false
void Menu::cargarAssets() {

    //cargamos todas las texturas que necesitamos para el menú
    backgroundTex.loadFromFile("../../Assets/fondo.png");
    titleTex.loadFromFile("../../Assets/titulo.png");
    instructionTex.loadFromFile("../../Assets/instrucciones.png");

    //creamos los sprites correspondientes
    background.setTexture(backgroundTex);
    title.setTexture(titleTex);
    title.setPosition(75, 100);
    instruction.setTexture(instructionTex);
    instruction.setPosition(17, 200);

    //ajustamos el titulo más pequeño para la pantalla de instrucciones
    smallTitle = title;
    smallTitle.setScale(0.5f, 0.5f);
    smallTitle.setPosition(275, 50);

    //cargamos la fuente que necesitaremos
    font.loadFromFile("../../Tipografía/Montserrat-SemiBold.ttf");

    //configuramos todos los textos
    pressPText.setFont(font); 
    pressPText.setString("Presiona P para continuar");
    pressPText.setCharacterSize(24);
    pressPText.setFillColor(Color::Blue);
    pressPText.setPosition(300, 500);

    startGameText.setFont(font);
    startGameText.setString("Presiona P para comenzar");
    startGameText.setCharacterSize(24);
    startGameText.setFillColor(Color::Blue);
    startGameText.setPosition(300, 600);

    exitText.setFont(font);
    exitText.setString("Presiona ESC para salir");
    exitText.setCharacterSize(16);
    exitText.setFillColor(Color::Red);
    exitText.setPosition(10, 10);
}
//definimos la clase run para ejecutarla
void Menu::run() {
    App->setMouseCursorVisible(false);
    while (App->isOpen()) {
        Event event;
        while (App->pollEvent(event)) {
            switch (event.type) {
            case Event :: Closed:
                App->close();
                break;
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::P) {
                    if (showInstructions) {
                        return; //condicion al presionar P, si no se muestran las instrucciones, al presionar P se mostrarán. 
                                //si se muestran las instrucciones, al volver a presionar P terminará el bucle del menú
                    }
                    showInstructions = true;
                }
                else if (event.key.code == Keyboard::Escape) {
                    App->close(); //cierra la ventana con escape
                }
            }
        }

        //dibujamos todo en pantalla
        App->clear();
        App->draw(background);
        if (!showInstructions) { //si showInstruction es falso, apareceran los siguientes sprites en ventana
           App->draw(title);
           App->draw(pressPText);
           App->draw(exitText);
        }
        else {
            App->draw(smallTitle); //sino, aparecerá los siguientes
            App->draw(instruction);
            App->draw(startGameText);
            App->draw(exitText);
        }

       App->display();
    }
}
