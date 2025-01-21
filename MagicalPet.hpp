#ifndef MAGICALPET_HPP
#define MAGICALPET_HPP

#include <iostream>
using namespace std;

class MagicalPet {

    public :


    virtual void feed(int foodAmount) = 0;
    virtual void play() = 0;
    virtual void heal() = 0;
    virtual void train() = 0;
    virtual void showStatus() const = 0;

};


#endif