#include "Ant.h"
void Ant::upd_role()
{
   /* if(role == new Baby)
    role_id++;
    role = r;*/
}

void Ant::move()
{
    //if (!has_target) set_velocity(randomise_coordinate() * ant_speed, randomise_coordinate() * ant_speed); //randomising velocity
        //pos.set_pos(pos.get_x() + velocity.x, pos.get_y() + velocity.y); //update ant position
}
    
void Ant::pick_res(Resource& res) {
    if (!res.is_visible()) return;
    else if (res.get_type() == food && role != new Collector) return;
    else if (res.get_type() == stick && role != new Builder) return;
    else if ((res.get_type() == body || res.get_type() == trash) && role != new Cleaner) return;
    res.set_invisible();
    //We should update ant's target after this
}

void Ant::drop_res() 
{

}

float randomise_velocity()
{
    int n = rand() % 3;
    switch (n) {
    case 0: return -1.0f;
    case 1: return 0.0f;
    case 2: return 1.0f;
    }
}