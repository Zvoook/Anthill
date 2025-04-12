#include "Enemy.h"

#include "Anthill.h"

void Enemy::move() {
    if (going_home) {
        float dx = home.x - pos.x;
        float dy = home.y - pos.y;
        float dist = sqrt(dx * dx + dy * dy);

        if (dist > 5.f) {
            velocity.x = (dx / dist) * enemy_speed;
            velocity.y = (dy / dist) * enemy_speed;
        }
        else {
            pos.x = home.x;
            pos.y = home.y;
            velocity.x = 0;
            velocity.y = 0;
        }

        pos.x += velocity.x;
        pos.y += velocity.y;
        shape.setPosition(pos.x, pos.y);
        return;
    }

    else if (has_target && !going_home) {
        float dx = window_width / 2 - pos.x;
        float dy = window_height / 2 - pos.y;
        float dist = sqrt(dx * dx + dy * dy);

        if (dist > 5.f) {
            velocity.x = (dx / dist) * enemy_speed;
            velocity.y = (dy / dist) * enemy_speed;
        }
        else {
            pos.x = window_width / 2;
            pos.y = window_height / 2;
            velocity.x = 0;
            velocity.y = 0;
            robbed = true;
            Anthill::del_food();
            Anthill::del_stick();
        }
        if (robbed) {
            going_home = true;
            has_target = false;
        }
        if (age % velocity_changing_period == 0)
            set_velocity(randomise_velocity() * ant_speed, randomise_velocity() * enemy_speed);

        if (pos.x + velocity.x < 0 || pos.x + velocity.x > window_width)
            velocity.x = -velocity.x;

        if (pos.y + velocity.y < 0 || pos.y + velocity.y > window_height)
            velocity.y = -velocity.y;

        pos.x += velocity.x;
        pos.y += velocity.y;
        shape.setPosition(pos.x, pos.y);
    }
    else yet_robbed = 1;
}