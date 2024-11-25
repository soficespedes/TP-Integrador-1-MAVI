#pragma once
#include "lib.h"

#ifndef CROSSHAIR_H
#define CROSSHAIR_H

class Crosshair {
public:
    Crosshair();
    void cargarAssets(); //para cargar la textura
    void update(Vector2f mousePosition); //para actualizar posición
    void draw(RenderWindow& App); //para dibujarlo en pantalla
    void reduceLife();  //para reducir una vida
    int getLives() const;  //para obtener las vidas restantes

private:
    Texture crosshairTex; //textura
    Sprite crosshairSprite; //sprite
    int vidas; //vidas
};

#endif
