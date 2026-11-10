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


// =================== Окно ===================
const int window_width = 1200;       // ширина окна
const int window_height = 1000;      // высота окна


// =================== Таймер ===================
const int fps = 20;                          // количество тиков в секунду
const int second = 1000 / fps;               // миллисекунд в одном "игровом" секунда
const int feeding_period = 6 * second;       // частота кормления колонии
const int hunger_damage = 1;                 // урон от голода
const int stage_time = 6 * second;           // время взросления муравья
const int min_born_period = 0.2 * second;    // минимальный интервал между рождениями
const int food_for_born = 16;                // еда, необходимая для рождения


// =================== Муравьи ===================
const int max_ants_on_map = 100;             // максимум муравьев на карте
const int ant_size = 0.0073 * window_width;  // размер муравья
const int ant_speed = 6;                     // скорость муравья
const int velocity_changing_period = 10;     // период смены направления
const bool vision_circle = false;            // отображать ли круг обзора
const int soldier_radius_vision = 1500.f;    // радиус обзора солдата


// =================== Ресурсы ===================
const int stick_score = 225;                          // очки за палку
const int food_score = 30;                            // очки за еду
const int food_cluster_count = 0.008 * window_width;  // количество кластеров еды
const int stick_claster_count = 0.004 * window_width; // количество кластеров палок
const int max_resource_in_claster = 35;               // макс. ресурсов в кластере
const int res_regen_time = 8 * second;                // время респауна ресурсов
const int max_res_op_map = 100;                       // максимум ресурсов на карте
const int count_of_angles_in_form = 16;               // углов у формы ресурса
const int small_resource_size = 1;                    // размер маленького ресурса
const int madium_resource_size = 5;                   // размер среднего ресурса
const int big_resource_size = 10;                     // размер большого ресурса
const int dist_btw_res = 0.17 * window_width;         // расстояние между ресурсами
const int probability_of_small_resources = 70;        // вероятность маленького ресурса
const int probability_of_medium_resources = 20;       // вероятность среднего ресурса


// =================== Тля ===================
const int aphid_cluster_count = 0.003 * window_width;   // кластеров тли
const int max_aphids_in_cluster = 4;                    // макс. тлей в кластере
const float aphid_speed = 0.2;                          // скорость тли
const float aphid_size = ant_size * 0.7f;               // размер тли
const int aphid_honey_value = 3;                        // сколько мёда дает тля
const int honey_collect_time = 3 * second;              // время сбора мёда


// =================== Муравейник ===================
const int start_radius = 0.07 * window_width;       // начальный радиус
const int start_max_ant_count = 45;                 // макс. муравьёв на старте
const int start_food_limit = 600;                   // лимит еды на старте
const int start_stick_for_update = 6000;            // палок для апгрейда
const int start_ant_count = 25;                     // стартовое количество муравьев
const int min_downgrade_period = 7 * second;        // интервал деградации


// =================== Враги ===================
const int enemy_damage = 22;                                         // урон врага
const int enemy_wave_period = 11 * second;                           // период рейдов
const int min_enemy_in_wave = 2;                                     // минимум врагов в рейде
const int max_diffusion_enemy_in_wave = 8;                           // разброс количества врагов
const int enemy_speed = 4;                                           // скорость врага
const int rob_res_count = 100;                                       // сколько ресурсов крадут
const int time_without_enemy = (rand() % 3 + 2) * enemy_wave_period; // начальная задержка


enum info_type { food_info, stick_info, enemy };
enum res_type { no_res, food, stick, aphid, body, trash };
enum res_size { small = madium_resource_size, medium = madium_resource_size, big = big_resource_size };