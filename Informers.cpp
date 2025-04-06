#include "Informers.h"
void Informer::add_ant(Ant* ant) {
    ants.push_back(ant);  
}
void Informer::notify(info_type type, Position pos) {
    for (auto& ant : ants) {
        int role_id = ant->get_role();  

        if (type == food_info && role_id == 2) {  // Если роль Collector 
            ant->set_target(pos);  // Collector идет собирать еду
        }
        else if (type == stick_info && role_id == 3) {  // Если роль Builder 
            ant->set_target(pos);  // Builder идет собирать палки
        }
        else if (type == enemy && role_id == 4) {  // Если роль Soldier 
            ant->set_target(pos);  // Soldier идет сражаться с врагом
        }
    }
}

