#include "Raid.h"

void Raid::spawn_raid()
{
	int n = rand() % 3 + 1, c=rand()%6+min_enemy_in_wave;
	int x = 20, y = 20;
	switch (n) {
	case 1: x = window_weidth - x; break;
	case 2: y = window_high - y; break;
	case 3: {
		x = window_weidth - x;
		y = window_high - y;
	}
	}
	for (int i=0; i < c; ++i) raid.emplace_back(x, y);
}