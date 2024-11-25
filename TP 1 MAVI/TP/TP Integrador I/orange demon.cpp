#include "orange demon.h"
#include "lib.h"
OrangeDemon::OrangeDemon(const std::string& texturePath)
    : Demon(texturePath), timeVisible(0.0f), maxTimeVisible(1.0f) {
}

void OrangeDemon::update(float deltaTime) {
    timeVisible += deltaTime; // Aumentar el tiempo que ha estado visible
}

bool OrangeDemon::shouldDisappear() const {
    return timeVisible >= maxTimeVisible; // Desaparece si excede el tiempo máximo
}

void OrangeDemon::resetVisibilityTimer() {
    timeVisible = 0.0f; // Reinicia el temporizador de visibilidad
}
