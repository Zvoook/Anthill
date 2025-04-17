#include "Anthill.h"

Anthill* Anthill::instance = nullptr;
int Anthill::food_count = 0;
int Anthill::stick_count = 0;

Anthill::Anthill() :lvl(1), rad(start_radius) {
    instance = this;
    shape.setRadius(rad);
    pos.x = window_width / 2 - start_radius;
    pos.y = window_height / 2 - start_radius;
    shape.setPosition(Vector2f(pos.x, pos.y));
    food_count = start_food_limit / 2;
    stick_count = (int)(start_stick_for_update * 0.75);
    default_count();
    max_ants = start_max_ant_count;
    sticks_for_upd = start_stick_for_update;
    max_food = start_food_limit;
    shape.setFillColor(Color(160, 100, 60));
}

void Anthill::up_lvl() {
    lvl++;
    stick_count /= 2;
    if (max_ants * 1.2 < max_ants_on_map) max_ants *= 1.2;
    else max_ants_on_map;
    max_food *= 1.2;
    sticks_for_upd *= 1.2;
    if (rad * 1.1 < 11 * start_radius) rad *= 1.1;
    shape.setRadius(rad);
    pos.x = window_width / 2 - rad;
    pos.y = window_height / 2 - rad;
    shape.setPosition(Vector2f(pos.x, pos.y));
}

void Anthill::down_lvl() {
    lvl--;
    rad *= 0.8;
    max_ants = ants;
    max_food *= 0.8;
    sticks_for_upd *= 0.8;
    if (food_count > max_food) food_count = max_food;
    if (stick_count > sticks_for_upd) stick_count = sticks_for_upd;
    shape.setRadius(rad);
    pos.x = window_width / 2 - rad;
    pos.y = window_height / 2 - rad;
    shape.setPosition(Vector2f(pos.x, pos.y));
}

void Anthill::born_baby() {
    int x = window_width / 2 - rad / 2 + rand() % (int)rad;
    int y = window_height / 2 - rad / 2 + rand() % (int)rad;
    colony.emplace_back(x, y);
    food_count -= food_for_born;
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

void Anthill::upd_anthill(int ticks, vector<Resource>& resources)
{
    upd_ant_stats();
    if (ticks % min_born_period == 0) {
        if ((colony.size() == 0 || colony.size() < start_max_ant_count) && (food_count > food_for_born + (4 * ants + 1))) born_baby();
        else if (food_count >= food_for_born + (ants + 1 * 2) && ants < max_ants) born_baby();
    }
    if (stick_count >= sticks_for_upd) up_lvl();
    else if (stick_count <= 0.25 * sticks_for_upd && ticks % min_downgrade_period == 0) down_lvl();
}

void Anthill::default_count()
{
    ants = soldiers = builders = cleaners = sitters = babies = shepherds = collectors = 0;
}

void Anthill::hunger() {
    int ant_count = colony.size();
    if (food_count < ant_count) for (auto& ant : colony) ant.set_hp(ant.get_hp() - hunger_damage);
    else food_count -= ant_count;
}