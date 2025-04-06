#include "Ant.h"
#include "Enemy.h"

#define Colony
#ifdef Colony
int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    Clock time;
    float last_time = 0;
    vector<Ant> colony;
    vector<Enemy> raid;
    vector<Resource> resources;
    int res_on_map = 0, x = 0, y = 0;
    for (int i = 0; i <= stick_claster_count + food_cluster_count; ++i) {
        do {
            x = rand() % (window_weidth - 2 * dist_btw_res) + dist_btw_res;
            y = rand() % (window_high - 2 * dist_btw_res) + dist_btw_res;
        } while ((x > window_weidth / 2 - 3 * start_hill_size) && (x < window_weidth / 2 + 3 * start_hill_size) || (y > window_high / 2 - 3 * start_hill_size) && (y < window_high / 2 - 3 * start_hill_size));
        if (i <= food_cluster_count) create_cluster(res_on_map, resources, x, y, food);
        else create_cluster(res_on_map, resources, x, y, stick);
    }

    //random generating static ants
    int x2 = 0, y2 = 0;
    for (int i = 0; i < 50; ++i) {
        do {
            x2 = rand() % window_weidth;
            y2 = rand() % window_high;
        } while ((x2 < window_weidth / 2 - start_hill_size/2) || (x2 > window_weidth / 2 + start_hill_size/2) || (y2 < window_high / 2 - start_hill_size/2) || (y2 > window_high / 2 + start_hill_size/2));
        colony.emplace_back(x2, y2);
    }

    int ticks = 0;
    CircleShape circle(start_hill_size);
    circle.setPosition(Vector2f(window_weidth/2 - start_hill_size, window_high/2 - start_hill_size));
    circle.setFillColor(Color(115, 66, 34));
	RenderWindow window(VideoMode(window_weidth, window_high), L"Colony Simulator");
    Event event;
    while (window.isOpen()) {
        if (time.getElapsedTime().asMilliseconds() - last_time >= update_time) {
            ticks++;
            last_time = time.getElapsedTime().asMilliseconds();
            for (auto& ant : colony) {
                //ant.set_color();
                ant.move();
                if (ant.get_hp() > 0) {
                    ant.aged();
                    //if (ant.get_age() % stage_time==0 && ant.get_age()) ant.upd_role();
                }
            }
            if (ticks % wave_period == 0) for (int i = 0; i < 5; ++i) raid.emplace_back(10, 10);
            for (auto& enemy : raid) {
                //ant.set_color();
                enemy.move();
                if (enemy.get_hp() > 0) {
                    enemy.aged();
                    //if (ant.get_age() % stage_time==0 && ant.get_age()) ant.upd_role();
                }
            }
        }
        while (window.pollEvent(event)) if (event.type == Event::Closed) window.close();
        window.clear(Color(102,204,0));
        window.draw(circle);
        for (const auto& res : resources) {
            window.draw(res.get_shape());
        }
        for (auto& ant : colony) {
            if (ant.is_visible()) window.draw(ant.get_shape());
        }
        for (auto& enemy : raid) {
            if (enemy.is_visible()) window.draw(enemy.get_shape());
        }
        window.display();
    }
	return 0;
}
#endif

//int larvae = 0, soldiers = 0, foragers = 0, builders = 0;
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