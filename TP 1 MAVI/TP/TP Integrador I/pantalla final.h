#pragma once
#include "lib.h"

#ifndef PANTALLAFINAL_H
#define PANTALLAFINAL_H

class PantallaFinal {
public:
    PantallaFinal(); //constructor por default
    PantallaFinal(RenderWindow* App, int score); //constructor que incluye el puntaje
    void cargarAssets(); //cargamos los recursos
    void run(); //mostramos la pantalla final

private:
    RenderWindow* App;
    Texture backgroundTexture, gameOverTexture; //texturas que necesitaremos
    Sprite background, gameOver; //sprites a los que colocarle las texturas
    Font font; //fuente que queremos usar para escribir en la ventana
    Text scoreText, exitText; //tipos de texto que necesitamos
    int score; //puntaje final
};

#endif
