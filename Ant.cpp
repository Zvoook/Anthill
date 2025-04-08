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
    //if (role_id==0 || role_id == 1) return;
    float x = 0, y = 0;
    if (has_target) { x = target.x * ant_speed; y = target.y * ant_speed; }
    else if (age % velocity_changing_period == 0) { x = randomise_velocity() * ant_speed; y = randomise_velocity() * ant_speed; };

    if (pos.x + x<0 || pos.x + x > window_weidth) x = -x;
    if (pos.y + y<0 || pos.y + y > window_high) y = y;

    pos.x += x;
    pos.y += y;
    shape.setPosition(pos.x, pos.y);
}

bool Ant::pick(Resource& res) {
    if (!res.is_visible()) return 0;
    if ((res.get_type() == food && role_id == 2) || (res.get_type() == stick && role_id == 3) || ((res.get_type() == body || res.get_type() == trash) && role_id == 6)) return 1;
}

void Ant::drop() 
{
    int res_count = 0;
    if (inventory != no_res && pos.in_anthill()) {
        res_count += 1;
        set_inventory(no_res);
    }
}

void Ant::upd_color()
{
    switch (role_id) {
    case 0: { shape.setFillColor(Color::White); return; }
    case 1: { shape.setFillColor(Color(255,102,178)); return; }
    case 2: { shape.setFillColor(Color(255,128,0)); return; }
    case 3: { shape.setFillColor(Color::Yellow); return; }
    case 4: { shape.setFillColor(Color::Black); return; }
    case 5: { shape.setFillColor(Color(0,0,204)); return; }
    case 6: { shape.setFillColor(Color(102,51,0)); return; }
    }
}

void Ant::set_target_on_res(vector<Resource>& res)
{
    if (has_target) return;
    int n = 0;
    do {
        n = rand() % res[0].get_count();
    } while (!pick(res[n]));
    target = res[n].get_posit();
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