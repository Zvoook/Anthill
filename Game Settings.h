#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include <cmath>
#include <ctime>
using namespace std;


//TODO
//�������������� ������ �������� ��������������� �������� ������

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

//Anthill settings
#define lvl_1_place_for_ants 30
#define lvl_1_place_for_food 50000
#define lvl_1_place_for_materials 1000
#define lvl_1_count_soldiers 3;
#define lvl_1_count_builders 3;
#define lvl_1_count_cleaners 3;
#define lvl_1_count_sitters 3;
#define lvl_1_count_babies 3;
#define lvl_1_count_shepherds 3;
#define lvl_1_count_collectors 3;

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