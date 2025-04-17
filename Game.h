#pragma once
#include "Game Settings.h"
#include "Resource.h"
#include "Anthill.h"
#include "Raid.h"
#include "Informers.h"
#include "Tlya.h"
#include "Cemetery.h"

class Game {
private:
	int ticks;
	bool has_started_colony = false;
	int res_cnt;
public:
	Game() :ticks(0), res_cnt(0) {};
	~Game() = default;
	Anthill anthill;
	Raid raid;
	Cemetery cemetery;
	vector<Resource> resources;
	vector<Aphid> aphids;

	vector<Text> statsLines;
	Text OVER, YOU;
	static Game* current;
	static void set_current(Game* g) { current = g; }

	void add_stats(Font& font);
	void spawn_aphids();
	void update_aphids();
	void update_ants();
	void spawn_body();
	void spawn_res(int s = stick_claster_count, int f = food_cluster_count);

	void upd_res();
	void update_enemies();
	void update(Font& font);

	void check_collisions();
	bool check_game_over();
	
	string to_K(int x);
	void reset();
	void over(Font& font);
	void kill_all() { anthill.kill_colony(); }

	int get_ticks() const { return ticks; }
	static Game* get_current() { return current; }
};