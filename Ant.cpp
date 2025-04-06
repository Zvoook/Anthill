#include "Ant.h"
void Ant::upd_role() {
    switch (role_id) {
    case 0: { role = roles[role_id++]; return; }
    case 1: {
        bool n = rand() % 2;
        if (n == false) { role = roles[role_id++]; }
        else {
            role_id = 3;
            role = roles[role_id];
        }
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
        return;
    }
    case 4:case 5: {
        role_id = 6;
        role = roles[role_id];
        return;
    }
    case 6: {
        role_id = -1;
        hp = 0;
        visible = 0;
        return;
    }
    }
}

void Ant::move() {
    if (age%10==0) set_velocity(randomise_velocity() * ant_speed, randomise_velocity() * ant_speed); //randomising velocity
    pos.set_pos(pos.get_x() + velocity.x, pos.get_y() + velocity.y); //update ant position
    shape.setPosition(pos.get_x(), pos.get_y());
}

void Ant::pick_res(Resource& res) {
    if (!res.is_visible()) return;
    else if (res.get_type() == food && role != new Collector) return;
    else if (res.get_type() == stick && role != new Builder) return;
    else if ((res.get_type() == body || res.get_type() == trash) && role != new Cleaner) return;
    res.set_invisible();
    //We should update ant's target after this
}

void Ant::drop_res() 
{

}

void Ant::set_color()
{
    switch (role_id) {
    case 0: { shape.setFillColor(Color::Red); return; }
    case 1: { shape.setFillColor(Color::Yellow); return; }
    case 2: { shape.setFillColor(Color::Blue); return; }
    case 3: { shape.setFillColor(Color::Magenta); return; }
    case 4: { shape.setFillColor(Color::Black); return; }
    case 5: { shape.setFillColor(Color::White); return; }
    case 6: { shape.setFillColor(Color::Cyan); return; }
    }
}

float randomise_velocity()
{
    int n = rand() % 3;
    switch (n) {
    case 0: return -1.0f;
    case 1: return 0.0f;
    case 2: return 1.0f;
    }
}