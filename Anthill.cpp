#include "Anthill.h"

Anthill::Anthill() {
    this->lvl = 1;
    this->place_for_ants = 10;
    this->place_for_food = 50;
    this->place_for_materials = 50;
}

Anthill::~Anthill() {

}

void Anthill::up_lvl() {
    if (this->place_for_materials == 50 + lvl * 20) {
        this->lvl++;
        this->place_for_ants += 5;
        this->place_for_food += 10;
        this->place_for_materials += 20;
    }
}
