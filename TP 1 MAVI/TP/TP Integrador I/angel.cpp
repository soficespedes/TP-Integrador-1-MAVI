#include"lib.h"
#pragma once
#include "angel.h"

Angel::Angel() : isVisible(false) {}
void Angel::cargarAssets() {
    //cargamos la textura  del angel, le creamos un sprite y posicionamos
    angelTex.loadFromFile("../../Assets/angel.png");
    angelSprite.setTexture(angelTex);
    angelSprite.setPosition(rand() % 800, rand() % 600); //posición aleatoria inicial
    angelSprite.setScale(0.7f, 0.7f);
}
void Angel::draw(RenderWindow& App) {
    if (isVisible) {
        App.draw(angelSprite);
    }
}
bool Angel::isHit(Vector2f mousePos) {
    if (isVisible && angelSprite.getGlobalBounds().contains(mousePos)) {
        isVisible = false;  //el ángel fue disparado
        return true;
    }
    return false;
}

void Angel::spawn() {
    isVisible = true;
    angelSprite.setPosition(rand() % 800, rand() % 600); //nueva posición aleatoria
}
