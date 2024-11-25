#include "lib.h"
#include "menu.h"
#include "juego.h"
int main() {
    //creamos la ventana principal
    RenderWindow App(VideoMode(900, 700), "Not Today!");

        //llamamos a los métodos de la clase menu configurada anteriormente
        Menu menu(&App);
        menu.cargarAssets();
        menu.run();

        //llamamos a los métodos de la clase juego configurada anteriormente
        Juego juego(&App);
        juego.cargarAssets();
        juego.run();
    return 0;
}
