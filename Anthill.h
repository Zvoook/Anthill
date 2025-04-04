#ifndef ANTHILL_H
#define ANTHILL_H
#include <vector>



class Anthill {
public:
    Anthill();
    ~Anthill();
    void up_lvl();
private:
    int lvl;
    int place_for_food;
    int place_for_materials;
    int place_for_ants;
    std::vector<> soldiers;
    std::vector<> builders;
    std::vector<> cleaners;
    std::vector<> babysitters;
    std::vector<> babies;
    std::vector<> shepherd;
};



#endif
