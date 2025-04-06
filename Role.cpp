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
//Role* Soldier::role_up(Ant& ant)
//{
//    Cleaner* cleaner;
//    ant.set_role(cleaner);
//}
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

void Soldier::work() 
{

}

void Shepperd::work()
{
    
}

void Cleaner::work() 
{

}