#include <SFML/Audio.hpp>
#include "Ant.h"
#include "Enemy.h"
#include <cmath>

#define Colony
#ifdef Colony
int main() {
    srand(static_cast<unsigned>(time(nullptr)));  

    std::vector<Ant> colony;
    std::vector<Enemy> raid;
    std::vector<Resource> resources;
    int res_on_map = 0, x = 0, y = 0, ticks = 0;

    Clock time;
    float last_time = 0;
    for (int i = 0; i <= stick_claster_count + food_cluster_count; ++i) {
        do {
            x = rand() % (window_weidth - 2 * dist_btw_res) + dist_btw_res;
            y = rand() % (window_high - 2 * dist_btw_res) + dist_btw_res;
        } while ((x > window_weidth / 2 - 3 * start_hill_size) && (x < window_weidth / 2 + 3 * start_hill_size) ||
            (y > window_high / 2 - 3 * start_hill_size) && (y < window_high / 2 - 3 * start_hill_size));
        if (i <= food_cluster_count)
            create_cluster(res_on_map, resources, x, y, food);
        else
            create_cluster(res_on_map, resources, x, y, stick);
    }

    for (int i = 0; i < 20; ++i) {
        do {
            x = rand() % window_weidth;
            y = rand() % window_high;
        } while ((x < window_weidth / 2 - start_hill_size / 2) ||
            (x > window_weidth / 2 + start_hill_size / 2) ||
            (y < window_high / 2 - start_hill_size / 2) ||
            (y > window_high / 2 + start_hill_size / 2));
        colony.emplace_back(x, y);
    }

    CircleShape circle(start_hill_size);
    circle.setPosition(Vector2f(window_weidth / 2 - start_hill_size, window_high / 2 - start_hill_size));
    circle.setFillColor(Color(115, 66, 34));

    RenderWindow window(VideoMode(window_weidth, window_high), L"Colony Simulator");
    Image icon;
    if (!icon.loadFromFile("anthill.png")) {
        return -1;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    Music backgroundMusic;
    if (!backgroundMusic.openFromFile("music.ogg")) {
        return -1;
    }
    backgroundMusic.setLoop(true);
    backgroundMusic.setVolume(100);
    backgroundMusic.play();

    Event event;

    while (window.isOpen()) {
        if (time.getElapsedTime().asMilliseconds() - last_time >= update_time) {
            ticks++;
            last_time = time.getElapsedTime().asMilliseconds();

            for (auto& ant : colony) {
                ant.move();
                if (ant.get_hp() > 0) {
                    ant.up_time();
                    if (ant.get_age() % stage_time == 0 && ant.get_age())
                        ant.upd_role();
                }
            }

            for (size_t i = 0; i < colony.size(); i++) {
                for (size_t j = i + 1; j < colony.size(); j++) {
                    Vector2f pos1 = colony[i].get_shape().getPosition();
                    Vector2f pos2 = colony[j].get_shape().getPosition();

                    float dx = pos1.x - pos2.x;
                    float dy = pos1.y - pos2.y;
                    float distance = sqrt(dx * dx + dy * dy);
                    float min_dist = ant_size * 2.0f;  

                    if (distance < min_dist && distance > 0.001f) {
                        float overlap = (min_dist - distance) / 2.0f;
                        float offsetX = (dx / distance) * overlap;
                        float offsetY = (dy / distance) * overlap;

                        CircleShape& shape1 = const_cast<CircleShape&>(colony[i].get_shape());
                        CircleShape& shape2 = const_cast<CircleShape&>(colony[j].get_shape());

                        shape1.setPosition(pos1.x + offsetX, pos1.y + offsetY);
                        shape2.setPosition(pos2.x - offsetX, pos2.y - offsetY);
                    }
                }
            }

            if (ticks % enemy_wave_period == 0)
                for (int i = 0; i < 5; ++i)
                    raid.emplace_back(10, 10);

            for (auto& enemy : raid) {
                enemy.move();
                if (enemy.get_hp() > 0) {
                    enemy.aged();
                }
            }

            for (size_t i = 0; i < raid.size(); i++) {
                for (size_t j = i + 1; j < raid.size(); j++) {
                    Vector2f enemy_pos1 = raid[i].get_shape().getPosition();
                    Vector2f enemy_pos2 = raid[j].get_shape().getPosition();

                    float dx = enemy_pos1.x - enemy_pos2.x;
                    float dy = enemy_pos2.y - enemy_pos2.y;
                    float distance = sqrt(dx * dx + dy * dy);
 
                    float radius1 = raid[i].get_shape().getRadius();
                    float radius2 = raid[j].get_shape().getRadius();
                    float min_dist_enemy = radius1 + radius2;

                    if (distance < min_dist_enemy && distance > 0.001f) {
                        float overlap = (min_dist_enemy - distance) / 2.0f;
                        float offsetX = (dx / distance) * overlap;
                        float offsetY = (dy / distance) * overlap;

                        CircleShape& eShape1 = const_cast<CircleShape&>(raid[i].get_shape());
                        CircleShape& eShape2 = const_cast<CircleShape&>(raid[j].get_shape());

                        eShape1.setPosition(enemy_pos1.x + offsetX, enemy_pos1.y + offsetY);
                        eShape2.setPosition(enemy_pos2.x - offsetX, enemy_pos2.y - offsetY);
                    }
                }
            }
        }

        while (window.pollEvent(event))
            if (event.type == Event::Closed)
                window.close();

        window.clear(Color(102, 204, 0));
        window.draw(circle);
        for (const auto& res : resources)
            if (res.is_visible())
                window.draw(res.get_shape());
        for (auto& ant : colony)
            if (ant.is_visible())
                window.draw(ant.get_shape());
        for (auto& enemy : raid)
            if (enemy.is_visible())
                window.draw(enemy.get_shape());
        window.display();
    }
    return 0;
}
#endif
