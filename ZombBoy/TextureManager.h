#pragma once

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>

class TextureManager {
public:
    sf::Texture& loadTexture(const std::string& filepath) {
        // Try to find the texture by its filepath
        auto it = textures.find(filepath);
        if (it != textures.end()) {
            return it->second;
        }

        

        // Load the texture if it's not found
        sf::Texture& texture = textures[filepath];
        if (!texture.loadFromFile(filepath)) {
            throw std::runtime_error("Failed to load texture: " + filepath);
        }

        return texture;
    }

private:
    std::unordered_map<std::string, sf::Texture> textures;
};
