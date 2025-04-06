//#pragma once
//#include <iostream>
//#include <vector>
//#include <random>
//#include <memory>
//#include <cmath>
//#include <algorithm>
//#include <list>
//#include <SFML/Graphics.hpp>
//using namespace std;
//
//enum roles { baby = 1, sitter = 3, collector = 5, builder = 5, soldier = 7, shepherd = 3, cleaner = 3 };
//enum character { passive, aggressive };
//enum info_type { food_info, stick_info, enemy_info };
//enum res_type { no_res, food, stick, body, trash, aphid };
//enum direction { up, down, left, right, none };
//
//// Предварительные объявления классов
//class Ant;
//class Anthill;
//class Pheromone;
//class Position;
//
//// Класс позиции
//class Position {
//public:
//    float x, y;
//    Position(float x_ = 0, float y_ = 0) : x(x_), y(y_) {}
//    float distance(const Position& other) const { return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2)); }
//    bool operator==(const Position& other) const { return x == other.x && y == other.y; }
//};
//
//// Абстрактный класс для ролей
//class Role {
//public:
//    virtual ~Role() = default;
//    virtual void role_up(Ant& ant) = 0;
//    virtual void work(Ant& ant) = 0;
//    virtual const char* get_role_name() const = 0;
//};
//
//// Класс "Ресурс" теперь использует геометрическую фигуру вместо спрайта
//class Resource {
//private:
//    res_type type;
//    int size;
//    Position pos;
//    sf::CircleShape shape;  // Геометрическая фигура для отображения ресурса
//    bool collected;
//
//public:
//    Resource(res_type type_ = no_res, int size_ = 1, Position pos_ = Position())
//        : type(type_), size(size_), pos(pos_), collected(false)
//    {
//        setup_shape();
//    }
//
//    res_type get_type() const { return type; }
//    int get_size() const { return size; }
//    Position get_position() const { return pos; }
//    bool is_collected() const { return collected; }
//    void set_collected(bool value) { collected = value; }
//    void decrease_size() { if (size > 0) size--; setup_shape(); }
//
//   const sf::CircleShape& get_shape() const { return shape; }
//
//    // Настройка геометрической фигуры в зависимости от типа и размера ресурса
//    void setup_shape() {
//        float radius = 3.0f + size; // базовый радиус зависит от размера ресурса
//        shape.setRadius(radius);
//        shape.setOrigin(radius, radius);
//        shape.setPosition(pos.x, pos.y);
//
//        // Цвет фигуры в зависимости от типа ресурса
//        switch (type) {
//        case food:
//            shape.setFillColor(sf::Color::Green);
//            break;
//        case stick:
//            shape.setFillColor(sf::Color(139, 69, 19)); // коричневый
//            break;
//        case body:
//            shape.setFillColor(sf::Color(128, 128, 128)); // серый
//            break;
//        case trash:
//            shape.setFillColor(sf::Color(169, 169, 169)); // темно-серый
//            break;
//        case aphid:
//            shape.setFillColor(sf::Color(150, 75, 0)); // особый цвет для тли
//            break;
//        default:
//            shape.setFillColor(sf::Color::Yellow);
//            break;
//        }
//    }
//};
//
//// Класс "Афида (тля)"
//class Aphid : public Resource {
//private:
//    int milk_count;
//    direction cur_dir;
//    int move_timer;
//    // Для наглядности можно добавить дополнительные геометрические элементы,
//    // например, маленькие кружки для "усиков", но здесь оставим только основную фигуру
//
//public:
//    Aphid(Position _pos = Position()) : Resource(aphid, 1, _pos), milk_count(0), cur_dir(none), move_timer(0) {}
//
//    void produce_milk() {
//        milk_count++;
//        if (milk_count >= 10) {
//            milk_count = 0;
//            // Здесь можно создать новый ресурс пищи рядом с тлей
//        }
//    }
//
//    void move() {
//        // Случайное движение тли
//        if (move_timer <= 0) {
//            cur_dir = static_cast<direction>(rand() % 4);
//            move_timer = rand() % 50 + 10;
//        }
//        float speed = 0.2f;
//        Position pos = get_position();
//        switch (cur_dir) {
//        case direction::up:    pos.y -= speed; break;
//        case direction::down:  pos.y += speed; break;
//        case direction::left:  pos.x -= speed; break;
//        case direction::right: pos.x += speed; break;
//        default: break;
//        }
//        // Обновляем позицию ресурса
//        // Для обновления позиции сохраняем её в объекте и изменяем положение фигуры
//        // (если в дальнейшем потребуется анимация, можно добавить дополнительную логику)
//        // Здесь предполагаем, что объект Resource имеет возможность обновить свою позицию:
//        // (например, через дополнительный метод set_position)
//        // Для простоты заменим внутреннее поле pos и перерисуем фигуру:
//        /**(const_cast<Position*>(&get_position())) = pos;*/
//        pos = get_position();
//        sf::CircleShape temp_shape = get_shape(); // Создаем копию
//        temp_shape.setPosition(pos.x, pos.y);
//    }
//};
//
//// Класс "Враг" теперь использует ConvexShape для отображения
//class Enemy {
//private:
//    int hp, damage, speed;
//    Position pos;
//    sf::ConvexShape shape; // Геометрическая фигура для врага
//    bool is_dead;
//    direction cur_dir;
//    int move_timer;
//
//public:
//    Enemy(Position _pos = Position()) : pos(_pos), is_dead(false), cur_dir(none), move_timer(0) {
//        hp = rand() % 6 + 10;
//        damage = rand() % 3 + 3;
//        speed = rand() % 3 + 3;
//        setup_shape();
//    }
//
//    void setup_shape() {
//        // Создадим треугольник для врага
//        shape.setPointCount(3);
//        float size = 5.0f + hp * 0.5f;
//        shape.setPoint(0, sf::Vector2f(0, -size));
//        shape.setPoint(1, sf::Vector2f(-size, size));
//        shape.setPoint(2, sf::Vector2f(size, size));
//        shape.setOrigin(0, 0);
//        shape.setFillColor(sf::Color::Red);
//        shape.setPosition(pos.x, pos.y);
//    }
//
//    int get_hp() const { return hp; }
//    int get_damage() const { return damage; }
//    Position get_position() const { return pos; }
//    bool isDead() const { return is_dead; }
//
//    void take_damage(int dmg) {
//        hp -= dmg;
//        if (hp <= 0)
//            is_dead = true;
//        setup_shape();
//    }
//    void attack() {
//        cout << "Enemy attacks with damage " << damage << endl;
//    }
//    void shock() {
//        cout << "Enemy shocks with speed " << speed << endl;
//    }
//    const sf::ConvexShape& get_shape() const { return shape; }
//
//    void move() {
//        // Случайное движение врага
//        if (move_timer <= 0) {
//            cur_dir = static_cast<direction>(rand() % 4);
//            move_timer = rand() % 30 + 10;
//        }
//        float move_speed = speed * 0.2f;
//        switch (cur_dir) {
//        case direction::up:    pos.y -= move_speed; break;
//        case direction::down:  pos.y += move_speed; break;
//        case direction::left:  pos.x -= move_speed; break;
//        case direction::right: pos.x += move_speed; break;
//        default: break;
//        }
//        shape.setPosition(pos.x, pos.y);
//        move_timer--;
//    }
//};
//
//// Класс феромона (с использованием CircleShape для наглядности)
//class Pheromone {
//private:
//    Position pos;
//    info_type type;
//    int intensity;
//    int lifetime;
//    sf::CircleShape shape;
//
//public:
//    Pheromone(Position _pos, info_type _type, int _intensity = 100, int _lifetime = 500)
//        : pos(_pos), type(_type), intensity(_intensity), lifetime(_lifetime)
//    {
//        shape = sf::CircleShape(2.0f);
//        switch (type) {
//        case food_info:
//            shape.setFillColor(sf::Color(0, 255, 0, 100));
//            break;
//        case stick_info:
//            shape.setFillColor(sf::Color(139, 69, 19, 100));
//            break;
//        case enemy_info:
//            shape.setFillColor(sf::Color(255, 0, 0, 100));
//            break;
//        }
//        shape.setPosition(pos.x, pos.y);
//    }
//
//    Position get_position() const { return pos; }
//    info_type get_type() const { return type; }
//    int get_intensity() const { return intensity; }
//    bool is_active() const { return lifetime > 0; }
//
//    void update() {
//        lifetime--;
//        intensity = max(0, intensity - 1);
//        sf::Color color = shape.getFillColor();
//        color.a = static_cast<sf::Uint8>(100.0f * intensity / 100.0f);
//        shape.setFillColor(color);
//    }
//
//    sf::CircleShape& get_shape() { return shape; }
//};
//
//// Конкретные роли муравьев
//class Baby : public Role {
//public:
//    void work(Ant& ant) override;
//    void role_up(Ant& ant) override;
//    const char* get_role_name() const override { return "Baby"; }
//};
//
//class Sitter : public Role {
//public:
//    void work(Ant& ant) override;
//    void role_up(Ant& ant) override;
//    const char* get_role_name() const override { return "Sitter"; }
//};
//
//class Collector : public Role {
//private:
//    bool has_food;
//public:
//    Collector() : Role(), has_food(false) {}
//    void work(Ant& ant) override;
//    void role_up(Ant& ant) override;
//    const char* get_role_name() const override { return "Collector"; }
//    bool is_carrying_food() const { return has_food; }
//    void set_has_food(bool value) { has_food = value; }
//};
//
//class Builder : public Role {
//private:
//    bool has_stick;
//public:
//    Builder() : Role(), has_stick(false) {}
//    void work(Ant& ant) override;
//    void role_up(Ant& ant) override;
//    const char* get_role_name() const override { return "Builder"; }
//    bool is_carrying_stick() const { return has_stick; }
//    void set_has_stick(bool value) { has_stick = value; }
//};
//
//class Shepherd : public Role {
//public:
//    void work(Ant& ant) override;
//    void role_up(Ant& ant) override;
//    const char* get_role_name() const override { return "Shepherd"; }
//};
//
//class Soldier : public Role {
//private:
//    int damage;
//    bool is_fighting;
//public:
//    Soldier() : damage(rand() % 3 + 3), is_fighting(false) {}
//    void work(Ant& ant) override;
//    void role_up(Ant& ant) override;
//    const char* get_role_name() const override { return "Soldier"; }
//    int get_damage() const { return damage; }
//    bool get_is_fighting() const { return is_fighting; }
//    void set_is_fighting(bool value) { is_fighting = value; }
//};
//
//class Cleaner : public Role {
//private:
//    bool carrying_trash;
//public:
//    Cleaner() : carrying_trash(false) {}
//    void work(Ant& ant) override;
//    void role_up(Ant& ant) override;
//    const char* get_role_name() const override { return "Cleaner"; }
//    bool is_carrying_trash() const { return carrying_trash; }
//    void set_carrying_trash(bool value) { carrying_trash = value; }
//};
//
//// Шаблонный класс информера
//template<typename T>
//class Informer {
//public:
//    Informer(info_type _type) : type(_type) {}
//    void add_subscriber(T* ant) {
//        subscribers.push_back(ant);
//    }
//    void remove_subscriber(T* ant) {
//        subscribers.erase(remove(subscribers.begin(), subscribers.end(), ant), subscribers.end());
//    }
//    void notify(const Position& pos, int size = 1) {
//        for (auto* ant : subscribers) {
//            switch (type) {
//            case food_info:
//                ant->food_found(pos, size);
//                break;
//            case stick_info:
//                ant->stick_found(pos, size);
//                break;
//            case enemy_info:
//                ant->enemy_spotted(pos);
//                break;
//            }
//        }
//    }
//private:
//    info_type type;
//    vector<T*> subscribers;
//};
//
//// Класс "Муравей" с использованием геометрической фигуры (например, CircleShape) для визуализации
//class Ant {
//private:
//    int hp, max_hp, age, speed;
//    character charact;
//    unique_ptr<Role> role;
//    Position pos;
//    Anthill* home;
//    sf::CircleShape body;  // Геометрическая фигура для тела муравья
//
//    // Ресурсы
//    bool carrying_resource;
//    res_type resource_type;
//
//    // Движение
//    direction current_dir;
//    bool returning_home;
//    Position target;
//
//    // "Зрение"
//    float vision_radius;
//
//    // Индикаторы активности
//    bool is_dead;
//    int tick_counter;
//
//public:
//    Ant(Anthill* _home, Position start_pos = Position());
//    ~Ant() = default;
//    // Запрещаем копирование
//    Ant(const Ant&) = delete;
//    Ant& operator=(const Ant&) = delete;
//    // Разрешаем перемещение
//    Ant(Ant&&) = default;
//    Ant& operator=(Ant&&) = default;
//
//    // Основные методы
//    void update();
//    void work();
//    void move();
//    void age_up();
//    void take_damage(int damage);
//
//    // Методы для смены ролей
//    void set_role(unique_ptr<Role> new_role);
//    const char* get_role_name() const { return role ? role->get_role_name() : "No Role"; }
//
//    // Подписка на информеры
//    void subscribe_to_informer(info_type type);
//    void unsubscribe_from_informer(info_type type);
//
//    // Методы получения информации
//    void food_found(const Position& food_pos, int size);
//    void stick_found(const Position& stick_pos, int size);
//    void enemy_spotted(const Position& enemy_pos);
//
//    // Взаимодействие с ресурсами
//    void pick_resource(res_type type);
//    void drop_resource();
//
//    // Атака и защита
//    void attack(Enemy* enemy);
//    void defend();
//
//    // Оставление феромонов
//    void leave_pheromone(info_type type);
//
//    // Геттеры
//    int get_hp() const { return hp; }
//    int get_max_hp() const { return max_hp; }
//    int get_age() const { return age; }
//    int get_speed() const { return speed; }
//    character get_character() const { return charact; }
//    Position get_position() const { return pos; }
//    bool is_carrying_resource() const { return carrying_resource; }
//    res_type get_resource_type() const { return resource_type; }
//    bool has_died() const { return is_dead; }
//    bool has_target;
//
//    void set_position(const Position& new_pos) {
//        pos = new_pos;
//        body.setPosition(pos.x, pos.y);
//    }
//    void set_target(const Position& new_target) {
//        target = new_target;
//        has_target = true;
//    }
//    void clear_target() { has_target = false; }
//    void set_returning_home(bool value) { returning_home = value; }
//    Anthill* get_home() { return home; }
//
//    // Методы для отрисовки
//    sf::CircleShape& get_body() { return body; }
//
//    // Обнаружение объектов
//    template<typename T>
//    bool can_see(const T& obj, float radius) const {
//        Position obj_pos;
//        if constexpr (std::is_same_v<T, Position>) {
//            obj_pos = obj;
//        }
//        else {
//            obj_pos = obj.get_position();
//        }
//        return pos.distance(obj_pos) <= radius;
//    }
//
//    // Метод для умирания
//    void kill() {
//        is_dead = true;
//        hp = 0;
//        cout << "Ant (" << get_role_name() << ") has died" << endl;
//    }
//};
//
//// Класс "Муравейник" с использованием геометрической фигуры (CircleShape) для визуализации базы
//class Anthill {
//public:
//    Anthill(Position pos = Position(400, 300));
//    ~Anthill() = default;
//
//    // Основные методы
//    void update();
//    void add_ant();
//    void remove_dead_ants();
//    void leveling();
//
//    // Управление ресурсами
//    void add_food(int amount);
//    void add_sticks(int amount);
//    void consume_food();
//
//    // Феромоны и информеры
//    void register_pheromone(Pheromone pheromone);
//    void update_pheromones();
//
//    // Взаимодействие с ресурсами на карте
//    void register_resource(Resource resource);
//    void update_resources();
//
//    // Взаимодействие с врагами
//    void register_enemy(Enemy enemy);
//    void update_enemies();
//
//    // Геттеры
//    int get_level() const { return level; }
//    int get_food_count() const { return food_count; }
//    int get_stick_count() const { return stick_count; }
//    int get_capacity() const { return capacity; }
//    int get_ant_count() const { return static_cast<int>(colony.size()); }
//    Position get_position() const { return position; }
//
//    const vector<unique_ptr<Ant>>& get_ants() const { return colony; }
//    vector<unique_ptr<Ant>>& get_ants() { return colony; }
//    const vector<Pheromone>& get_pheromones() const { return pheromones; }
//    const vector<Resource>& get_resources() const { return resources; }
//    const vector<Enemy>& get_enemies() const { return enemies; }
//
//    // Информеры
//    Informer<Ant>& get_food_informer() { return food_informer; }
//    Informer<Ant>& get_stick_informer() { return stick_informer; }
//    Informer<Ant>& get_enemy_informer() { return enemy_informer; }
//
//    // Методы для отрисовки базы
//    sf::CircleShape& get_shape() { return shape; }
//    void setup_shape() {
//        float radius = 30.f + 10.f * level;
//        shape.setRadius(radius);
//        shape.setOrigin(radius, radius);
//        shape.setPosition(position.x, position.y);
//        shape.setFillColor(sf::Color(139, 69, 19)); // коричневый
//    }
//
//private:
//    int level, food_count, stick_count, capacity;
//    Position position;
//    vector<unique_ptr<Ant>> colony;
//    vector<Pheromone> pheromones;
//    vector<Resource> resources;
//    vector<Enemy> enemies;
//    sf::CircleShape shape;
//
//    Informer<Ant> food_informer;
//    Informer<Ant> stick_informer;
//    Informer<Ant> enemy_informer;
//
//    int food_consumption_timer;
//    int spawn_timer;
//    int resource_spawn_timer;
//    int enemy_spawn_timer;
//};
