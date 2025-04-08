#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include <cmath>
using namespace std;


//Window settings
#define window_weidth 1920
#define window_high 1080

//Timer settings
#define update_time 250
#define stage_time_per_ticks 20

//Ant settings
#define ant_size 10
#define ant_speed 2
#define life_stages 5

//Anthill settings
#define lvl_1_place_for_ants 30
#define lvl_1_place_for_food 50000
#define lvl_1_place_for_materials 1000

//Resource settings
#define resource_size 2
#define stick_claster_count 2
#define food_cluster_count 3
#define probability_of_small_resources 70
#define probability_of_medium_resources 20

enum roles { baby, sitter, collector, builder, solder, sheppert, cleaner };
enum character { passive, agressive };
enum info_type { food_info, stick_info, enemy };
enum res_type { no_res, food, stick, body, trash };
enum res_size { small = 1, medium, big };