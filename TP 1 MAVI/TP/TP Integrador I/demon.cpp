#include"lib.h"
#pragma once
#include "demon.h"

Demon::Demon(const string& texturePath) {
    demonTex.loadFromFile(texturePath);
    demonSprite.setTexture(demonTex);
    demonSprite.setPosition(rand() % 700, rand() % 500); //configuramos la posici�n aleatoria inicial
    demonSprite.setScale(0.7f, 0.7f);
}
void Demon::draw(RenderWindow& App) {
    App.draw(demonSprite);
}
bool Demon::isHit(const Vector2f& point) {
    //verificamos si el punto (posici�n del clic) est� dentro de los l�mites del sprite
    return demonSprite.getGlobalBounds().contains(point);
}

void Demon::teleport() {
    demonSprite.setPosition(rand() % 700, rand() % 500); //colocamos la nueva posici�n aleatoria
}


