#include "Anthill.h"

Anthill::Anthill():lvl(1), rad(start_hill_size) {
    current_ants = start_ant_count - 9;
    food_count = lvl_1_place_for_food - 25000;
    stick_count = lvl_1_place_for_materials - 500;
    place_for_ants = start_ant_count;
    place_for_materials = lvl_1_place_for_materials;
    place_for_food = lvl_1_place_for_food;
    count_soldiers = lvl_1_count_soldiers;
    count_builders = lvl_1_count_builders;
    count_cleaners = lvl_1_count_cleaners;
    count_sitters = lvl_1_count_sitters;
    count_babies = lvl_1_count_babies;
    count_shepherds = lvl_1_count_shepherds;
    count_collectors = lvl_1_count_collectors;
}

void Anthill::up_lvl() {
    if (stick_count == place_for_materials) {
        lvl++;
        place_for_ants += 10;
        place_for_food += 25000;
        place_for_materials += 500;
        rad *= 1.2;
    }
}

void Anthill::down_lvl() { //муравьи из колонии должны помереть
    if (stick_count == 0) {
        lvl--;
        place_for_ants -= 10;
        current_ants -= 10;
        place_for_food -= 25000;
        food_count -= 25000 + rand() % 5000;
        place_for_materials -= 500;
        rad *= 0.8;
        //colony.erase(colony.begin(), colony.begin() + 10);
    }
}

void Anthill::feeding() { //потребление еды муравьями
    food_count -= current_ants;
}

void Anthill::bring_res(res_type type) {

}

void Anthill::born_baby() {
    int x, y;
    if (current_ants != place_for_ants) {
        do {
            x = rand() % window_weidth;
            y = rand() % window_high;
        } while ((x < window_weidth / 2 - start_hill_size / 2) ||
            (x > window_weidth / 2 + start_hill_size / 2) ||
            (y < window_high / 2 - start_hill_size / 2) ||
            (y > window_high / 2 + start_hill_size / 2));
        colony.emplace_back(x, y);
    }
}