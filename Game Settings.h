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

//TODO
//Масштабировать визуал элементы пропорционально размерам экрана

//Window settings
#define window_weidth 1920
#define window_high 1080

//Timer settings
#define update_time 20
#define stage_time 200

//Ant settings
#define ant_size 4
#define ant_speed 4
#define velocity_change_period 20
#define life_stages 5

//Resource settings
#define form 30
#define small_resource_size 7
#define madium_resource_size 12
#define big_resource_size 16
#define max_resource_in_claster 15
#define dist_btw_res 100
#define stick_claster_count 6
#define food_cluster_count 6
#define probability_of_small_resources 70
#define probability_of_medium_resources 20

//Anthill settings
#define start_hill_size 50.f

//Enemy settings
#define wave_period 250

enum info_type { food_info, stick_info, enemy };
enum res_type { no_res, food, stick, body, trash };
enum res_size { small = madium_resource_size, medium = madium_resource_size, big = big_resource_size };