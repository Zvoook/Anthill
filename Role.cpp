#include "Role.h"
void Sitter::work()
{

}

void Builder::work()
{

}

void Collector::work()
{

}

Soldier::Soldier() {
    damage = rand() % 21 + 30;
}

void Soldier::work()
{
    //if (raid_flag == 1)


}

void Soldier::attack() {

}

void Soldier::escape_from_enemy() {
}

void Soldier::set_on_enemy() {

}


void Shepperd::work()
{

}

void Cleaner::work()
{

}