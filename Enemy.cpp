#include "Enemy.h"
//void Ant::move() {
//    if (has_target) {
//        float dx = target.x - pos.x;
//        float dy = target.y - pos.y;
//        float dist = sqrt(dx * dx + dy * dy);
//
//        if (dist > 5.f) {
//            velocity.x = (dx / dist) * ant_speed;
//            velocity.y = (dy / dist) * ant_speed;
//        }
//        else {
//            pos.x = target.x;
//            pos.y = target.y;
//            velocity.x = 0;
//            velocity.y = 0;
//
//            if (inventory != no_res && !pos.in_anthill()) {
//                set_target(Position(window_weidth / 2, window_high / 2));
//                going_home = true;
//            }
//            else if (inventory != no_res && pos.in_anthill()) {
//
//                if (inventory == food) Anthill::add_food();
//                else if (inventory == stick) Anthill::add_stick();
//
//                inventory = no_res;
//                clear_target();
//                going_home = false;
//            }
//            else {
//                has_target = false;
//            }
//        }
//
//        pos.x += velocity.x;
//        pos.y += velocity.y;
//        shape.setPosition(pos.x, pos.y);
//        return;
//    }
//
//    if (age % velocity_changing_period == 0)
//        set_velocity(randomise_velocity() * ant_speed, randomise_velocity() * ant_speed);
//
//    if (pos.x + velocity.x < 0 || pos.x + velocity.x > window_weidth)
//        velocity.x = -velocity.x;
//
//    if (pos.y + velocity.y < 0 || pos.y + velocity.y > window_high)
//        velocity.y = -velocity.y;
//
//    pos.x += velocity.x;
//    pos.y += velocity.y;
//    shape.setPosition(pos.x, pos.y);
//}