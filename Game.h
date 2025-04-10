#pragma once
#include <SFML/Audio.hpp>
#include <sstream>
#include "Anthill.h"
#include "Enemy.h"

class Game {
public:
	Game() :ticks(0) {};
	~Game() = default;
	Anthill anthill;
	vector<Enemy> raid;
	vector<Resource> resources;
	vector<Text> statsLines;
	void tick() { ticks++; }
	int get_ticks() const { return ticks; }

	auto makeText(const string& text, Color color, Font& font);
	void add_stats(Font& font);
private:
	int ticks;
};