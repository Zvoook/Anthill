#include "Anthill.h"

Anthill::Anthill() {
    lvl = 1;
    place_for_ants = 10;
    place_for_food = 50;
    place_for_materials = 50;
    current_ants = 5;
    current_food = 10;
    current_materials = 10;
}

Anthill::~Anthill() {

}

void Anthill::up_lvl() {
    if (place_for_materials == current_materials) {
        lvl++;
        place_for_ants += 5;
        place_for_food += 10;
        place_for_materials += 20;
    }
}

void Anthill::bring_material(int rank_material) {
}

void Anthill::bring_food(int rank_food) {
}