#pragma once
#include "lib.h"

#ifndef ANGEL_H
#define ANGEL_H

class Angel {
public:
    Angel();
    void cargarAssets(); //para cargar la textura
    void draw(RenderWindow& App); //para dibujar en la ventana
    bool isHit(Vector2f mousePos); //para verificar si el �ngel fue disparado
    void spawn(); //para hacer que el �ngel aparezca en una posici�n aleatoria

private:
    Texture angelTex; //textura
    Sprite angelSprite; //sprite
    bool isVisible;  //el �ngel es visible en pantalla?
};

#endif