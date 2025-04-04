#ifndef ANTHILL_H
#define ANTHILL_H
#include <vector>



class Anthill {
public:
    Anthill();
    ~Anthill();
    void up_lvl();
    void bring_material(int rank_material); //тут крч в параметрах надо указать насколько большая ветка принесена
    void bring_food(int rank_food); //тут насколько большая еда
private:
    int lvl;
    int current_food;
    int current_materials;
    int current_ants;
    int place_for_food;
    int place_for_materials;
    int place_for_ants;
    // std::vector<> soldiers;
    // std::vector<> builders;
    // std::vector<> cleaners;
    // std::vector<> babysitters;
    // std::vector<> babies;
    // std::vector<> shepherds;
};



#endif
