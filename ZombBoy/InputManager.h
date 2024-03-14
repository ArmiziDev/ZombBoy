// InputManager.h

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SFML/Window/Keyboard.hpp>

class InputManager {
public:
    enum KeyState {
        NotPressed = 0,
        Pressed = 1
    };

    void update();
    bool isKeyPressed(sf::Keyboard::Key key);

private:
    KeyState keyStates[sf::Keyboard::KeyCount]; // Array to store the state of each key
};

#endif // INPUT_MANAGER_H
