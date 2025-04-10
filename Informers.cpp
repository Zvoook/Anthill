#include "Informers.h"
#include <algorithm>
#include <cmath>
#include <limits>

void Informers::subscribe_ant(Ant* ant) {
    int role_id = ant->get_role();
    ants_by_role[role_id].push_back(ant);
}

void Informers::unsubscribe_ant(Ant* ant) {
    int role_id = ant->get_role();
    auto& ants = ants_by_role[role_id];
    ants.erase(remove(ants.begin(), ants.end(), ant), ants.end());
}

void Informers::subscribe_resource(Resource* resource) {
    int type = resource->get_type(); 
    if (type >= 0 && type < resources.size()) {
        resources[type].push_back(resource);
    }
}

void Informers::unsubscribe_resource(Resource* resource) {
    int type = resource->get_type();
    if (type >= 0 && type < resources.size()) {
        auto& res_vec = resources[type];
        res_vec.erase(remove(res_vec.begin(), res_vec.end(), resource), res_vec.end());
    }
}

bool Informers::can_see(Ant* ant, Resource* resource) {
    if (!resource) return false;
    Vector2f ant_pos(ant->get_pos().x, ant->get_pos().y);
    Vector2f res_pos(resource->get_posit().x, resource->get_posit().y);
    float dx = ant_pos.x - res_pos.x;
    float dy = ant_pos.y - res_pos.y;
    float distance = sqrt(dx * dx + dy * dy);
    // Ресурс считается видимым, если находится в зоне обнаружения, является видимым и его количество > 0.
    return (distance <= detect_dist && resource->is_visible() && resource->get_quantity() > 0);
}

void Informers::update_status() {
    for (auto& role_pair : ants_by_role) {
        int role_id = role_pair.first;
        auto& ants = role_pair.second;
        vector<int> target_types;
        if (role_id == 3) target_types.push_back(food);
        else if (role_id == 2) target_types.push_back(stick);
        else if (role_id == 6) {
            target_types.push_back(body);
            target_types.push_back(trash);
        }
        for (Ant* ant : ants) {
            if (ant->has_valid_target())
                continue;
            bool target_found = false;
            for (int type : target_types) {
                if (target_found) break;
                for (Resource* resource : resources[type]) {
                    if (can_see(ant, resource)) {
                        if (ant->pick(*resource)) {
                            ant->set_target(resource->get_posit());
                            target_found = true;
                            break;
                        }
                        else {
                            inform_about_resource(ant, resource);
                        }
                    }
                }
            }
        }
    }
}

void Informers::inform_about_resource(Ant* informer_ant, Resource* resource) {
    int required_role_id = -1;
    int type = resource->get_type();
    switch (type) {
    case food:   required_role_id = 3; break;
    case stick:  required_role_id = 2; break;
    case body:   required_role_id = 6; break;
    case trash: required_role_id = 6; break;

    }
    if (required_role_id != -1) {
        Ant* free_ant = find_free_ant(resource, required_role_id);
        if (free_ant)
            free_ant->set_target(resource->get_posit());
    }
}

Ant* Informers::find_free_ant(Resource* resource, int role_id) {
    auto& ants = ants_by_role[role_id];
    Ant* nearest = nullptr;
    float min_dist = 0.0f;
    Vector2f res_pos(resource->get_posit().x, resource->get_posit().y);
    bool first_found = false;
    for (Ant* ant : ants) {
        if (!ant->has_valid_target()) {
            Vector2f ant_pos(ant->get_pos().x, ant->get_pos().y);
            float dx = ant_pos.x - res_pos.x;
            float dy = ant_pos.y - res_pos.y;
            float dist =  sqrt(dx * dx + dy * dy);

            if (!first_found || dist < min_dist) {
                first_found = true;
                min_dist = dist;
                nearest = ant;
            }
        }
    }
    return nearest;
}

void Informers::clear_info(Resource* resource) {
    unsubscribe_resource(resource);
}

void Informers::add_resource(Resource* resource) {
    int required_role_id = -1;
    int type = resource->get_type();
    switch (type) {
    case food:   required_role_id = 3; break;
    case stick:  required_role_id = 2; break;
    case body:
    case trash:  required_role_id = 6; break;
    }
    if (required_role_id != -1) {
        Ant* free_ant = find_free_ant(resource, required_role_id);
        if (free_ant)
            free_ant->set_target(resource->get_posit());
    }
}
