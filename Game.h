#pragma once
#include <SFML/Audio.hpp>
#include <sstream>
#include "Anthill.h"
#include "Raid.h"

class Game {
public:
	Game() :ticks(0) {};
	~Game() = default;
	Anthill anthill;
	Raid raid;

	vector<Resource> resources;
	vector<Text> statsLines;

	void tick() { ticks++; }
	void add_stats(Font& font);
	void reset();
	void spawn_res();
	//void clean_ants();
	//void clean_enemy();
	void kill_all() { anthill.kill_colony(); };
	int get_ticks() const { return ticks; }
private:
	int ticks;
};