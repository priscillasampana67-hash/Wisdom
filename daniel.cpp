#include <iostream>
#include <string>
#include <vector>

// Base class for everything in the game world
class GameObject {
protected:
    std::string name;
    float posX, posY, posZ;

public:
    GameObject(std::string n, float x, float y, float z) 
        : name(n), posX(x), posY(y), posZ(z) {}
    
    // Pure virtual function demonstrating polymorphism
    virtual void update() = 0; 
    virtual ~GameObject() = default;
};

// Derived class for the player character
class Player : public GameObject {
private:
    int health;
    int armor;

public:
    Player(std::string n, float x, float y, float z) 
        : GameObject(n, x, y, z), health(100), armor(50) {}

    void update() override {
        // Here we would eventually process keyboard/controller input
        std::cout << "Updating player: " << name << " - processing input." << std::endl;
    }
};

// Derived class for vehicles
class Vehicle : public GameObject {
private:
    float speed;
    bool isEngineOn;

public:
    Vehicle(std::string n, float x, float y, float z) 
        : GameObject(n, x, y, z), speed(0.0f), isEngineOn(false) {}

    void update() override {
        // Here we would apply driving physics and tire friction
        std::cout << "Updating vehicle: " << name << " - applying physics." << std::endl;
    }
};

int main() {
    // Using pointers and dynamic memory allocation to manage the game world
    std::vector<GameObject*> gameWorld;
    
    // Spawning entities into the world
    gameWorld.push_back(new Player("CJ", 0.0f, 0.0f, 0.0f));
    gameWorld.push_back(new Vehicle("Banshee", 10.0f, 0.0f, 5.0f));

    // Simulated Game Loop
    std::cout << "--- Game Loop Started ---" << std::endl;
    for (int frame = 0; frame < 3; ++frame) {
        std::cout << "Frame " << frame << ":" << std::endl;
        for (GameObject* obj : gameWorld) {
            obj->update();
        }
    }

    // Cleaning up dynamic memory to prevent memory leaks
    for (GameObject* obj : gameWorld) {
        delete obj;
    }
    gameWorld.clear();

    return 0;
}