#include "Tlya.h"
void Aphid::move() {
    if (is_shepherded) return;
    if (age % (velocity_changing_period * 3) == 0) {
        velocity.x = randomise_velocity_aphid() * aphid_speed; 
        velocity.y = randomise_velocity_aphid() * aphid_speed;
    }
    if (pos.x + velocity.x < 0 || pos.x + velocity.x > window_width) velocity.x = -velocity.x;
    if (pos.y + velocity.y < 0 || pos.y + velocity.y > window_height) velocity.y = -velocity.y;
    pos.x += velocity.x;
    pos.y += velocity.y;
    shape.setPosition(pos.x, pos.y);
}

int Aphid::produce_honey() {
    if (is_shepherded) {
        honey_timer++;
        if (honey_timer >= 20) {  
            honey_timer = 0;
            honey_amount += 5;    
            return 5;
        }
    }
    else {
        honey_timer++;
        if (honey_timer >= 50) {  
            honey_timer = 0;
            honey_amount += 2;   
            return 2;
        }
    }
    return 0;
}

void Aphid::update() {
    age++;
    produce_honey();
    if (age > 1000) hp--;
    if (is_shepherded && hp < 100 && age % 30 == 0) hp++;
    move();
}

void create_aphid_cluster(vector<Aphid>& aphids, float x, float y, int count) {
    for (int i = 0; i < count; i++) {
        float shift_x = (rand() % dist_btw_res) - dist_btw_res / 2;
        float shift_y = (rand() % dist_btw_res) - dist_btw_res / 2;

        Aphid aphid(x + shift_x, y + shift_y);
        aphids.push_back(aphid);
    }
}

float randomise_velocity_aphid()
{
    int n = rand() % 3;
    switch (n) {
    case 0: return -1.0f;
    case 1: return 0.0f;
    case 2: return 1.0f;
    }
}