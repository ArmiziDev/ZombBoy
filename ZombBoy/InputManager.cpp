// InputManager.cpp

#include "InputManager.h"

void InputManager::update() {
    for (int i = 0; i < sf::Keyboard::KeyCount; ++i) {
        if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i))) {
            keyStates[i] = Pressed;
        }
        else {
            keyStates[i] = NotPressed;
        }
    }
}

bool InputManager::isKeyPressed(sf::Keyboard::Key key) {
    return keyStates[key] == Pressed;
}
