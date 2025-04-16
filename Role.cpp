#include "Role.h"
#include "Ant.h"
#include "Anthill.h"
#include "Resource.h"
#include "Tlya.h"
#include "Enemy.h"

void Baby::work(Ant& ant, vector<Resource>&, vector<Enemy>&) { /*if (ant.is_warmed()) ant.set_warmed(false)*/ ; }

void Sitter::work(Ant& ant, vector<Resource>&, vector<Enemy>&) {
    for (Ant& other : Anthill::get_instance()->colony) {
        if (other.get_role() != 0 || other.get_hp() <= 0) continue; // ищем живую личинку

        float dx = other.get_pos().x - ant.get_pos().x;
        float dy = other.get_pos().y - ant.get_pos().y;
        float dist = sqrt(dx * dx + dy * dy);

        if (dist < 3.f * ant_size) {
            other.age_up(0.25 * stage_time);
            other.set_warmed(true);
            break;
        }
    }

    if (!ant.get_pos().in_anthill() && !ant.has_valid_target()) {
        ant.set_target(Position(window_width / 2, window_height / 2));
    }
}

void Collector::work(Ant& ant, vector<Resource>& resources, vector<Enemy>& enemy) {
    if (ant.get_inventory() == no_res) ant.look_around(resources);
    else if (!ant.has_valid_target() && !ant.get_pos().in_anthill()) ant.set_target(Position(window_width / 2, window_height / 2));
}

void Builder::work(Ant& ant, vector<Resource>& resources, vector<Enemy>& enemy) {
    if (ant.get_inventory() == no_res) ant.look_around(resources);
    else if (!ant.has_valid_target() && !ant.get_pos().in_anthill()) ant.set_target(Position(window_width / 2, window_height / 2));
}

//void Soldier::work(Ant* self, GameContext* ctx) {
//    if (!ctx->enemies->empty()) {
//        float min_dist = 1e9;
//        Position target_pos;
//        for (Enemy& e : *ctx->enemies) {
//            float dx = e.get_pos().x - self->get_pos().x;
//            float dy = e.get_pos().y - self->get_pos().y;
//            float dist = sqrt(dx * dx + dy * dy);
//            if (dist < min_dist) {
//                min_dist = dist;
//                target_pos = e.get_pos();
//            }
//        }
//        self->set_target(target_pos);
//    }
//    else {
//        if (self->get_age() % velocity_changing_period == 0)
//            self->set_velocity(randomise_velocity() * ant_speed, randomise_velocity() * ant_speed);
//    }
//}
//

void Shepperd::work(Ant& ant, vector<Resource>& resources, vector<Enemy>& enemy) {
    if (ant.get_inventory() == no_res) ant.look_around(resources);
    else if (!ant.has_valid_target() && !ant.get_pos().in_anthill())  ant.set_target(Position(window_width / 2, window_height / 2));
}


void Cleaner::work(Ant& ant, vector<Resource>& resources, vector<Enemy>&) {
    Cemetery* cemetery = Cemetery::get_current();
    if (!cemetery) return;

    if (ant.get_inventory() == no_res) {
        ant.look_around(resources);
    }
    else if (!cemetery->in_cemetery(ant.get_pos())) {
        ant.set_target(cemetery->get_center());
    }
}