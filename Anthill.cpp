#include "Anthill.h"
int Anthill::food_count = 0;
int Anthill::stick_count = 0;

Anthill::Anthill() :lvl(1), rad(start_radius) {
    food_count = start_food_limit / 2;
    stick_count = start_stick_for_update / 2;
    default_count();
    max_ants = start_max_ant_count;
    sticks_for_upd = start_stick_for_update;
    max_food = start_food_limit;
}

void Anthill::up_lvl() {
    lvl++;
    stick_count /= 2;
    max_ants *= 1.2;
    max_food *= 1.2;
    sticks_for_upd *= 1.2;
    rad *= 1.2;
}

void Anthill::down_lvl() {
    lvl--;
    rad *= 0.8;
    max_ants = ants;
    max_food *= 0.8;
    sticks_for_upd *= 0.8;
    if (food_count > max_food) food_count = max_food;
    if (stick_count > sticks_for_upd) stick_count = sticks_for_upd;
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

void Anthill::upd_ant_stats()
{
    default_count();
    for (auto& ant : colony) {
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

void Anthill::upd_anthill(int ticks)
{
    upd_ant_stats();
    if (stick_count == sticks_for_upd) up_lvl();
    else if (stick_count == 0) down_lvl();
    //if (ticks % feeding_period == 0) feeding();
    if (food_count > food_for_born && ticks % min_born_period == 0) {
        born_baby();
        food_count -= food_for_born;
    }
}
void Anthill::hunger() {
    int ant_count = colony.size();
    if (food_count < ant_count) {
        for (auto& ant : colony) {
            int new_hp = ant.get_hp() - hungry_damage;
            ant.set_hp(new_hp);
        }
    }
    else food_count -= ant_count;
}