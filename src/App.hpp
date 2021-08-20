//
// Created by caleb on 8/19/21.
//

#ifndef PARTICLE_APP_HPP
#define PARTICLE_APP_HPP
#include "includes.hpp"
#include "Particle.hpp"
#include <array>
#include <ctime>
class App {

private:

    sf::RenderWindow* window;

    sf::Clock clock;
    float dt;

    sf::Event event{};

    sf::Vector2i MousePos;

    std::array<Particle*, 200000> particleArray;

    void Render();
    void HandleEvents();
    void Update();
    void UpdateDT();
    void UpdateMousePosition();

public:
    App();

    ~App();

    void Run();

};


#endif //PARTICLE_APP_HPP
