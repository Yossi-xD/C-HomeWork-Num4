#ifndef DRAGONGOTCHI_HPP
#define DRAGONGOTCHI_HPP

#include "MagicalPet.hpp"

class DragonGotchi : public MagicalPet {

    private : 
        int hunger;
        int happiness;

    public : 

    DragonGotchi() : hunger (0) , happiness(10) {} 

    void feed(int foodAmount) override {
        if (foodAmount < 0) {
            throw MagicalException("Error: Negative feed amount!") ;
            return;
        }
        if (foodAmount > 10) {
            throw MagicalException("Error: Feed amount too high for Dragon!");
            return;
        }

        hunger += foodAmount;
        if (hunger > 20) hunger = 20;

        happiness += foodAmount / 2;
        if (happiness > 50) happiness = 50;
    }

    void play() override {
        if (hunger >= 15) {
            throw MagicalException("Error: Dragon is too hungry to play!");
            return;
        }

        hunger -= 5;
        if (hunger < 0) hunger = 0;

        happiness += 3;
        if (happiness > 50) happiness = 50;
    }

    void heal() override {
        hunger -= 3;
        if (hunger < 0) hunger = 0;

        happiness += 5;
        if (happiness > 50) happiness = 50;
    }

    void train() override {
        hunger += 2;
        if (hunger > 20) hunger = 20;

        happiness -= 2;
        if (happiness < 0) happiness = 0;
    }

    void showStatus() const override {
        cout << "=== DragonGotchi Status === Hunger: " << hunger << " Happiness: " << happiness << endl;
    }

    int getHunger() const { return hunger; }
    int getHappiness() const { return happiness; }
    void setHunger(int h) { hunger = (h > 20) ? 20 : (h < 0) ? 0 : h; }
    void setHappiness(int h) { happiness = (h > 50) ? 50 : (h < 0) ? 0 : h; }

};


#endif