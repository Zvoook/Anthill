#include "Role.h"
#include "Ant.h"
#include "Anthill.h"
#include "Raid.h"
#include "Resource.h"
#include "Tlya.h"

// Список глобальных врагов и ресурсов (если нужны — передай через параметры или статические ссылки)
extern vector<Ant> ants;
extern vector<Enemy> enemies;
extern vector<Resource> resources;
extern vector<Aphid> aphids;

// 👶 НЯНЬКА
void Sitter::work(Ant* self)
{
    // если есть враги рядом — ищем личинок (Baby = role_id == 0)
    if (!enemies.empty()) {
        for (Ant& ant : ants) {
            if (ant.get_role() == 0 && !ant.has_valid_target()) {
                ant.set_target(Position(window_width / 2, window_height / 2)); // внутрь муравейника
                break;
            }
        }
    }
}

// 🛠 СТРОИТЕЛЬ
void Builder::work(Ant* self)
{
    if (self->has_valid_target() || self->get_inventory() != no_res) return;

    for (Resource& res : resources) {
        if (res.is_visible() && res.get_type() == stick) {
            self->set_inventory(stick);
            self->set_target(res.get_posit());
            res.set_invisible();
            break;
        }
    }
}

// 🥕 СОБИРАТЕЛЬ
void Collector::work(Ant* self)
{
    if (self->has_valid_target() || self->get_inventory() != no_res) return;

    for (Resource& res : resources) {
        if (res.is_visible() && res.get_type() == food) {
            self->set_inventory(food);
            self->set_target(res.get_posit());
            res.set_invisible();
            break;
        }
    }
}

// ⚔️ СОЛДАТ
void Soldier::work(Ant* self)
{
    if (!enemies.empty()) {
        // Ищем ближайшего врага
        float min_dist = 1e9;
        Position target_pos;

        for (Enemy& e : enemies) {
            float dx = e.get_pos().x - self->get_pos().x;
            float dy = e.get_pos().y - self->get_pos().y;
            float dist = sqrt(dx * dx + dy * dy);

            if (dist < min_dist) {
                min_dist = dist;
                target_pos = e.get_pos();
            }
        }

        self->set_target(target_pos);
    }
    else {
        // патруль — случайное блуждание
        if (self->get_age() % velocity_changing_period == 0)
            self->set_velocity(randomise_velocity() * ant_speed, randomise_velocity() * ant_speed);
    }
}

// 🧹 УБОРЩИК
void Cleaner::work(Ant* self)
{
    if (self->has_valid_target() || self->get_inventory() != no_res) return;

    for (Resource& res : resources) {
        if (res.is_visible() && res.get_type() == body) {
            self->set_inventory(body);
            Position out_pos(window_width - 50, 50); // вне муравейника
            self->set_target(res.get_posit());
            res.set_invisible();
            break;
        }
    }
}

// 🐛 ПАСТУХ
void Shepperd::work(Ant* self)
{
    for (Aphid& a : aphids) {
        if (!a.is_shepherd() && a.is_visible()) {
            a.set_shepherd();
            self->set_target(a.get_pos());
            Anthill::add_food(); // получаем еду от тли
            break;
        }
    }
}
