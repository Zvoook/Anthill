#ifndef ANTHILL_H
#define ANTHILL_H
#include <vector>
// #include "Role.h"



class Anthill {
public:
    Anthill();
    ~Anthill();
    void up_lvl();
    void down_lvl();
    void work();
    void bring_material(int rank_material); //ÑÑÑ ÐºÑÑ Ð² Ð¿Ð°ÑÐ°Ð¼ÐµÑÑÐ°Ñ Ð½Ð°Ð´Ð¾ ÑÐºÐ°Ð·Ð°ÑÑ Ð½Ð°ÑÐºÐ¾Ð»ÑÐºÐ¾ Ð±Ð¾Ð»ÑÑÐ°Ñ Ð²ÐµÑÐºÐ° Ð¿ÑÐ¸Ð½ÐµÑÐµÐ½Ð°
    void bring_food(int rank_food); //ÑÑÑ Ð½Ð°ÑÐºÐ¾Ð»ÑÐºÐ¾ Ð±Ð¾Ð»ÑÑÐ°Ñ ÐµÐ´Ð°
    void print_characteristics(); //Ð²ÑÐ²Ð¾Ð´ Ð²ÑÐµÑ ÑÐ°ÑÐ°ÐºÑÐµÑÐ¸ÑÑÐ¸Ðº Ð¼ÑÑÐ°Ð²ÐµÐ¹Ð½Ð¸ÐºÐ°
    void born_baby();
    // ÑÑÐ°Ð½Ð¸ÑÑ Ð²ÐµÐºÑÐ¾Ñ ÐºÐ¾Ð»Ð¾Ð½Ð¸Ð¸ Ð¸ Ð´Ð¾Ð±Ð°Ð²Ð»ÑÑÑ/Ð²ÑÑÐ¸ÑÐ°ÑÑ
    // ÑÐµÐ°Ð»Ð¸Ð·Ð¾Ð²Ð°ÑÑ Ð¿Ð¾ÑÑÐµÐ¿ÐµÐ½Ð½Ð¾Ðµ ÑÐ°Ð·ÑÑÑÐµÐ½Ð¸Ðµ: Ð¿ÐµÑÐ²ÑÐµ 10 Ð¼ÑÑÐ°Ð²ÑÐµÐ² Ð¸Ð· ÐºÐ¾Ð»Ð¾Ð½Ð¸Ð¸ ÑÐ¼Ð¸ÑÐ°ÑÑ, ÐµÐ´Ð° ÑÐ¼ÐµÐ½ÑÑÐ°ÐµÑÑÑ Ð½Ð° ÑÐ°Ð½Ð´Ð¾Ð¼ ÐºÐ¾Ð»Ð²Ð¾
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
    int radius;
    std::vector<Ant&> colony;
};
#endif