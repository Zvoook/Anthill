#include "Role.h"

void Baby::role_up(weak_ptr<Ant> ant)
{
    if (auto ant = ant.lock()) {
        ant->set_role(make_shared<Sitter>());
    }
}

void Sitter::role_up(weak_ptr<Ant> ant) {}
void Builder::work(weak_ptr<Ant> ant) {}
void Builder::role_up(weak_ptr<Ant> ant) {}
void Collector::work(weak_ptr<Ant> ant) { cout << "Collecting!\n"; }
void Collector::role_up(weak_ptr<Ant> ant) {
    int h = ant->get_max_hp();
    if (h > 10) ant->set_role(make_shared<Soldier>());
    else ant->set_role(make_shared<Shepperd>());
}
void Soldier::work(weak_ptr<Ant> ant) {}
void Soldier::role_up(weak_ptr<Ant> ant) {}
void Shepperd::work(weak_ptr<Ant> ant) {}
void Shepperd::role_up(weak_ptr<Ant> ant) {}
void Cleaner::work(weak_ptr<Ant> ant) {}
void Cleaner::role_up(weak_ptr<Ant> ant) {}