//#include "Ants.h"
//
//// Реализация методов для ролей с использованием геометрических фигур
//
//// --- Baby ---
//void Baby::work(Ant& ant) {
//    // Простой пример: муравей-ребёнок растёт
//    cout << "Baby is growing" << endl;
//}
//
//void Baby::role_up(Ant& ant) {
//    ant.set_role(unique_ptr<Role>(new Sitter()));
//    cout << "Baby has grown into a Sitter" << endl;
//}
//
//// --- Sitter ---
//void Sitter::work(Ant& ant) {
//    cout << "Sitter is taking care of babies" << endl;
//
//    // Если рядом обнаружен враг, оповещаем муравейник
//    Anthill* home = ant.get_home();
//    const vector<Enemy>& enemies = home->get_enemies();
//
//    for (const Enemy& enemy : enemies) {
//        if (enemy.get_position().distance(home->get_position()) < 50.0f) {
//            home->get_enemy_informer().notify(enemy.get_position());
//            cout << "Sitter warns about enemy near anthill!" << endl;
//            break;
//        }
//    }
//}
//
//void Sitter::role_up(Ant& ant) {
//    int n = rand() % 100;
//
//    ant.unsubscribe_from_informer(enemy_info);
//
//    if (n < 50) {
//        ant.set_role(unique_ptr<Role>(new Collector()));
//        ant.subscribe_to_informer(food_info);
//        cout << "Sitter has become a Collector" << endl;
//    }
//    else {
//        ant.set_role(unique_ptr<Role>(new Builder()));
//        ant.subscribe_to_informer(stick_info);
//        cout << "Sitter has become a Builder" << endl;
//    }
//}
//
//// --- Collector ---
//void Collector::work(Ant& ant) {
//    Anthill* home = ant.get_home();
//    Position ant_pos = ant.get_position();
//
//    if (has_food) {
//        if (ant_pos.distance(home->get_position()) < 30.0f) {
//            home->add_food(1);
//            has_food = false;
//            ant.set_returning_home(false);
//            ant.clear_target();
//            cout << "Collector delivered food to anthill" << endl;
//            ant.leave_pheromone(food_info);
//        }
//        else {
//            ant.set_returning_home(true);
//            ant.set_target(home->get_position());
//            cout << "Collector is carrying food to anthill" << endl;
//        }
//    }
//    else {
//        const vector<Resource>& resources = home->get_resources();
//        for (const Resource& resource : resources) {
//            if (resource.get_type() == food && !resource.is_collected() &&
//                ant.can_see(resource, 50.0f)) {
//
//                ant.set_target(resource.get_position());
//                cout << "Collector found food" << endl;
//
//                if (resource.get_size() > 1) {
//                    home->get_food_informer().notify(resource.get_position(), resource.get_size());
//                    cout << "Collector informs others about large food source!" << endl;
//                }
//                if (ant_pos.distance(resource.get_position()) < 5.0f) {
//                    has_food = true;
//                    cout << "Collector picked up food" << endl;
//                    ant.leave_pheromone(food_info);
//                    break;
//                }
//            }
//        }
//        if (!has_food && !ant.has_target) {
//            const vector<Pheromone>& pheromones = home->get_pheromones();
//            for (const Pheromone& pheromone : pheromones) {
//                if (pheromone.get_type() == food_info && pheromone.is_active() &&
//                    ant.can_see(pheromone, 60.0f)) {
//                    ant.set_target(pheromone.get_position());
//                    cout << "Collector follows food pheromone" << endl;
//                    break;
//                }
//            }
//        }
//    }
//}
//
//void Collector::role_up(Ant& ant) {
//    int h = ant.get_max_hp();
//    ant.unsubscribe_from_informer(food_info);
//    if (h >= 10) {
//        ant.set_role(unique_ptr<Role>(new Soldier()));
//        ant.subscribe_to_informer(enemy_info);
//        cout << "Collector has become a Soldier" << endl;
//    }
//    else {
//        ant.set_role(unique_ptr<Role>(new Shepherd()));
//        cout << "Collector has become a Shepherd" << endl;
//    }
//}
//
//// --- Builder ---
//void Builder::work(Ant& ant) {
//    Anthill* home = ant.get_home();
//    Position ant_pos = ant.get_position();
//
//    if (has_stick) {
//        if (ant_pos.distance(home->get_position()) < 30.0f) {
//            home->add_sticks(1);
//            has_stick = false;
//            ant.set_returning_home(false);
//            ant.clear_target();
//            cout << "Builder delivered stick to anthill" << endl;
//            ant.leave_pheromone(stick_info);
//        }
//        else {
//            ant.set_returning_home(true);
//            ant.set_target(home->get_position());
//            cout << "Builder is carrying stick to anthill" << endl;
//        }
//    }
//    else {
//        const vector<Resource>& resources = home->get_resources();
//        for (const Resource& resource : resources) {
//            if (resource.get_type() == stick && !resource.is_collected() &&
//                ant.can_see(resource, 50.0f)) {
//                ant.set_target(resource.get_position());
//                cout << "Builder found stick" << endl;
//                if (resource.get_size() > 1) {
//                    home->get_stick_informer().notify(resource.get_position(), resource.get_size());
//                    cout << "Builder informs others about large stick!" << endl;
//                }
//                if (ant_pos.distance(resource.get_position()) < 5.0f) {
//                    has_stick = true;
//                    cout << "Builder picked up stick" << endl;
//                    ant.leave_pheromone(stick_info);
//                    break;
//                }
//            }
//        }
//        if (!has_stick && !ant.has_target) {
//            const vector<Pheromone>& pheromones = home->get_pheromones();
//            for (const Pheromone& pheromone : pheromones) {
//                if (pheromone.get_type() == stick_info && pheromone.is_active() &&
//                    ant.can_see(pheromone, 60.0f)) {
//                    ant.set_target(pheromone.get_position());
//                    cout << "Builder follows stick pheromone" << endl;
//                    break;
//                }
//            }
//        }
//    }
//}
//
//void Builder::role_up(Ant& ant) {
//    int h = ant.get_max_hp();
//    ant.unsubscribe_from_informer(stick_info);
//    if (h >= 10) {
//        ant.set_role(unique_ptr<Role>(new Soldier()));
//        ant.subscribe_to_informer(enemy_info);
//        cout << "Builder has become a Soldier" << endl;
//    }
//    else {
//        ant.set_role(unique_ptr<Role>(new Shepherd()));
//        cout << "Builder has become a Shepherd" << endl;
//    }
//}
//
//// --- Shepherd ---
//void Shepherd::work(Ant& ant) {
//    cout << "Shepherd is guiding ants to work efficiently" << endl;
//    Anthill* home = ant.get_home();
//    Position ant_pos = ant.get_position();
//    const vector<Resource>& resources = home->get_resources();
//    for (const Resource& resource : resources) {
//        if (resource.get_type() == aphid && ant.can_see(resource, 50.0f)) {
//            ant.set_target(resource.get_position());
//            cout << "Shepherd found aphid" << endl;
//            if (ant_pos.distance(resource.get_position()) < 10.0f) {
//                cout << "Shepherd is caring for aphid" << endl;
//                ant.leave_pheromone(food_info);
//                break;
//            }
//        }
//    }
//}
//
//void Shepherd::role_up(Ant& ant) {
//    ant.set_role(unique_ptr<Role>(new Cleaner()));
//    cout << "Shepherd has become a Cleaner" << endl;
//}
//
//// --- Soldier ---
//void Soldier::work(Ant& ant) {
//    Anthill* home = ant.get_home();
//    Position ant_pos = ant.get_position();
//
//    if (is_fighting) {
//        cout << "Soldier is fighting an enemy" << endl;
//        return;
//    }
//
//    const vector<Enemy>& enemies = home->get_enemies();
//    for (size_t i = 0; i < enemies.size(); i++) {
//        const Enemy& enemy = enemies[i];
//        if (!enemy.isDead() && ant.can_see(enemy, 60.0f)) {
//            ant.set_target(enemy.get_position());
//            cout << "Soldier found an enemy!" << endl;
//            home->get_enemy_informer().notify(enemy.get_position());
//            if (ant_pos.distance(enemy.get_position()) < 10.0f) {
//                is_fighting = true;
//                cout << "Soldier is attacking enemy with damage " << damage << endl;
//                ant.leave_pheromone(enemy_info);
//                break;
//            }
//        }
//    }
//
//    if (!is_fighting && !ant.has_target) {
//        const vector<Pheromone>& pheromones = home->get_pheromones();
//        for (const Pheromone& pheromone : pheromones) {
//            if (pheromone.get_type() == enemy_info && pheromone.is_active() &&
//                ant.can_see(pheromone, 80.0f)) {
//                ant.set_target(pheromone.get_position());
//                cout << "Soldier follows enemy pheromone" << endl;
//                break;
//            }
//        }
//    }
//    if (!is_fighting && !ant.has_target) {
//        if (rand() % 100 < 5) { // 5% шанс патрулировать
//            Position anthill_pos = home->get_position();
//            float patrol_radius = 100.0f + (rand() % 50);
//            float angle = (rand() % 360) * 3.14159f / 180.0f;
//            Position patrol_pos;
//            patrol_pos.x = anthill_pos.x + cos(angle) * patrol_radius;
//            patrol_pos.y = anthill_pos.y + sin(angle) * patrol_radius;
//            ant.set_target(patrol_pos);
//            cout << "Soldier is patrolling" << endl;
//        }
//    }
//}
//
//void Soldier::role_up(Ant& ant) {
//    ant.unsubscribe_from_informer(enemy_info);
//    ant.set_role(unique_ptr<Role>(new Cleaner()));
//    cout << "Soldier has become a Cleaner" << endl;
//}
//
//// --- Cleaner ---
//void Cleaner::work(Ant& ant) {
//    Anthill* home = ant.get_home();
//    Position ant_pos = ant.get_position();
//
//    if (carrying_trash) {
//        if (ant_pos.distance(home->get_position()) < 30.0f) {
//            carrying_trash = false;
//            ant.set_returning_home(false);
//            ant.clear_target();
//            cout << "Cleaner delivered trash to anthill for recycling" << endl;
//        }
//        else {
//            ant.set_returning_home(true);
//            ant.set_target(home->get_position());
//            cout << "Cleaner is carrying trash to anthill" << endl;
//        }
//    }
//    else {
//        const vector<Resource>& resources = home->get_resources();
//        for (const Resource& resource : resources) {
//            if ((resource.get_type() == body || resource.get_type() == trash) &&
//                !resource.is_collected() && ant.can_see(resource, 50.0f)) {
//                ant.set_target(resource.get_position());
//                cout << "Cleaner found " << (resource.get_type() == body ? "body" : "trash") << endl;
//                if (ant_pos.distance(resource.get_position()) < 5.0f) {
//                    carrying_trash = true;
//                    cout << "Cleaner picked up " << (resource.get_type() == body ? "body" : "trash") << endl;
//                    break;
//                }
//            }
//        }
//    }
//
//    const vector<Pheromone>& pheromones = home->get_pheromones();
//    for (const Pheromone& pheromone : pheromones) {
//        if (pheromone.is_active() && pheromone.get_intensity() < 20 &&
//            ant.can_see(pheromone, 20.0f) && !carrying_trash) {
//            ant.set_target(pheromone.get_position());
//            cout << "Cleaner is cleaning old pheromone" << endl;
//            break;
//        }
//    }
//}
//
//void Cleaner::role_up(Ant& ant) {
//    ant.set_role(unique_ptr<Role>(new Sitter()));
//    cout << "Cleaner has become a Sitter again" << endl;
//}
//
//// --- Методы класса Ant ---
//Ant::Ant(Anthill* _home, Position start_pos)
//    : hp(1), max_hp(1), age(0), speed(3),
//    charact(passive), role(nullptr), pos(start_pos), home(_home),
//    carrying_resource(false), resource_type(no_res),
//    current_dir(none), returning_home(false), has_target(false),
//    vision_radius(50.0f), is_dead(false), tick_counter(0)
//{
//    // Изначально назначаем роль Baby
//    role = make_unique<Baby>();
//    // Фигура для тела уже настроена в конструкторе (при необходимости можно вызвать setup_shapes)
//}
//
//void Ant::update() {
//    if (is_dead) return;
//    tick_counter++;
//    if (tick_counter % 100 == 0) {
//        age_up();
//    }
//    work();
//    move();
//}
//
//void Ant::work() {
//    if (role && !is_dead) {
//        role->work(*this);
//    }
//}
//
//void Ant::move() {
//    if (is_dead) return;
//
//    if (has_target) {
//        float dx = target.x - pos.x;
//        float dy = target.y - pos.y;
//        float distance = sqrt(dx * dx + dy * dy);
//        if (distance < 3.0f) {
//            has_target = false;
//            return;
//        }
//        dx /= distance;
//        dy /= distance;
//        pos.x += dx * speed;
//        pos.y += dy * speed;
//    }
//    else {
//        if (rand() % 100 < 5) {
//            current_dir = static_cast<direction>(rand() % 4);
//        }
//        switch (current_dir) {
//        case direction::up:    pos.y -= speed * 0.5f; break;
//        case direction::down:  pos.y += speed * 0.5f; break;
//        case direction::left:  pos.x -= speed * 0.5f; break;
//        case direction::right: pos.x += speed * 0.5f; break;
//        default: break;
//        }
//        const float border = 20.0f;
//        if (pos.x < border) { pos.x = border; current_dir = direction::right; }
//        if (pos.y < border) { pos.y = border; current_dir = direction::down; }
//        if (pos.x > 800 - border) { pos.x = 800 - border; current_dir = direction::left; }
//        if (pos.y > 600 - border) { pos.y = 600 - border; current_dir = direction::up; }
//    }
//    // Обновляем положение геометрической фигуры муравья
//    get_body().setPosition(pos.x, pos.y);
//}
//
//void Ant::age_up() {
//    age++;
//    if (role) {
//        const char* role_name = role->get_role_name();
//        if (strcmp(role_name, "Baby") == 0) max_hp = baby;
//        else if (strcmp(role_name, "Sitter") == 0) max_hp = sitter;
//        else if (strcmp(role_name, "Collector") == 0) max_hp = collector;
//        else if (strcmp(role_name, "Builder") == 0) max_hp = builder;
//        else if (strcmp(role_name, "Soldier") == 0) max_hp = soldier;
//        else if (strcmp(role_name, "Shepherd") == 0) max_hp = shepherd;
//        else if (strcmp(role_name, "Cleaner") == 0) max_hp = cleaner;
//        hp = max_hp;
//    }
//    if (age % 5 == 0 && role) {
//        role->role_up(*this);
//    }
//}
//
//void Ant::take_damage(int damage) {
//    hp -= damage;
//    if (hp <= 0) {
//        kill();
//    }
//}
//
//void Ant::set_role(unique_ptr<Role> new_role) {
//    role = std::move(new_role);
//}
//
//void Ant::subscribe_to_informer(info_type type) {
//    switch (type) {
//    case food_info:
//        home->get_food_informer().add_subscriber(this);
//        break;
//    case stick_info:
//        home->get_stick_informer().add_subscriber(this);
//        break;
//    case enemy_info:
//        home->get_enemy_informer().add_subscriber(this);
//        break;
//    }
//}
//
//void Ant::unsubscribe_from_informer(info_type type) {
//    switch (type) {
//    case food_info:
//        home->get_food_informer().remove_subscriber(this);
//        break;
//    case stick_info:
//        home->get_stick_informer().remove_subscriber(this);
//        break;
//    case enemy_info:
//        home->get_enemy_informer().remove_subscriber(this);
//        break;
//    }
//}
//
//void Ant::food_found(const Position& food_pos, int size) {
//    const char* role_name = get_role_name();
//    if (strcmp(role_name, "Collector") == 0 && !has_target && !is_carrying_resource()) {
//        set_target(food_pos);
//        cout << "Ant received info about food at (" << food_pos.x << "," << food_pos.y << ") with size " << size << endl;
//    }
//}
//
//void Ant::stick_found(const Position& stick_pos, int size) {
//    const char* role_name = get_role_name();
//    if (strcmp(role_name, "Builder") == 0 && !has_target && !is_carrying_resource()) {
//        set_target(stick_pos);
//        cout << "Ant received info about stick at (" << stick_pos.x << "," << stick_pos.y << ") with size " << size << endl;
//    }
//}
//
//void Ant::enemy_spotted(const Position& enemy_pos) {
//    const char* role_name = get_role_name();
//    if (strcmp(role_name, "Soldier") == 0 && !has_target) {
//        set_target(enemy_pos);
//        cout << "Ant received info about enemy at (" << enemy_pos.x << "," << enemy_pos.y << ")" << endl;
//    }
//}
//
//void Ant::pick_resource(res_type type) {
//    carrying_resource = true;
//    resource_type = type;
//}
//
//void Ant::drop_resource() {
//    carrying_resource = false;
//    resource_type = no_res;
//}
//
//void Ant::attack(Enemy* enemy) {
//    int attack_power = 1;
//    const char* role_name = get_role_name();
//    if (strcmp(role_name, "Soldier") == 0) {
//        Soldier* soldier_role = dynamic_cast<Soldier*>(role.get());
//        if (soldier_role) {
//            attack_power = soldier_role->get_damage();
//        }
//    }
//    cout << "Ant attacks enemy with power " << attack_power << endl;
//    enemy->take_damage(attack_power);
//}
//
//void Ant::defend() {
//    cout << "Ant defends itself" << endl;
//}
//
//void Ant::leave_pheromone(info_type type) {
//    Pheromone new_pheromone(pos, type);
//    home->register_pheromone(new_pheromone);
//    cout << "Ant left pheromone of type " << type << " at position (" << pos.x << "," << pos.y << ")" << endl;
//}
//
//// --- Методы класса Anthill ---
//Anthill::Anthill(Position pos)
//    : level(1), food_count(50), stick_count(50), capacity(20),
//    position(pos), shape(30.f),
//    food_informer(food_info), stick_informer(stick_info), enemy_informer(enemy_info),
//    food_consumption_timer(0), spawn_timer(0), resource_spawn_timer(0), enemy_spawn_timer(0)
//{
//    for (int i = 0; i < 10; i++) {
//        add_ant();
//    }
//}
//
//void Anthill::update() {
//    for (auto& ant : colony) {
//        ant->update();
//    }
//    update_pheromones();
//    update_resources();
//    update_enemies();
//    remove_dead_ants();
//    food_consumption_timer++;
//    if (food_consumption_timer >= 200) {
//        food_consumption_timer = 0;
//        consume_food();
//    }
//    spawn_timer++;
//    if (spawn_timer >= 300 && food_count > 10 && colony.size() < capacity) {
//        spawn_timer = 0;
//        add_ant();
//        food_count -= 10;
//    }
//    resource_spawn_timer++;
//    if (resource_spawn_timer >= 500) {
//        resource_spawn_timer = 0;
//        for (int i = 0; i < 5; i++) {
//            float x = (rand() % 700) + 50;
//            float y = (rand() % 500) + 50;
//            int type_roll = rand() % 100;
//            res_type type;
//            if (type_roll < 50) {
//                type = food;
//            }
//            else if (type_roll < 90) {
//                type = stick;
//            }
//            else {
//                type = aphid;
//            }
//            int size = rand() % 5 + 1;
//            Resource new_resource(type, size, Position(x, y));
//            register_resource(new_resource);
//        }
//    }
//    enemy_spawn_timer++;
//    if (enemy_spawn_timer >= 800) {
//        enemy_spawn_timer = 0;
//        if (rand() % 100 < 20 + level * 5) {
//            float x = (rand() % 700) + 50;
//            float y = (rand() % 500) + 50;
//            Position enemy_pos(x, y);
//            while (enemy_pos.distance(position) < 150.0f) {
//                x = (rand() % 700) + 50;
//                y = (rand() % 500) + 50;
//                enemy_pos = Position(x, y);
//            }
//            Enemy new_enemy(enemy_pos);
//            register_enemy(new_enemy);
//        }
//    }
//    leveling();
//}
//
//void Anthill::add_ant() {
//    if (colony.size() < capacity) {
//        colony.push_back(make_unique<Ant>(this, position));
//        cout << "New ant born in anthill" << endl;
//    }
//}
//
//void Anthill::remove_dead_ants() {
//    colony.erase(
//        std::remove_if(colony.begin(), colony.end(),
//            [](const unique_ptr<Ant>& ant_ptr) {
//                return ant_ptr->has_died();
//            }),
//        colony.end()
//    );
//}
//
//void Anthill::leveling() {
//    int required_sticks = level * 50;
//    if (stick_count >= required_sticks) {
//        level++;
//        stick_count -= required_sticks;
//        capacity = 10 + level * 10;
//        shape.setRadius(30.f + 10.f * level);
//        shape.setPosition(position.x - shape.getRadius(), position.y - shape.getRadius());
//        cout << "Anthill upgraded to level " << level << "! New capacity: " << capacity << endl;
//    }
//}
//
//void Anthill::add_food(int amount) {
//    food_count += amount;
//    cout << "Added " << amount << " food. Total food: " << food_count << endl;
//}
//
//void Anthill::add_sticks(int amount) {
//    stick_count += amount;
//    cout << "Added " << amount << " sticks. Total sticks: " << stick_count << endl;
//}
//
//void Anthill::consume_food() {
//    int required_food = colony.size() / 2 + 1;
//    if (food_count >= required_food) {
//        food_count -= required_food;
//        cout << "Colony consumed " << required_food << " food. Remaining: " << food_count << endl;
//    }
//    else {
//        cout << "Colony is starving! Not enough food!" << endl;
//        for (auto& ant : colony) {
//            ant->take_damage(1);
//        }
//    }
//}
//
//void Anthill::register_pheromone(Pheromone pheromone) {
//    pheromones.push_back(pheromone);
//}
//
//void Anthill::update_pheromones() {
//    for (auto& pheromone : pheromones) {
//        pheromone.update();
//    }
//    pheromones.erase(
//        std::remove_if(pheromones.begin(), pheromones.end(),
//            [](const Pheromone& p) { return !p.is_active(); }),
//        pheromones.end()
//    );
//}
//
//void Anthill::register_resource(Resource resource) {
//    resources.push_back(resource);
//}
//
//void Anthill::update_resources() {
//    for (auto& resource : resources) {
//        if (resource.get_type() == aphid) {
//            if (rand() % 100 < 5) {
//                Position aphid_pos = resource.get_position();
//                Position food_pos(aphid_pos.x + (rand() % 20 - 10), aphid_pos.y + (rand() % 20 - 10));
//                Resource new_food(food, 1, food_pos);
//                resources.push_back(new_food);
//            }
//        }
//    }
//    resources.erase(
//        std::remove_if(resources.begin(), resources.end(),
//            [](const Resource& r) { return r.is_collected() && r.get_size() <= 0; }),
//        resources.end()
//    );
//}
//
//void Anthill::register_enemy(Enemy enemy) {
//    enemies.push_back(enemy);
//    cout << "New enemy spotted near the anthill!" << endl;
//    enemy_informer.notify(enemy.get_position());
//}
//
//void Anthill::update_enemies() {
//    for (auto& enemy : enemies) {
//        if (!enemy.isDead()) {
//            enemy.move();
//            Position enemy_pos = enemy.get_position();
//            for (auto& ant : colony) {
//                if (!ant->has_died() && enemy_pos.distance(ant->get_position()) < 15.0f) {
//                    ant->take_damage(enemy.get_damage());
//                    cout << "Enemy attacks ant!" << endl;
//                    ant->defend();
//                    if (strcmp(ant->get_role_name(), "Soldier") == 0) {
//                        enemy.take_damage(3);
//                        cout << "Soldier counterattacks enemy!" << endl;
//                    }
//                    else {
//                        enemy.take_damage(1);
//                        cout << "Ant tries to defend itself!" << endl;
//                    }
//                    break;
//                }
//            }
//        }
//    }
//    for (auto it = enemies.begin(); it != enemies.end();) {
//        if (it->isDead()) {
//            Position body_pos = it->get_position();
//            Resource body_resource(body, 3, body_pos);
//            resources.push_back(body_resource);
//            cout << "Enemy defeated! Its body can be processed by cleaners." << endl;
//            it = enemies.erase(it);
//        }
//        else {
//            ++it;
//        }
//    }
//}
