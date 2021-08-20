//
// Created by caleb on 8/19/21.
//

#include "App.hpp"

App::App() : dt{0.0f}{
    window = new sf::RenderWindow(SCREEN, "Particle");
    window->setVerticalSyncEnabled(true);
    UpdateMousePosition();
    srand(time(NULL));

    for(auto & i : particleArray)
         i = new Particle(&MousePos, &dt);


}

App::~App() {
    delete window;
}

void App::Update() {
    while(window->isOpen()){
        UpdateDT();
        UpdateMousePosition();
       // for(auto & i : particleArray)
        //    i->updateVertex();

        HandleEvents();


        Render();
    }
}

void App::Render() {
    window->clear();
    for(auto & i : particleArray)
        window->draw(i->GetVertex(), 1, sf::Points);
    window->display();
}

void App::HandleEvents() {
    while(window->pollEvent(event)){
        if(event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            window->close();
        else if(event.type == sf::Event::MouseButtonPressed){
            for(auto & i : particleArray){
                i->SetMaxSpeed(1250);
            }
        }
        else if(event.type == sf::Event::MouseButtonReleased){
            for(auto & i : particleArray){
                i->SetMaxSpeed(10000);
            }
        }
    }

}



void App::UpdateDT() {
    dt = clock.restart().asSeconds();
}

void App::Run() {
    std::thread thr(&App::ThreadExperiment, this);

    Update();
    thr.join();

}

void App::UpdateMousePosition() {
    MousePos = sf::Mouse::getPosition(*window);
}

void App::ThreadExperiment() {
    while(window->isOpen()){
        for(auto & i : particleArray)
            i->updateVertex();
    }
}
