#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include <cmath>
#include <ctime>
#include <limits>
using namespace std;
using namespace sf;

//Window settings
const int window_weidth = 900;
const int window_high = 900;

//Timer settings
const int scene_update_time = 20; //ticks per ms
const int in_second = (int)(1000 / scene_update_time); //second
const int stage_time = 7 * in_second; //time of live in stage

//Ant settings
const int ant_size = 6;
const int ant_speed = 8;
const int velocity_changing_period = 10;
//const int life_stages = 5;
const bool vision_circle = true;

//Resource settings
const int count_of_angles_in_form = 30;
const int small_resource_size = 1;
const int madium_resource_size = 5;
const int big_resource_size = 10;
const int max_resource_in_claster = 30;
const int dist_btw_res = 100;
const int stick_claster_count = 12;
const int food_cluster_count = 10;
const int probability_of_small_resources = 70;
const int probability_of_medium_resources = 20;

//Anthill settings
const int start_radius = 50.f;
const int start_max_ant_count = 20;
const int start_food_limit = 500;
const int start_stick_limit = 1000;
const int start_ant_count = 30;
const int min_born_period = 2 * in_second;
const int food_for_born = 10;
const int feeding_period = in_second;

//Enemy settings
const int enemy_wave_period = 250;

enum info_type { food_info, stick_info, enemy };
enum res_type { no_res, food, stick, body, trash };
enum res_size { small = madium_resource_size, medium = madium_resource_size, big = big_resource_size };