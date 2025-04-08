#include "Ant.h"
void Ant::upd_role() {
    switch (role_id) {
    case 0: { role = roles[role_id++]; upd_color(); return; }
    case 1: {
        bool n = rand() % 2;
        if (n == false) { role = roles[role_id++]; }
        else {
            role_id = 3;
            role = roles[role_id];
        }
        upd_color();
        return;
    }
    case 2:case 3: {
        if (hp > max_hp / 2) {
            role_id = 4;
            role = roles[role_id];
        }
        else {
            role_id = 5;
            role = roles[role_id];
        }
        upd_color();
        return;
    }
    case 4:case 5: {
        role_id = 6;
        role = roles[role_id];
        upd_color();
        return;
    }
    case 6: {
        role_id = -1;
        hp = 0;
        visible = 0;
        upd_color();
        return;
    }
    }
}

void Ant::move() {
    if (age % velocity_change_period == 0) set_velocity(randomise_velocity() * ant_speed, randomise_velocity() * ant_speed);
    if (pos.x + velocity.x<0 || pos.x + velocity.x > window_weidth) velocity.x = -velocity.x;
    if (pos.y + velocity.y<0 || pos.y + velocity.y > window_high) velocity.y = -velocity.y;
    pos.x += velocity.x;
    pos.y += velocity.y;
    shape.setPosition(pos.x, pos.y);
}

bool Ant::pick(Resource& res) {
    if (!res.is_visible()) return 0;
    if ((res.get_type() == food && role == new Collector) || (res.get_type() == stick && role == new Builder) || ((res.get_type() == body || res.get_type() == trash) && role != new Cleaner)) return 1;
    //We should update ant's target after this
}

void Ant::drop() 
{
    int res_count = 0;
    if (inventory != no_res && pos.in_anthill()) {
        res_count += 1;
        set_inventory(no_res);
    }
}

// void Ant::upd_color()
// {
//     switch (role_id) {
//     case 0: { shape.setFillColor(Color::Red); return; }
//     case 1: { shape.setFillColor(Color::Yellow); return; }
//     case 2: { shape.setFillColor(Color::Blue); return; }
//     case 3: { shape.setFillColor(Color::Magenta); return; }
//     case 4: { shape.setFillColor(Color::Black); return; }
//     case 5: { shape.setFillColor(Color::White); return; }
//     case 6: { shape.setFillColor(Color::Cyan); return; }
//     }
// }

float randomise_velocity()
{
    int n = rand() % 3;
    switch (n) {
    case 0: return -1.0f;
    case 1: return 0.0f;
    case 2: return 1.0f;
    }
}