#include "Anthill.h"

int Anthill::food_count = 0;
int Anthill::stick_count = 0;


Anthill::Anthill():lvl(1), rad(start_radius) {
    food_count = start_food_limit / 2;
    stick_count = start_stick_limit / 2;
    default_count();
    max_ants = 100/*start_max_ant_count*/;
    max_sticks = start_stick_limit;
    max_food = start_food_limit;
}

void Anthill::up_lvl() {
    if (stick_count == max_sticks) {
        lvl++;
        max_ants *= 1.2;
        max_food *= 1.2;
        max_sticks *= 1.2;
        rad *= 1.2;
    }
}

void Anthill::down_lvl() {
    if (stick_count == 0) {
        lvl--;
        rad *= 0.8;
        max_ants = ants;
        max_food *= 0.8;
        max_sticks *= 0.8;
        if (food_count > max_food) food_count = max_food;
        if (stick_count > max_sticks) stick_count = max_sticks;
        /*int killed_role = 0;
        while (ants > max_ants) {
            for (auto& ant : colony) if (ant.get_role() == killed_role) { ant.set_hp(0); }
            killed_role++;
        }*/
    }
}

void Anthill::bring_res(res_type type) {
    if (type == food) food_count += rand() % 50 + 100;
    else if (type == stick) stick_count += rand() % 50 + 100;
}

void Anthill::born_baby() {
    int x, y;
    if (ants <= max_ants) {
        do {
            x = rand() % window_weidth;
            y = rand() % window_high;
        } while ((x < window_weidth / 2 - start_radius / 2) || (x > window_weidth / 2 + start_radius / 2) ||
            (y < window_high / 2 - start_radius / 2) || (y > window_high / 2 + start_radius / 2));
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
        if (food_count == 0) ant.set_hp(0);
        else if (ant.get_hp() != 0) {
            ants++;
            switch (ant.get_role()) {
            case 0:babies++; break;
            case 1:sitters++; break;
            case 2:collectors++; break;
            case 3:builders++; break;
            case 4:soldiers++; break;
            case 5:shepherds++; break;
            case 6:cleaners++; break;
            }
        }
    }
}