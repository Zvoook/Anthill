#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include <cmath>
#include <ctime>
//#include <limits>
using namespace std;
using namespace sf;

//Window settings
const int window_width = 1200;
const int window_height = 1000;

//Timer settings
const int fps = 20;
const int second = 1000 / fps;
const int feeding_period = 5 * second;           // 5 секунд на кормление
const int hunger_damage = 2;                     // умеренный голод
const int stage_time = 6 * second;               // ускоренная стадия взросления
const int min_born_period = 3 * second;          // рождение реже
const int food_for_born = 20;                    // рождение дороже

//Ant settings
const int ant_size = 0.0075 * window_width;
const int ant_speed = 6; // было 8 — слишком быстро, глаза не успевают
const int velocity_changing_period = 15; // больше стабильности
const bool vision_circle = true;
const int soldier_radius_vision = 1500.f;

//Resource settings
const int stick_score = 233;
const int food_score = 24;
const int food_cluster_count = 0.006 * window_width;       // немного больше еды
const int stick_claster_count = 0.004 * window_width;      // нормальное число палок
const int max_resource_in_claster = 30;                    // оставим как есть
const int res_regen_time = 8 * second;
const int max_res_op_map = 100;
const int count_of_angles_in_form = 16;
const int small_resource_size = 1;
const int madium_resource_size = 5;
const int big_resource_size = 10;
const int dist_btw_res = 0.17 * window_width;
const int probability_of_small_resources = 70;
const int probability_of_medium_resources = 20;

//Aphid settings
const int aphid_cluster_count = 0.003 * window_width;
const int max_aphids_in_cluster = 4;
const float aphid_speed = 0.2;
const float aphid_size = ant_size * 0.7f;
const int aphid_honey_value = 2;
const int honey_collect_time = 3 * second;

//Anthill settings
const int start_radius = 0.07 * window_width;    //начальный радиус муравейника
const int start_max_ant_count = 35;              // лимит муравьев на старте
const int start_food_limit = 500;                // лимит еды
const int start_stick_for_update = 7000;         // палок для первого апгрейда
const int start_ant_count = 25;                  // 
const int min_downgrade_period = 7 * second;

//Enemy settings
const int enemy_damage = 50;
const int enemy_wave_period = 15 * second;       // рейды каждые 15 секунд
const int min_enemy_in_wave = 3;                 // минимум врагов в рейде
const int enemy_speed = 4;
const int rob_res_count = 140;

enum info_type { food_info, stick_info, enemy };
enum res_type { no_res, food, stick, aphid, body, trash };
enum res_size { small = madium_resource_size, medium = madium_resource_size, big = big_resource_size };