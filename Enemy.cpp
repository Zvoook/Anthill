#include "Enemy.h"
void Enemy::move() {
    if (age % 10 == 0) set_velocity(randomise_velocity() * ant_speed, randomise_velocity() * ant_speed); //randomising velocity
    if (pos.get_x() + velocity.x<0 || pos.get_x() + velocity.x > window_weidth) velocity.x = -velocity.x;
    if (pos.get_y() + velocity.y<0 || pos.get_y() + velocity.y > window_high) velocity.y = -velocity.y;
    pos.set_pos(pos.get_x() + velocity.x, pos.get_y() + velocity.y); //update ant position
    shape.setPosition(pos.get_x(), pos.get_y());
}