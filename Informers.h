#pragma once
#include "Game Settings.h"
#include <map>
#include "Ant.h"
#include "Resource.h"

class Informers {
private:
    // ¬ектор векторов: индекс соответствует типу ресурса (см. enum res_type)
    // resources[0] Ц дл€ no_res 
    // resources[1] Ц дл€ food,
    // resources[2] Ц дл€ stick,
    // resources[3] Ц дл€ aphid,
    // resources[4] Ц дл€ body,
    // resources[5] Ц дл€ trash.
    vector<vector<Resource*>> resources;

    // ћуравьи группируютс€ по рол€м: ключ Ц номер роли (значение, возвращаемое Ant::get_role())
    map<int, vector<Ant*>> ants_by_role;
    float detect_dist;

public:
    //  онструктор: инициализирует радиус обнаружени€ и подготавливает вектор дл€ 6 типов ресурсов.
    Informers(float detect_dist) : detect_dist(detect_dist) { resources.resize(6); }

    // –егистраци€/удаление муравь€
    void subscribe_ant(Ant* ant);
    void unsubscribe_ant(Ant* ant);

    // –егистраци€/удаление ресурса Ц ресурс добавл€етс€ в под-вектор согласно его типу (значение из enum)
    void subscribe_resource(Resource* resource);
    void unsubscribe_resource(Resource* resource);

    // ќсновное обновление: обход ресурсов и назначение целей муравь€м, если ресурс виден,
    // активен (is_visible()) и количество > 0.
    void update_status();

    // ѕроверка, находитс€ ли ресурс в зоне обнаружени€ муравь€
    bool can_see(Ant* ant, Resource* resource);

    // Ќазначение ресурса ближайшему свободному муравью подход€щей роли
    void add_resource(Resource* resource);

    // »нформирование подход€щих муравьЄв о ресурсе, если текущий муравей не может его подобрать
    void inform_about_resource(Ant* informer_ant, Resource* resource);

    // ѕоиск ближайшего свободного муравь€ с указанной ролью дл€ данного ресурса
    Ant* find_free_ant(Resource* resource, int role_id);

    // ќчистка информации о ресурсе (например, когда его количество становитс€ 0)
    void clear_info(Resource* resource);
};