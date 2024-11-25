#pragma once
#include "lib.h"

#ifndef MENU_H
#define MENU_H

class Menu {
public:
    Menu(RenderWindow* App) ;
    void cargarAssets(); //nos permitir� cargar todos los recursos graficos
    void run(); //para mostrar la pantalla
   
private:
    RenderWindow* App;
    bool showInstructions; //booleano que nos permitir� mostrar las instrucciones
    // Elementos gr�ficos
    Texture backgroundTex, titleTex, instructionTex;
    Sprite background, title, instruction, smallTitle;
    Font font;
    Text pressPText, startGameText, exitText;
};

#endif
