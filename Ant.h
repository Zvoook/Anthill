#pragma once
#include "Game Settings.h"
#include "Position.h"
#include "Role.h"
#include "Resource.h"
//Role* roles;

class Ant {
private:
    int hp, max_hp, life_time;
    Position pos, target;
    Vector2f velocity;
    Role* role;
    int role_id;
    CircleShape shape;
    bool has_target;
    res_type inventory;
public:
    Ant(float x=0, float y=0) : /*role(null_ptr), */role_id(0), life_time(0), hp(1), velocity(0, 0), target(0, 0), has_target(false), inventory(no_res) {
        max_hp = rand() % 6 + 10;
        shape.setRadius(ant_size);
        shape.setFillColor(Color(255, 182, 193));
        shape.setPosition(x, y);
    }
    //void create_colony(vector<Ant&> col, int c) {
    //    for (int i = 0; i <= c; ++i) {
    //        /*float x = rand() % (window_weidth - 2 * dist_btw_res) + dist_btw_res;
    //        float y = rand() % (window_high - 2 * dist_btw_res) + dist_btw_res;*/
    //        Ant& ant;
    //        col.push_back(ant);
    //    }
    //}
    //~Ant() { delete role; }
    //void set_role(int id) { role = roles[id]; }
    void set_velocity(float vx, float vy) { velocity.x = vx; velocity.y = vy; }
    void set_hp(int n) { hp = n; }
    void upd_role(Role* r) { role_id++; role = r; }
    void update();
    //void pick_res(Resource& res);
    void drop_res();

    void kill() { hp = 0; }
    //void work() { role->work(*this); }

    int get_hp() const { return hp; }
    int get_max_hp() const { return max_hp; }
    int get_lifetime() const { return life_time; }
    int get_role() const { return role_id; }
};

float randomise_velocity();