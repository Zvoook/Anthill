#include "Ants.h"

void Collector::work(shared_ptr<Ant> ant) { cout << "Collecting!\n"; }

void Collector::role_up(shared_ptr<Ant> ant) {
    int h = ant->get_max_hp();
    if (h > 10) ant->set_role(make_shared<Solder>());
    else ant->set_role(make_shared<Sheppert>());
}

void Cleaner::work(shared_ptr<Ant> ant) {}

void Cleaner::role_up(shared_ptr<Ant> ant){}

void create_cluster(vector<Resource>& resources, float x, float y, res_type type)
{
    int res_in_cluster = rand() % 10 + 5;
    for (int i = 0; i < res_in_cluster; ++i) {
        float shift_x = (rand() % 100) - 50;
        float shift_y = (rand() % 100) - 50;

        int n = rand() % 100;
        res_size size;
        if (n < probability_of_small_resources) { size = small; }
        else if (n < probability_of_small_resources+ probability_of_medium_resources) { size = medium; }
        else { size = big; }
        Resource res(type, size);
        res.set_posit(x + shift_x, y + shift_y);
        resources.push_back(res);
    }
}

void Sitter::role_up(shared_ptr<Ant> ant)
{
}

void Builder::work(shared_ptr<Ant> ant)
{
}

void Builder::role_up(shared_ptr<Ant> ant)
{
}

void Solder::work(shared_ptr<Ant> ant)
{
}

void Solder::role_up(shared_ptr<Ant> ant)
{
}

void Sheppert::work(shared_ptr<Ant> ant)
{
}

void Sheppert::role_up(shared_ptr<Ant> ant)
{
}

void Ant::update() {
    life_time++;
    set_velocity((rand() % 2 ? -1.0f : 1.0f) * ant_speed, (rand() % 2 ? -1.0f : 1.0f) * ant_speed);
    pos.set_pos(pos.get_x() + velocity.x, pos.get_y() + velocity.y);
    if (life_time % 20 == 0) role->role_up(shared_from_this());
    if (life_time == life_stages * stage_time_per_ticks) kill();
}
