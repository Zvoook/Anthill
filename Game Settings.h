#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include <cmath>
#include <ctime>
using namespace std;
using namespace sf;

//Window settings
#define window_weidth 1920
#define window_high 1080

//Timer settings
#define update_time 250
#define stage_time_per_ticks 20

//Ant settings
#define ant_size 1000
#define ant_speed 2
#define life_stages 5

//Resource settings
#define small_resource_size 3
#define madium_resource_size 7
#define big_resource_size 12
#define max_resource_in_claster 15
#define dist_btw_res 100
#define stick_claster_count 4
#define food_cluster_count 6
#define probability_of_small_resources 70
#define probability_of_medium_resources 20

//Anthill settings
#define start_hill_size 75.f

enum info_type { food_info, stick_info, enemy };
enum res_type { no_res, food, stick, body, trash };
enum res_size { small = madium_resource_size, medium = madium_resource_size, big = big_resource_size };