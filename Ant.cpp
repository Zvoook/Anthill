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
    if (has_target) {
        float dx = target.x - pos.x;
        float dy = target.y - pos.y;
        float dist = sqrt(dx * dx + dy * dy);
        /*if (dist > 1.5f) {*/
            velocity.x = (dx / dist) * ant_speed;
            velocity.y = (dy / dist) * ant_speed;
        //}
        /*else {
            velocity.x = 0;
            velocity.y = 0;
        }*/
        pos.x += velocity.x;
        pos.y += velocity.y;
    }
    else {
        if (age % velocity_changing_period == 0)  set_velocity(randomise_velocity() * ant_speed, randomise_velocity() * ant_speed);
        if (pos.x + velocity.x < 0 || pos.x + velocity.x > window_weidth) velocity.x = -velocity.x;
        if (pos.y + velocity.y < 0 || pos.y + velocity.y > window_high) velocity.y = -velocity.y;
        pos.x += velocity.x;
        pos.y += velocity.y;
    }

    shape.setPosition(pos.x, pos.y);
}

bool Ant::pick(Resource& res) {
    if (!res.is_visible() /*|| role_id!=2 || role_id!=3*/) return 0;
    if ((res.get_type() == food && role_id == 3) || (res.get_type() == stick && role_id == 2) || ((res.get_type() == body || res.get_type() == trash) && role_id == 6)) return 1;
}

void Ant::upd_color()
{
    switch (role_id) {
    case 0: { shape.setFillColor(Color::White); return; }
    case 1: { shape.setFillColor(Color(255, 102, 178)); return; }
    case 2: { shape.setFillColor(Color(255, 128, 0)); return; }
    case 3: { shape.setFillColor(Color::Yellow); return; }
    case 4: { shape.setFillColor(Color::Black); return; }
    case 5: { shape.setFillColor(Color(0, 0, 204)); return; }
    case 6: { shape.setFillColor(Color(102, 51, 0)); return; }
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
