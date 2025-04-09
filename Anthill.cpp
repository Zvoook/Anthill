#include "Anthill.h"

Anthill::Anthill():lvl(1), rad(start_hill_size) {
    food_count = food_limit - 25000;
    stick_count = stick_limit - 500;
    default_count();
    current_ants = ants - 9;
    place_for_ants = ants;
    place_for_materials = stick_limit;
    /*place_for_food = food_limit;
    count_soldiers = count_builders = count_cleaners = count_sitters =  count_babies   count_shepherds = shepherds;
    count_collectors = collectors;*/
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

void Anthill::bring_res(res_type type) {
    if (type == food) food_count += rand() % 50 + 100;
    else if (type == stick) stick_count += rand() % 50 + 100;
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

void Anthill::drop(Ant& ant)
{
    if (ant.get_inventory() != no_res && ant.check_pos()) {
        if (ant.get_inventory() == food) food_count ++;
        if (ant.get_inventory() == stick) stick_count++;
        ant.set_inventory(no_res);
    }
}

void Anthill::upd_ant_stats()
{
    default_count();
    for (auto& ant : colony) {
        switch (ant.get_role()) {
        case 0:count_babies++; break;
        case 1:count_sitters++; break;
        case 2:count_collectors++; break;
        case 3:count_builders++; break;
        case 4:count_soldiers++; break;
        case 5:count_shepherds++; break;
        case 6:count_cleaners++; break;
        }
    }
}

//void Anthill::upd_stats()
//{
//    for (auto& ant : colony) {
//        if (ant.get_role()==1) 
//    }
//}