#include "Role.h"
#include "Ant.h"
#include "Enemy.h"
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
            break;
        }
    }
    if (!ant.get_pos().in_anthill() && !ant.has_valid_target()) {
        ant.set_target(Position(window_width / 2, window_height / 2));
    }
}

void Collector::work(Ant& ant, vector<Resource>& resources, vector<Enemy>& enemies, vector<Aphid>& aphids) {
    if (ant.get_inventory() == no_res) ant.look_around(resources, aphids, enemies);
    else if (!ant.has_valid_target() && !ant.get_pos().in_anthill()) ant.set_target(Position(window_width / 2, window_height / 2));
}

void Builder::work(Ant& ant, vector<Resource>& resources, vector<Enemy>& enemies, vector<Aphid>& aphids) {
    if (ant.get_inventory() == no_res) ant.look_around(resources, aphids, enemies);
    else if (!ant.has_valid_target() && !ant.get_pos().in_anthill()) ant.set_target(Position(window_width / 2, window_height / 2));
}

void Soldier::work(Ant& ant, vector<Resource>& resources, vector<Enemy>& enemies, vector<Aphid>& aphids) {
    // if (ant.get_hp() < 30) {
    //     escape_from_enemy(ant);
    //     return;
    // }

    for (auto& enemy : enemies) {
        if (!enemy.is_visible()) continue;

        float dx = enemy.get_pos().x - ant.get_pos().x;
        float dy = enemy.get_pos().y - ant.get_pos().y;
        float dist = sqrt(dx * dx + dy * dy);

        if (dist < soldier_radius_vision) {
            if (dist < ant_size * 1.5f) {
                attack(ant, enemy);
            } else {
                set_on_enemy(ant, enemy);
            }
            return;
        }
    }

    ant.move();
}

void Soldier::attack(Ant& ant, Enemy& enemy) {
    enemy.take_damage(ant.get_attack_power());
    ant.take_damage(enemy_damage);
}
//
// void Soldier::regen(Ant& ant) {
//     if (ant.set_hp(ant.get_hp()) = ant.get_hp() + 100);
// }

// void Soldier::escape_from_enemy(Ant& ant) {
//     if (ant.get_hp() < 100) {
//         ant.set_target(Position(window_width / 2, window_height / 2));
//     }
// }

void Soldier::set_on_enemy(Ant& ant, Enemy& enemy) {
    ant.set_target(enemy.get_pos());
}

void Shepperd::work(Ant& ant, vector<Resource>& resources, vector<Enemy>& enemies, vector<Aphid>& aphids) {
    if (ant.get_inventory() == no_res) {
        ant.look_around(resources, aphids, enemies);
    }
    else if (!ant.has_valid_target() && !ant.get_pos().in_anthill()) {
        ant.set_target(Position(window_width / 2, window_height / 2));
    }
}


void Cleaner::work(Ant& ant, vector<Resource>& resources, vector<Enemy>& enemies, vector<Aphid>& aphids) {
    Cemetery* cemetery = Cemetery::get_current();
    if (!cemetery) return;

    if (ant.get_inventory() == no_res) {
        ant.look_around(resources, aphids, enemies);
    }
    else if (!cemetery->in_cemetery(ant.get_pos())) {
        ant.set_target(cemetery->get_center());
    }
}