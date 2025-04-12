﻿#pragma once
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
const int window_weidth = 1000;
const int window_high = 1000;

//Timer settings
const int fps = 20; //ticks per ms
const int in_second = (int)(1000 / fps); //second
const int stage_time = 7 * in_second; //time of live in stage

//Ant settings
const int ant_size = 0.006 * window_weidth;
const int ant_speed = 8;
const int velocity_changing_period = 10;

//Aphid settings
const int aphid_cluster_count = 0.003 * window_weidth; 
const int max_aphids_in_cluster = 4;                 
const float aphid_speed = 0.2;  
const float aphid_size = ant_size * 0.7f;
const int aphid_honey_value = 2;                      
const int honey_collect_time = 3 * in_second;         

//const int life_stages = 5;
const bool vision_circle = true;
const int hungry_damage = 1;

//Resource settings
const int count_of_angles_in_form = 16;
const int small_resource_size = 1;
const int madium_resource_size = 5;
const int big_resource_size = 10;
const int max_resource_in_claster = 30;
const int dist_btw_res = 0.15 * window_weidth;
const int stick_claster_count = 0.01 * window_weidth;
const int food_cluster_count = 0.01 * window_weidth;
const int probability_of_small_resources = 70;
const int probability_of_medium_resources = 20;

//Anthill settings
const int start_radius = 0.07 * window_weidth;
const int start_max_ant_count = 20;
const int start_food_limit = 32500;
const int start_stick_for_update = 1000;
const int start_ant_count = 30;

//Ant born and feeding
const int min_born_period = 2 * in_second;
const int food_for_born = 10;
const int feeding_period = 3 * in_second;

//Enemy settings
const int enemy_wave_period = 5 * in_second;
const int life_time = 5 * in_second;
const int min_enemy_in_wave = 5;
const int enemy_speed = 4;

enum info_type { food_info, stick_info, enemy };
enum res_type { no_res, food, stick, body, trash, enemy_info };
enum res_size { small = madium_resource_size, medium = madium_resource_size, big = big_resource_size };