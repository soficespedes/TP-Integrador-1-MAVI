#pragma once
#include "lib.h"
#include "crosshair.h"
#include "demon.h"
#include "angel.h"
#include "pantalla final.h"
#include "orange demon.h"
#ifndef JUEGO_H
#define JUEGO_H

class Juego {
public:
    Juego(RenderWindow* App);
    void cargarAssets(); //para cargar todas las texturas y recursos que necesitaremos en nuestra pantalla de juego
    void run(); //para ejecutar el bucle principal del juego
  
private:
    RenderWindow* App;
    Texture backgroundTex; //textura del fondo
    Sprite background; //sprite del fondo
    Font font; //para cargar la fuente que queremos utilizar
    Text exitText, lifeText, scoreText; //textos que escribiremos
    int score = 0;  //puntuación inicial

    Crosshair crosshair;   //instancia de la clase Crosshair
    PantallaFinal pantallafinal; //instancia de la pantalla final

    Angel angel; //instancia de la clase Angel
    Clock angelClock; //temporizador para la aparición del ángel
    float angelAppearDelay = 1.0f; //intervalo en segundos entre apariciones de nuevos ángeles
    int angelesDisparados = 0; //cantidad de angeles disparados

    Demon* currentDemon = nullptr; //puntero al demonio actual 

    OrangeDemon* orangeDemon = nullptr; //puntero al demonio naranja
    Clock orangeDemonClock; //temporizador para la aparición del demonio naranja
    float orangeDemonAppearDelay = 5.0f; //tiempo entre apariciones en segundos
    bool orangeDemonActive = false; //nos indica si el demonio está activo
};

#endif
