#include"lib.h"
#pragma once
#include "crosshair.h"

Crosshair::Crosshair() : vidas(3) {} //cantidad de vidas

void Crosshair::cargarAssets() {
    //cargamos la textura del crosshair, ajustamos el tamaño
    crosshairTex.loadFromFile("../../Assets/crosshair.png");
    crosshairSprite.setTexture(crosshairTex);
    crosshairSprite.setScale(0.3f, 0.3f); 
}

void Crosshair::update(Vector2f mousePosition) {
    //ajustamos la posición para centrar el crosshair en el puntero
    FloatRect bounds = crosshairSprite.getLocalBounds();
    crosshairSprite.setPosition(
        mousePosition.x - bounds.width * crosshairSprite.getScale().x / 2.0f,
        mousePosition.y - bounds.height * crosshairSprite.getScale().y / 2.0f
    );
}

//dibujamos el sprite en ventana
void Crosshair::draw(RenderWindow& App) {
    App.draw(crosshairSprite);
}
//si las vidas son mayores a 0, reduceLife sigue inicializando
void Crosshair::reduceLife() {
    if (vidas > 0) {
        vidas--;
    }
}
//retorna la cantidad de vidas que tiene el jugador
int Crosshair::getLives() const {
    return vidas;
}
