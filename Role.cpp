#include "Role.h"
//Role* Sitter::role_up(Ant& ant)
//{
//    bool n = rand() % 2;
//    if (n == false) {
//        Collector* collect;
//        ant.set_role(collect);
//    }
//    else {
//        Builder* build;
//        ant.set_role(build);
//    }
//}
//Role* Builder::role_up(Ant& ant)
//{
//    if (ant.get_hp() > ant.get_max_hp() / 2) {
//        Soldier* sold;
//        ant.set_role(sold);
//        ant.set_hp(ant.get_max_hp());
//    }
//    else {
//        Shepperd* shep;
//        ant.set_role(shep);
//        ant.set_hp(ant.get_max_hp());
//    }
//}
//Role* Collector::role_up(Ant& ant) {
//    if (ant.get_hp() > ant.get_max_hp() / 2) {
//        Soldier* sold;
//        ant.set_role(sold);
//        ant.set_hp(ant.get_max_hp());
//    }
//    else {
//        Shepperd* shep;
//        ant.set_role(shep);
//        ant.set_hp(ant.get_max_hp());
//    }
//}
// Role* Soldier::role_up(Ant& ant)
// {
//     Soldier* soldier;
//     ant.set_role(soldier);
// }
//Role* Shepperd::role_up(Ant& ant)
//{
//    Cleaner* cleaner;
//    ant.set_role(cleaner);
//}


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