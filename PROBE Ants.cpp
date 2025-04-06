//#include <sfml/graphics.hpp>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <cmath>
//#include <limits>
//#include <iostream>
//#include <algorithm>
//
//struct resourcerequest {
//    int resourceid;
//    sf::vector2f position;
//    bool isfood;
//    int remainingants;
//    resourcesize size;
//};
//
//class ant {
//public:
//    sf::circleshape shape;
//    sf::vector2f velocity;
//    bool carryingresource;
//    antrole role;
//    sf::vector2f patrolpoint;
//    int resourceid;
//    int carryweight;
//    float timeinrole;
//    float maxroletime;
//    bool isalive;
//
//    ant(float x, float y, antrole role) : role(role), timeinrole(0.f), isalive(true) {
//        shape.setradius(ant_size);
//
//        switch (role) {
//        case antrole::larva:
//            shape.setfillcolor(sf::color(255, 182, 193));
//            maxroletime = 10.f;
//            velocity = { 0.0f, 0.0f };
//            break;
//        case antrole::forager:
//            shape.setfillcolor(sf::color::blue);
//            maxroletime = 20.f;
//            velocity = { (rand() % 2 ? -1.0f : 1.0f) * speed, (rand() % 2 ? -1.0f : 1.0f) * speed };
//            break;
//        case antrole::builder:
//            shape.setfillcolor(sf::color::yellow);
//            maxroletime = 30.f;
//            velocity = { (rand() % 2 ? -1.0f : 1.0f) * speed, (rand() % 2 ? -1.0f : 1.0f) * speed };
//            break;
//        case antrole::soldier:
//            shape.setfillcolor(sf::color::red);
//            maxroletime = 40.f;
//            patrolpoint = { static_cast<float>(rand() % game_field_width), static_cast<float>(rand() % game_field_height) };
//            velocity = { (rand() % 2 ? -1.0f : 1.0f) * patrol_speed, (rand() % 2 ? -1.0f : 1.0f) * patrol_speed };
//            break;
//        }
//
//        shape.setposition(x, y);
//        carryingresource = false;
//        resourceid = -1;
//        carryweight = 0;
//    }
//
//    void update(float deltatime) {
//        if (!isalive) return;
//
//        timeinrole += deltatime;
//            if (timeinrole >= maxroletime) {
//                switch (role) {
//                case antrole::larva:
//                    role = antrole::forager;
//                    shape.setfillcolor(sf::color::blue);
//                    maxroletime = 20.f;
//                    velocity = { (rand() % 2 ? -1.0f : 1.0f) * speed, (rand() % 2 ? -1.0f : 1.0f) * speed };
//                    break;
//                case antrole::forager:
//                    role = antrole::builder;
//                    shape.setfillcolor(sf::color::yellow);
//                    maxroletime = 30.f;
//                    break;
//                case antrole::builder:
//                    role = antrole::soldier;
//                    shape.setfillcolor(sf::color::red);
//                    maxroletime = 40.f;
//                    patrolpoint = { static_cast<float>(rand() % game_field_width), static_cast<float>(rand() % game_field_height) };
//                    velocity = { (rand() % 2 ? -1.0f : 1.0f) * patrol_speed, (rand() % 2 ? -1.0f : 1.0f) * patrol_speed };
//                    break;
//                case antrole::soldier:
//                    isalive = false;
//                    return;
//                }
//                timeinrole = 0.f;
//            }
//    }
//
//    void patrolmove() {
//        if (role != antrole::soldier) return;
//
//        sf::vector2f currentpos = shape.getposition();
//        float distance = std::hypot(currentpos.x - patrolpoint.x, currentpos.y - patrolpoint.y);
//
//        if (distance < 10.0f) {
//            patrolpoint = { static_cast<float>(rand() % game_field_width), static_cast<float>(rand() % game_field_height) };
//        }
//
//        sf::vector2f direction = patrolpoint - currentpos;
//        float length = std::hypot(direction.x, direction.y);
//        if (length > 0) {
//            direction /= length;
//            shape.move(direction * patrol_speed);
//        }
//    }
//
//    bool checkcollisionwithresource(sf::rectangleshape& resourceshape) {
//        return shape.getglobalbounds().intersects(resourceshape.getglobalbounds());
//    }
//};
//
//class resource {
//public:
//    sf::rectangleshape shape;
//    bool isfood;
//    resourcesize size;
//    int requiredants;
//    int currentants;
//    int resourceid;
//    static int nextid;
//
//    resource(float x, float y, bool isfood, resourcesize size) : isfood(isfood), size(size), currentants(0) {
//        resourceid = nextid++;
//
//        float sizevalue;
//        switch (size) {
//        case resourcesize::small:   sizevalue = resource_size_small; requiredants = 1; break;
//        case resourcesize::medium:  sizevalue = resource_size_medium; requiredants = 2; break;
//        case resourcesize::large:   sizevalue = resource_size_large; requiredants = 3; break;
//        }
//
//        shape.setsize(sf::vector2f(sizevalue, sizevalue));
//        shape.setfillcolor(isfood ? sf::color::red : sf::color::yellow);
//        shape.setposition(x, y);
//    }
//};
//
//int resource::nextid = 0;
//
//class nest {
//public:
//    sf::circleshape shape;
//    nest(float x, float y, float radius) {
//        shape.setradius(radius);
//        shape.setfillcolor(sf::color(139, 69, 19));
//        shape.setposition(x - radius, y - radius);
//    }
//};
//
//void letterboxview(sf::view& view, int windowwidth, int windowheight) {
//    float windowratio = windowwidth / static_cast<float>(windowheight);
//    float viewratio = view.getsize().x / view.getsize().y;
//    float sizex = 1.f;
//    float sizey = 1.f;
//    float posx = 0.f;
//    float posy = 0.f;
//    bool horizontalspacing = true;
//
//    if (windowratio < viewratio) horizontalspacing = false;
//
//    if (horizontalspacing) {
//        sizex = viewratio / windowratio;
//        posx = (1.f - sizex) / 2.f;
//    }
//    else {
//        sizey = windowratio / viewratio;
//        posy = (1.f - sizey) / 2.f;
//    }
//
//    view.setviewport(sf::floatrect(posx, posy, sizex, sizey));
//}
//
//sf::vector2f randompositioninnest(const nest& nest) {
//    float nestradius = nest.shape.getradius();
//    sf::vector2f nestcenter = nest.shape.getposition() + sf::vector2f(nestradius, nestradius);
//    float r = nestradius * std::sqrt(static_cast<float>(rand()) / rand_max);
//    float theta = 2 * pi * static_cast<float>(rand()) / rand_max;
//    return { nestcenter.x + r * std::cos(theta), nestcenter.y + r * std::sin(theta) };
//}
//
//
//int main() {
//    sf::renderwindow window(sf::videomode(game_field_width, game_field_height), "ant colony simulation");
//    srand(static_cast<unsigned>(time(0)));
//
//    sf::view fixedview(sf::floatrect(0, 0, game_field_width, game_field_height));
//    window.setview(fixedview);
//
//    sf::font font;
//    if (!font.loadfromfile("arial.ttf")) {
//        std::cerr << "ошибка загрузки шрифта!" << std::endl;
//        return -1;
//    }
//
//    int foodcollected = 0;
//    int stickscollected = 0;
//    sf::text countertext;
//    countertext.setfont(font);
//    countertext.setcharactersize(20);
//    countertext.setfillcolor(sf::color::white);
//    countertext.setoutlinecolor(sf::color::black);
//    countertext.setoutlinethickness(2);
//    countertext.setposition(10.f, 10.f);
//
//    nest nest(game_field_width / 2.0f, game_field_height / 2.0f, nest_radius_initial);
//
//    std::vector<ant> ants;
//    for (int i = 0; i < initial_ants; ++i) {
//        antrole role = (i % 2 == 0) ? antrole::forager : antrole::builder;
//        ants.emplace_back(game_field_width / 2.0f + static_cast<float>(rand() % 20),
//            game_field_height / 2.0f + static_cast<float>(rand() % 20), role);
//    }
//
//    for (int i = 0; i < initial_soldiers; ++i) {
//        ants.emplace_back(game_field_width / 2.0f + static_cast<float>(rand() % 50),
//            game_field_height / 2.0f + static_cast<float>(rand() % 50), antrole::soldier);
//    }
//
//    for (int i = 0; i < initial_larvae; ++i) {
//        sf::vector2f nestpos = randompositioninnest(nest);
//        ants.emplace_back(nestpos.x, nestpos.y, antrole::larva);
//    }
//
//    std::vector<resource> resources;
//    for (int i = 0; i < num_resource_clusters; ++i) {
//        float x = static_cast<float>(rand() % game_field_width);
//        float y = static_cast<float>(rand() % game_field_height);
//        createresourcecluster(resources, x, y, true);
//    }
//
//    for (int i = 0; i < num_resource_clusters; ++i) {
//        float x = static_cast<float>(rand() % game_field_width);
//        float y = static_cast<float>(rand() % game_field_height);
//        createresourcecluster(resources, x, y, false);
//    }
//
//    int totalsticksonmap = num_resource_clusters * resources_per_cluster;
//    int nestimprovementthreshold = totalsticksonmap / 4;
//
//    std::vector<resourcerequest> helprequests;
//    sf::clock deltaclock;
//
//    while (window.isopen()) {
//        float deltatime = deltaclock.restart().asseconds();
//        sf::event event;
//
//        while (window.pollevent(event)) {
//            if (event.type == sf::event::closed)
//                window.close();
//            if (event.type == sf::event::resized)
//                letterboxview(fixedview, event.size.width, event.size.height);
//        }
//
//        // обновление муравьев
//        std::vector<ant> newants;
//        for (auto& ant : ants) {
//            if (!ant.isalive) continue;
//            ant.update(deltatime);
//
//            if (ant.role == antrole::soldier) {
//                ant.patrolmove();
//                continue;
//            }
//                // логика сборщиков и строителей
//                if (!ant.carryingresource) {
//                    resource* target = nullptr;
//                    float mindistance = std::numeric_limits<float>::max();
//                    resourcesize priority = resourcesize::large;
//
//                    for (auto& resource : resources) {
//                        if (resource.shape.getfillcolor() == sf::color::transparent) continue;
//                        if ((ant.role == antrole::forager && !resource.isfood) ||
//                            (ant.role == antrole::builder && resource.isfood)) continue;
//
//                        if (resource.currentants >= resource.requiredants) continue;
//
//                        if (resource.size < priority ||
//                            (resource.size == priority &&
//                                std::hypot(ant.shape.getposition().x - resource.shape.getposition().x,
//                                    ant.shape.getposition().y - resource.shape.getposition().y) < mindistance)) {
//                            target = &resource;
//                            priority = resource.size;
//                            mindistance = std::hypot(ant.shape.getposition().x - resource.shape.getposition().x,
//                                ant.shape.getposition().y - resource.shape.getposition().y);
//                        }
//                    }
//
//                    if (target) {
//                        if (ant.resourceid == -1) {
//                            ant.resourceid = target->resourceid;
//                            target->currentants++;
//                        }
//
//                        sf::vector2f direction = target->shape.getposition() - ant.shape.getposition();
//                        float length = std::hypot(direction.x, direction.y);
//                        if (length > 0) {
//                            direction /= length;
//                            ant.shape.move(direction * speed);
//                        }
//
//                        if (ant.checkcollisionwithresource(target->shape)) {
//                            ant.carryingresource = true;
//                            ant.carryweight = 1;
//
//                            if (target->currentants == target->requiredants) {
//                                target->shape.setfillcolor(sf::color::transparent);
//                            }
//                        }
//                    }
//                    else {
//                        ant.shape.move(ant.velocity);
//                    }
//                }
//                else {
//                    sf::vector2f nestcenter = nest.shape.getposition() + sf::vector2f(nest.shape.getradius(), nest.shape.getradius());
//                    sf::vector2f direction = nestcenter - ant.shape.getposition();
//                    float length = std::hypot(direction.x, direction.y);
//
//                    if (length > 2.0f) {
//                        direction /= length;
//                        ant.shape.move(direction * speed);
//                    }
//                    else {
//                        ant.carryingresource = false;
//                        ant.resourceid = -1;
//
//                        if (ant.role == antrole::forager) foodcollected += ant.carryweight;
//                        if (ant.role == antrole::builder) stickscollected += ant.carryweight;
//                        ant.carryweight = 0;
//                    }
//                }
//        }
//
//        // обработка запросов помощи
//        for (auto& resource : resources) {
//            if (resource.shape.getfillcolor() == sf::color::transparent) continue;
//            if (resource.currentants < resource.requiredants) {
//                helprequests.push_back({
//                    resource.resourceid,
//                    resource.shape.getposition(),
//                    resource.isfood,
//                    resource.requiredants - resource.currentants,
//                    resource.size
//                    });
//            }
//        }
//
//        for (auto& request : helprequests) {
//            for (auto& ant : ants) {
//                if (!ant.isalive || ant.carryingresource || ant.resourceid != -1) continue;
//                if (ant.role != (request.isfood ? antrole::forager : antrole::builder)) continue;
//                    ant.resourceid = request.resourceid;
//                request.remaining_ants--;
//                break;
//            }
//        }
//
//        helprequests.erase(std::remove_if(helprequests.begin(), helprequests.end(),
//            [](const resourcerequest& req) { return req.remainingants <= 0; }), helprequests.end());
//
//        // создание новых муравьев
//        if (foodcollected >= food_threshold_for_new_ant) {
//            bool larvatransformed = false;
//            for (auto& ant : ants) {
//                if (ant.role == antrole::larva && rand() % 10 < 3) {
//                    ant = ant(ant.shape.getposition().x, ant.shape.getposition().y,
//                        (rand() % 10 < 3) ? antrole::soldier :
//                        (rand() % 2 ? antrole::forager : antrole::builder));
//                    foodcollected -= food_threshold_for_new_ant;
//                    larvatransformed = true;
//                    break;
//                }
//            }
//
//            if (!larvatransformed) {
//                if (rand() % 5 == 0) {
//                    sf::vector2f pos = randompositioninnest(nest);
//                    newants.emplace_back(pos.x, pos.y, antrole::larva);
//                }
//                else {
//                    antrole newrole = (rand() % 10 < 2) ? antrole::soldier :
//                        (rand() % 2 ? antrole::forager : antrole::builder);
//                    newants.emplace_back(nest.shape.getposition().x, nest.shape.getposition().y, newrole);
//                }
//                foodcollected -= food_threshold_for_new_ant;
//            }
//        }
//
//        ants.insert(ants.end(), newants.begin(), newants.end());
//
//        // улучшение муравейника
//        if (stickscollected >= nestimprovementthreshold) {
//            float newradius = nest.shape.getradius() + 10.f;
//            sf::vector2f center(game_field_width / 2.0f, game_field_height / 2.0f);
//            nest.shape.setradius(newradius);
//            nest.shape.setposition(center.x - newradius, center.y - newradius);
//            stickscollected -= nestimprovementthreshold;
//
//            for (auto& ant : ants) {
//                if (ant.role == antrole::larva) {
//                    ant.shape.setposition(randompositioninnest(nest));
//                }
//            }
//        }
//
//        // обновление ui
//        int larvae = 0, soldiers = 0, foragers = 0, builders = 0;
//        for (const auto& ant : ants) {
//            if (!ant.isalive) continue;
//            switch (ant.role) {
//            case antrole::larva: larvae++; break;
//            case antrole::soldier: soldiers++; break;
//            case antrole::forager: foragers++; break;
//            case antrole::builder: builders++; break;
//            }
//        }
//
//        int visiblefood = 0, visiblesticks = 0;
//        for (const auto& res : resources) {
//            if (res.shape.getfillcolor() != sf::color::transparent) {
//                res.isfood ? visiblefood++ : visiblesticks++;
//            }
//        }
//
//        countertext.setstring(
//            "ants: " + std::to_string(ants.size()) +
//            " (f:" + std::to_string(foragers) +
//            " b:" + std::to_string(builders) +
//            " s:" + std::to_string(soldiers) +
//            " l:" + std::to_string(larvae) + ")" +
//            "  food: " + std::to_string(foodcollected) +
//            "  sticks: " + std::to_string(stickscollected) +
//            "  resources: " + std::to_string(visiblefood) + "/" + std::to_string(visiblesticks)
//        );
//
//        window.clear(sf::color::green);
//        window.draw(nest.shape);
//        for (auto& res : resources) window.draw(res.shape);
//        for (auto& ant : ants) if (ant.isalive) window.draw(ant.shape);
//        window.draw(countertext);
//        window.display();
//    }
//
//    return 0;
//}