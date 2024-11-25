#pragma once
#include "lib.h"

#ifndef DEMON_H
#define DEMON_H

class Demon {
public:
    Demon(const string& texturePath); //para cargar la textura
    void draw(RenderWindow& App); //para dibujar en pantalla
    bool isHit(const Vector2f& point); //para verificar si el demonio fue golpeado
    void teleport(); //para teletransportar el sprite
 
private:
    Texture demonTex; //textura
    Sprite demonSprite; //sprite
};

#endif