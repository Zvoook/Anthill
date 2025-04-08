#ifndef ANTHILL_H
#define ANTHILL_H
#include <vector>
// #include "Role.h"



class Anthill {
public:
    Anthill();
    ~Anthill();
    void up_lvl();
    void bring_material(int rank_material); //тут крч в параметрах надо указать насколько большая ветка принесена
    void bring_food(int rank_food); //тут насколько большая еда
    void print_characteristics(); //вывод всех характеристик муравейника
private:
    int lvl;
    int current_food;
    int current_materials;
    int current_ants;
    int place_for_food;
    int place_for_materials;
    int place_for_ants;
    int count_soldiers;
    int count_builders;
    int count_cleaners;
    int count_sitters;
    int count_babies;
    int count_shepherds;
    int count_collectors;
    // std::vector<Soldier> soldiers;
    // std::vector<Builder> builders;
    // std::vector<Cleaner> cleaners;
    // std::vector<Sitter> sitters;
    // std::vector<Baby> babies;
    // std::vector<Shepperd> shepherds;
    // std::vector<Collector> collectors;
};



#endif
