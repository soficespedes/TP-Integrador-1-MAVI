#include"lib.h"
#pragma once
#include "demon.h"

Demon::Demon(const string& texturePath) {
    demonTex.loadFromFile(texturePath);
    demonSprite.setTexture(demonTex);
    demonSprite.setPosition(rand() % 700, rand() % 500); //configuramos la posición aleatoria inicial
    demonSprite.setScale(0.7f, 0.7f);
}
void Demon::draw(RenderWindow& App) {
    App.draw(demonSprite);
}
bool Demon::isHit(const Vector2f& point) {
    //verificamos si el punto (posición del clic) está dentro de los límites del sprite
    return demonSprite.getGlobalBounds().contains(point);
}

void Demon::teleport() {
    demonSprite.setPosition(rand() % 700, rand() % 500); //colocamos la nueva posición aleatoria
}


