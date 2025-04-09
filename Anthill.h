#include "Game Settings.h"
#include "Ant.h"

class Anthill {
public:
    vector<Ant> colony;
    Anthill();
    ~Anthill()=default;
    void up_lvl();
    void down_lvl();
    void feeding() { food_count -= current_ants;}
    void bring_res(res_type type);
    void born_baby();
    void upd_stats() {};

    int get_soldier_count() const { return count_soldiers; }
    int get_builder_count() const { return count_builders; }
    int get_cleaner_count() const { return count_cleaners; }
    int get_sitter_count() const { return count_sitters; }
    int get_baby_count() const { return count_babies; }
    int get_shepherd_count() const { return count_shepherds; }
    int get_collector_count() const { return count_collectors; }

    /*int get_food_count() const;
    int get_stick_count() const;*/

    int get_food_count() const { return food_count; }
    int get_stick_count() const { return stick_count; }
private:
    float rad;
    int lvl, food_count, stick_count;
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
};