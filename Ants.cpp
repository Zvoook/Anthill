#pragma once
#include "Game Settings.h"
#include "Position.h"
#include "Role.h"
#include "Resource.h"

class Ant : public enable_shared_from_this<Ant> {
private:
    int hp, max_hp, life_time;
    Position pos, target;
    Vector2f velocity;
    Role* role;
    character charact;
    res_type inventory;
    CircleShape shape;
    bool has_target;
public:
    Ant(float x, float y) : role(make_shared<Baby>()), life_time(0), hp(1), velocity(0, 0), target(0, 0), has_target(false), inventory(no_res) {
        max_hp = rand() % 6 + 10;
        charact = (max_hp % 2 == 0) ? passive : agressive;
        shape.setRadius(ant_size);
        shape.setFillColor(Color(255, 182, 193));
        shape.setPosition(x, y);
    }
    void set_role(shared_ptr<Role> new_role) { role = move(new_role); }
    void set_velocity(float vx, float vy) { velocity.x = vx; velocity.y = vy; }
    void work();
    //void work() { if (role) role->work(shared_from_this()); }
    void update();
    void pick_res(Resource res);
    void drop_res();
    void kill() { hp = 0; };
    int get_max_hp() const { return max_hp; }
    bool is_alive() const { return hp; }
};
