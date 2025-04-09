#include "Game Settings.h"
#include "Ant.h"

class Anthill {
public:
    vector<Ant> colony;
    Anthill();
    ~Anthill()=default;
    void up_lvl();
    void down_lvl();
    void feeding() { food_count -= ants;}
    void bring_res(res_type type);
    void born_baby();
    void drop(Ant& ant);
    void upd_ant_stats();
    void default_count() {ants = soldiers = builders = cleaners = cleaners = sitters = babies = shepherds = collectors = 0;}

    int get_soldier_count() const { return soldiers; }
    int get_builder_count() const { return builders; }
    int get_cleaner_count() const { return cleaners; }
    int get_sitter_count() const { return sitters; }
    int get_baby_count() const { return babies; }
    int get_shepherd_count() const { return shepherds; }
    int get_collector_count() const { return collectors; }
    int get_food_count() const { return food_count; }
    int get_stick_count() const { return stick_count; }
    int get_ant_count() const { return ants; }
private:
    float rad;
    int lvl, food_count, stick_count, max_food, max_sticks, max_ants;
    int ants, babies, sitters, collectors, builders, soldiers, shepherds, cleaners;
};