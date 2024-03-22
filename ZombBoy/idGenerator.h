#pragma once

class IDGenerator {
public:
    static IDGenerator& getInstance() {
        static IDGenerator instance;
        return instance;
    }

    unsigned int getNextID() {
        return currentID++;
    }

private:
    IDGenerator() : currentID(1) {}
    unsigned int currentID;

    // Prevent copying and assignment
    IDGenerator(const IDGenerator&) = delete;
    IDGenerator& operator=(const IDGenerator&) = delete;
};