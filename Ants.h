#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <memory>
using namespace std;
using namespace sf;

#define antsize 10
#define ant_speed 2
#define life_stages 5
#define stage_time_per_ticks 20
#define probability_of_small_resources 70
#define probability_of_medium_resources 20

enum roles { baby, sitter, collector, builder, solder, sheppert, cleaner };
enum Sides {up, down, left, right};
enum character { passive, agressive };
enum info_type { food_info, stick_info, enemy };
enum res_type { no_res, food, stick, body, trash };
enum res_size {small, medium, big};

class Position {
private:
    float x, y;
    double hipotenuse(int a, int b) { return sqrt(pow(a, 2) + pow(b, 2)); }
public:
    Position(int a=0, int b=0) :x(a), y(b) {};
    float distance(const Position& last) { hipotenuse(x - last.x, y - last.y); }
    bool operator==(const Position& last) { return x == last.x && y == last.y; }
    void set_pos(float a, float b) { x = a; y = b; }
    float get_x() { return x; }
    float get_y() { return y; }
};

class Resource {
private:
    res_type type;
    int size;
    Position pos;
    int ants_for_collecting;
    bool collected;
public:
    Resource(res_type t = no_res, int a = 1, res_size s = small, Position p = Position()) : size(s), collected(false), type(t), pos(p) {ants_for_collecting == (size + 1) * 2;};
    void set_posit(float a, float b) { pos.set_pos(a,b); }
    void decrease_size() { if (size > 0) size--; }
    void collect() { collected = true; }
    res_type get_type() const { return type; }
    int get_size() const { return size; }
    Position get_posit() const { return pos; }
    bool is_collect() const { return collected; }
};

void create_cluster(vector<Resource>& resources, float x, float y, res_type type);

class Ant;
class Baby;
class Sitter;
class Solder;
class Collector;
class Sheppert;
class Cleaner;

class Role {
public:
    virtual ~Role() = default;
    virtual void role_up(shared_ptr<Ant> ant) = 0;
    virtual void work(shared_ptr<Ant> ant) = 0;
};

class Baby : public Role {
    Baby() = default;
    void work(shared_ptr<Ant> ant) override {};
    void role_up(shared_ptr<Ant> ant) override { ant->set_role(static_pointer_cast<Role>(make_shared<Sitter>())); };
};

class Ant : public enable_shared_from_this<Ant> {
private:
    int hp, max_hp, life_time;
    Position pos;
    Vector2f velocity;
    shared_ptr<Role> role;
    character charact;
    res_type res;
    CircleShape shape;
public:
    Ant(float x, float y) : role(make_shared<Baby>()), life_time(0), hp(1), velocity(0, 0) {
        max_hp = rand() % 6 + 10;
        charact = (max_hp % 2 == 0) ? passive : agressive;
        shape.setRadius(antsize);
        shape.setFillColor(Color(255, 182, 193));
        shape.setPosition(x, y);
    }
    void set_role(shared_ptr<Role> new_role) { role = move(new_role); }
    void set_velocity(float vx, float vy) { velocity.x = vx; velocity.y = vy; }
    void work() { if (role) role->work(shared_from_this()); }
    void update();
    void kill() { hp = 0; };
    int get_max_hp() const { return max_hp; }
};

class Sitter : public Role {
    Sitter() = default;
    void work(shared_ptr<Ant> ant) override {};
    void role_up(shared_ptr<Ant> ant) override;
};

class Collector : public Role {
    Collector() = default;
    void work(shared_ptr<Ant> ant) override;
    void role_up(shared_ptr<Ant> ant) override;
};

class Builder : public Role {
    Builder() = default;
    void work(shared_ptr<Ant> ant) override;
    void role_up(shared_ptr<Ant> ant) override;
};

class Solder : public Role {
    Solder() = default;
    void work(shared_ptr<Ant> ant) override;
    void role_up(shared_ptr<Ant> ant) override;
};

class Sheppert : public Role {
    Sheppert() = default;
    void work(shared_ptr<Ant> ant) override;
    void role_up(shared_ptr<Ant> ant) override;
};

class Cleaner : public Role {
    Cleaner() = default;
    void work(shared_ptr<Ant> ant) override;
    void role_up(shared_ptr<Ant> ant) override;
};
