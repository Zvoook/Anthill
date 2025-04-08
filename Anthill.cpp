#include "Anthill.h"
#include "Game Settings.h"

Anthill::Anthill() {
    lvl = 1;
    current_ants = lvl_1_place_for_ants - 10;
    current_food = lvl_1_place_for_food - 25000;
    current_materials = lvl_1_place_for_materials - 500;
    place_for_ants = lvl_1_place_for_ants;
    place_for_materials = lvl_1_place_for_materials;
    place_for_food = lvl_1_place_for_food;
}

Anthill::~Anthill() {

}

void Anthill::up_lvl() {
    if (current_materials == place_for_materials) {
        lvl++;
        place_for_ants += 10;
        place_for_food += 25000;
        place_for_materials += 500;
    }
}

void Anthill::bring_material(int rank_material) {
}

void Anthill::bring_food(int rank_food) {
}
