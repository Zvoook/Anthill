#include "Anthill.h"
#include "Game Settings.h"

Anthill::Anthill() {
    lvl = 1;
    current_ants = lvl_1_place_for_ants - 9;
    current_food = lvl_1_place_for_food - 25000;
    current_materials = lvl_1_place_for_materials - 500;
    place_for_ants = lvl_1_place_for_ants;
    place_for_materials = lvl_1_place_for_materials;
    place_for_food = lvl_1_place_for_food;
    count_soldiers = lvl_1_count_soldiers;
    count_builders = lvl_1_count_builders;
    count_cleaners = lvl_1_count_cleaners;
    count_sitters = lvl_1_count_sitters;
    count_babies = lvl_1_count_babies;
    count_shepherds = lvl_1_count_shepherds;
    count_collectors = lvl_1_count_collectors;
    radius = lvl_1_radius;
}

Anthill::~Anthill() {

}

void Anthill::up_lvl() {
    if (current_materials == place_for_materials) {
        lvl++;
        place_for_ants += 10;
        place_for_food += 25000;
        place_for_materials += 500;
        radius *= 1.2;
    }
}

void Anthill::bring_material(int rank_material) {
}

void Anthill::bring_food(int rank_food) {
}

void Anthill::print_characteristics() {
    while (1) {
        cout << "Количество муравьев: " << current_ants << "/" << place_for_ants << endl;
        cout << "Количество еды: " << current_food << "/" << place_for_food << endl;
        cout << "Количество материалов: "<< current_materials << "/" << place_for_materials << endl;
        cout << "Количество солдат: " << count_soldiers << endl;
        cout << "Количество строителей: " << count_builders << endl;
        cout << "Количество уборщиков: " << count_cleaners << endl;
        cout << "Количество нянек: " << count_sitters << endl;
        cout << "Количество ребятишек: " << count_babies << endl;
        cout << "Количество пастухов: " << count_shepherds << endl;
        cout << "Количество сборщиков: " << count_collectors << endl;
    }
}
