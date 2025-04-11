#include "Enemy.h"
#include "Anthill.h"

void Enemy::move() {
    if (going_home) {
        float dx = 1000 - pos.x;
        float dy = 10 - pos.y;
        float dist = sqrt(dx * dx + dy * dy);

        if (dist > 5.f) {
            velocity.x = (dx / dist) * enemy_speed;
            velocity.y = (dy / dist) * enemy_speed;
        }
        else {
            pos.x = 1090;
            pos.y = 10;
            velocity.x = 0;
            velocity.y = 0;
        }

        pos.x += velocity.x;

        if (has_target && !going_home) {
            float dx = window_weidth / 2 - pos.x;
            float dy = window_high / 2 - pos.y;
            float dist = sqrt(dx * dx + dy * dy);

            if (dist > 5.f) {
                velocity.x = (dx / dist) * enemy_speed;
                velocity.y = (dy / dist) * enemy_speed;
            }
            else {
                pos.x = window_weidth / 2;
                pos.y = window_high / 2;
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

            if (pos.x + velocity.x < 0 || pos.x + velocity.x > window_weidth)
                velocity.x = -velocity.x;

            if (pos.y + velocity.y < 0 || pos.y + velocity.y > window_high)
                velocity.y = -velocity.y;

            pos.x += velocity.x;
            pos.y += velocity.y;
            shape.setPosition(pos.x, pos.y);
        }
    }
}