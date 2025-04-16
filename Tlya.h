#pragma once
#include "Game Settings.h"
#include "Position.h"
// ����� ��� - ������� ������
class Aphid {
private:
    int hp;
    Position pos;
    Vector2f velocity;
    CircleShape shape;
    bool visible;
    int age;
    int honey_timer;

public:
    Aphid(float x, float y) : pos(x, y), age(0), hp(100), velocity(0, 0),
        honey_timer(0), visible(true) {
        shape.setRadius(aphid_size);
        shape.setFillColor(Color(153, 153, 255));
        shape.setPosition(x, y);
        shape.setPointCount(8);
    }
    ~Aphid() = default;

    void move();
    void set_velocity(float vx, float vy) { velocity.x = vx; velocity.y = vy; }
    int produce_honey();
    void update();
    bool is_dead() const { return hp <= 0; }
    void take_damage(int damage) { hp -= damage; if (hp < 0) hp = 0; }
    void set_invisible() { visible = false; }
    bool is_visible() const { return visible; }
    Position get_pos() const { return pos; }
    const CircleShape& get_shape() const { return shape; }
    int get_hp() const { return hp; }
    int get_age() const { return age; }
};
void create_aphid_cluster(vector<Aphid>& aphids, float x, float y, int count);

float randomise_velocity_aphid();