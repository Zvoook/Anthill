#include "Ant.h"
void Ant::update() {
    life_time++;  //update ticks
    //if (!has_target) set_velocity(randomise_coordinate() * ant_speed, randomise_coordinate() * ant_speed); //randomising velocity
    pos.set_pos(pos.get_x() + velocity.x, pos.get_y() + velocity.y); //update ant position
    //if (life_time % 20 == 0) {
    //    Role* new_role = role->role_up(*this); //update role
    //    if (new_role != nullptr && new_role != role) {
    //        delete role;
    //        role = new_role;
    //    }
    //}
}

//void Ant::pick_res(Resource& res) {
//    Collector* col;
//    Builder* build;
//    Cleaner* clean;
//    if (!res.is_visible_res()) return;
//    else if (res.get_type() == food && role != col) return;
//    else if (res.get_type() == stick && role != build) return;
//    else if ((res.get_type() == body || res.get_type() == trash) && role != clean) return;
//    res.set_invisible();
//    //We should update ant's target after this
//}

void Ant::drop_res() {

}
