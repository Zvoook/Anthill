#pragma once
#include <vector>
#include <map>
#include "Ant.h"
#include "Resource.h"

using std::vector;
using std::map;

class Informers {
private:
    // Вектор векторов: индекс соответствует типу ресурса (см. enum res_type)
    // resources[0] – для no_res 
    // resources[1] – для food,
    // resources[2] – для stick,
    // resources[3] – для aphid,
    // resources[4] – для body,
    // resources[5] – для trash.
    vector<vector<Resource*>> resources;

    // Муравьи группируются по ролям: ключ – номер роли (значение, возвращаемое Ant::get_role())
    map<int, vector<Ant*>> ants_by_role;
    float detect_dist;

public:
    // Конструктор: инициализирует радиус обнаружения и подготавливает вектор для 6 типов ресурсов.
    Informers(float detect_dist): detect_dist(detect_dist){resources.resize(6);}

    // Регистрация/удаление муравья
    void subscribe_ant(Ant* ant);
    void unsubscribe_ant(Ant* ant);

    // Регистрация/удаление ресурса – ресурс добавляется в под-вектор согласно его типу (значение из enum)
    void subscribe_resource(Resource* resource);
    void unsubscribe_resource(Resource* resource);

    // Основное обновление: обход ресурсов и назначение целей муравьям, если ресурс виден,
    // активен (is_visible()) и количество > 0.
    void update_status();

    // Проверка, находится ли ресурс в зоне обнаружения муравья
    bool can_see(Ant* ant, Resource* resource);

    // Назначение ресурса ближайшему свободному муравью подходящей роли
    void add_resource(Resource* resource);

    // Информирование подходящих муравьёв о ресурсе, если текущий муравей не может его подобрать
    void inform_about_resource(Ant* informer_ant, Resource* resource);

    // Поиск ближайшего свободного муравья с указанной ролью для данного ресурса
    Ant* find_free_ant(Resource* resource, int role_id);

    // Очистка информации о ресурсе (например, когда его количество становится 0)
    void clear_info(Resource* resource);
};
