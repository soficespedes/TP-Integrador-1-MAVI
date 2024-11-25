#pragma once
#include "demon.h"

class OrangeDemon : public Demon {
public:
    OrangeDemon(const string& texturePath);
    void update(float deltaTime);       // Actualizar el tiempo en pantalla
    bool shouldDisappear() const;       // Verificar si debe desaparecer
    void resetVisibilityTimer();        // Reiniciar el temporizador
private:
    float timeVisible;                  // Tiempo que ha estado visible
    float maxTimeVisible;               // Tiempo máximo antes de desaparecer
};
