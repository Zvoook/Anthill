//#pragma once
//#include "Game Settings.h"
//#include "Position.h"
//#include "Role.h"
//#include "Resource.h"
//
//class Ant {
//private:
//    int hp, max_hp, life_time;
//    Position pos, target;
//    Vector2f velocity;
//    //Role* role;
//    res_type inventory;
//    CircleShape shape;
//    bool has_target;
//public:
//    Ant(float x, float y) : life_time(0), hp(1), velocity(0, 0), target(0, 0), has_target(false), inventory(no_res) {
//        //role = new Baby();
//        max_hp = rand() % 6 + 10;
//        shape.setRadius(ant_size);
//        shape.setFillColor(Color(255, 182, 193));
//        shape.setPosition(x, y);
//    }
//    //~Ant() { delete role; }
//    //void set_role(Role* new_role) { role = new_role; }
//    void set_velocity(float vx, float vy) { velocity.x = vx; velocity.y = vy; }
//    void set_hp(int n) { hp = n; }
//    void update();
//    //void pick_res(Resource& res);
//    void drop_res();
//
//    void kill() { hp = 0; }
//    //void work() { role->work(*this); }
//
//    int get_hp() const { return hp; }
//    int get_max_hp() const { return max_hp; }
//};
