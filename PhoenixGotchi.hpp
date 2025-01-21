#ifndef PHEONIXGOTCHI_HPP
#define PHEONIXGOTCHI_HPP

#include "MagicalPet.hpp"

    class PhoenixGotchi : public MagicalPet {

        private : 
        int hunger ; 
        int happiness ;

        public : 

        PhoenixGotchi() : hunger(5) , happiness(5) {}

        void feed(int foodAmount) override {
        if (foodAmount < 0) {
            throw MagicalException("Error: Negative feed amount!");
            return;
        }
        if (foodAmount > 10) {
            throw MagicalException("Error: Feed amount too high for Pheonix !");
            return;
        }

        hunger += foodAmount;
        if (hunger > 30) hunger = 30;

        happiness += foodAmount / 3;
        if (happiness > 40) happiness = 40;
    }

    void play() override {
        if (hunger >= 20) {
            throw MagicalException("Error: Pheonix is too hungry to play!");
            return;
        }
        
        hunger -= 3;
        if (hunger < 0) hunger = 0;

        happiness += 5;
        if (happiness > 40) happiness = 40;
    }

    void heal() override {
        hunger -= 2;
        if (hunger < 0) hunger = 0;

        happiness += 8;
        if (happiness > 40) happiness = 40;
    }

    void train() override {
        hunger += 4;
        if (hunger > 30) hunger = 30;

        happiness -= 1;
        if (happiness < 0) happiness = 0;
    }

    void showStatus() const override {
        cout << "=== PheonixGotchi Status === Hunger: " << hunger << " Happiness: " << happiness << endl;
    }

    int getHunger() const { return hunger; }
    int getHappiness() const { return happiness; }
    void setHunger(int h) { hunger = (h > 30) ? 30 : (h < 0) ? 0 : h; }
    void setHappiness(int h) { happiness = (h > 40) ? 40 : (h < 0) ? 0 : h; }

    };

#endif