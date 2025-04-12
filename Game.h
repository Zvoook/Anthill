#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Anthill.h"
#include "Raid.h"
#include "Tlya.h"


using namespace std;
using namespace sf;

class Game {
public:
    Game() : ticks(0) { }
    Anthill anthill;
    Raid raid;
    vector<Resource> resources;
    vector<Aphid> aphids;  
    vector<Text> statsLines;
	void tick() { ticks++; }
	void add_stats(Font& font);
	void reset();
	void spawn_res();
	void spawn_aphids(); 
	void spawn_body();
	void kill_raid();
	void update_aphids(); 
	void kill_all() { anthill.kill_colony(); }
	int get_ticks() const { return ticks; }
	string to_K(int x);
private:
    int ticks;
};
