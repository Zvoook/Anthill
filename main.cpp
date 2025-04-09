#include "fix_for_macos.hpp"
#include <SFML/Audio.hpp>
#include <sstream>
#include "Ant.h"
#include "Enemy.h"
#include "Anthill.h"

#define Colony
#ifdef Colony
int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    Anthill anthill;
    std::vector<Enemy> raid;
    std::vector<Resource> resources;
    int x = 0, y = 0, ticks = 0;

    //Resource spawn
    Clock time;
    float last_time = 0;
    for (int i = 0; i <= stick_claster_count + food_cluster_count; ++i) {
        do {
            x = rand() % (window_weidth - 2 * dist_btw_res) + dist_btw_res;
            y = rand() % (window_high - 2 * dist_btw_res) + dist_btw_res;
        } while ((x > window_weidth / 2 - 3 * start_hill_size) && (x < window_weidth / 2 + 3 * start_hill_size) ||
            (y > window_high / 2 - 3 * start_hill_size) && (y < window_high / 2 - 3 * start_hill_size));
        if (i <= food_cluster_count)
            create_cluster(resources, x, y, food);
        else
            create_cluster(resources, x, y, stick);
    }
     //Anthil setting
    CircleShape circle(start_hill_size);
    circle.setPosition(Vector2f(window_weidth / 2 - start_hill_size, window_high / 2 - start_hill_size));
    circle.setFillColor(Color(115, 66, 34));

    //Window setting
    RenderWindow window(VideoMode(window_weidth, window_high), L"Colony Simulator");
    Image icon;
    if (!icon.loadFromFile("anthill.png")) return -1;
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //MUSIC
    /*Music backgroundMusic;
    if (!backgroundMusic.openFromFile("Voroniny.ogg")) return -1;
    backgroundMusic.setLoop(true);
    backgroundMusic.setVolume(100);
    backgroundMusic.play();*/

    //Events and font
    Event event;
    Font font;
    if (!font.loadFromFile("Arial.ttf")) return -1;
    Text statsText("", font, 20);
    statsText.setFillColor(Color::White);
    statsText.setPosition(10, 10);

    while (window.isOpen()) {
        if (time.getElapsedTime().asMilliseconds() - last_time >= update_time) {
            ticks++;
            last_time = time.getElapsedTime().asMilliseconds();

            //Spawn entities
            if (ticks % enemy_wave_period == 0) {
                for (int i = 0; i < 10; ++i) anthill.born_baby();
                //for (int i = 0; i < 5; ++i) raid.emplace_back(10, 10);
            }
            //anthill.feeding();

            for (auto& ant : anthill.colony) {
            ant.move();
            if (ant.get_hp() > 0) {
                ant.up_time();
                if (ant.get_age() % stage_time == 0 && ant.get_age())
                    ant.upd_role();
            }
            }

            //Enemy's update
            for (auto& enemy : raid) {
                enemy.move();
                if (enemy.get_hp() > 0) enemy.aged();
            }

            for (auto& ant : anthill.colony) {
                if (!ant.has_valid_target() && ant.get_inventory() == no_res) {
                    for (auto& res : resources) {
                        if (res.is_visible()) {
                            if ((res.get_type() == food && ant.get_role() == 2) ||
                                (res.get_type() == stick && ant.get_role() == 3)) {
                                ant.set_target(res.get_posit());
                                break;
                            }
                        }
                    }
                }

                for (auto& res : resources) {
                    if (res.is_visible() && ant.get_inventory() == no_res) {
                        if (ant.get_pos().distance(res.get_posit()) < ant_size * 1.5f && ant.pick(res)) {
                            ant.set_inventory(res.get_type());
                            res.set_invisible();
                            ant.set_target(Position(window_weidth / 2, window_high / 2));
                            break;
                        }
                    }
                }

                // �������� �������
                if (ant.get_inventory() != no_res && ant.get_pos().in_anthill()) {
                    anthill.drop(ant);
                    ant.clear_target();
                }
            }

            // ������������ ��������
            for (size_t i = 0; i < anthill.colony.size(); i++) {
                for (size_t j = i + 1; j < anthill.colony.size(); j++) {
                    Vector2f pos1 = anthill.colony[i].get_shape().getPosition();
                    Vector2f pos2 = anthill.colony[j].get_shape().getPosition();


                    float dx = pos1.x - pos2.x;
                    float dy = pos1.y - pos2.y;
                    float distance = sqrt(dx * dx + dy * dy);
                    float min_dist = ant_size * 2.0f;

                    if (distance < min_dist && distance > 0.001f) {
                        float overlap = (min_dist - distance) / 2.0f;
                        float offsetX = (dx / distance) * overlap;
                        float offsetY = (dy / distance) * overlap;

                        CircleShape& shape1 = const_cast<CircleShape&>(anthill.colony[i].get_shape());
                        CircleShape& shape2 = const_cast<CircleShape&>(anthill.colony[j].get_shape());

                        shape1.setPosition(pos1.x + offsetX, pos1.y + offsetY);
                        shape2.setPosition(pos2.x - offsetX, pos2.y - offsetY);
                    }
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

        std::stringstream stats;
        stats << "Ants: " << anthill.colony.size() << "\n";
        stats << "Soldiers: " << anthill.get_soldier_count() << "\n";
        stats << "Builders: " << anthill.get_builder_count() << "\n";
        stats << "Cleaners: " << anthill.get_cleaner_count() << "\n";
        stats << "Sitters: " << anthill.get_sitter_count() << "\n";
        stats << "Babies: " << anthill.get_baby_count() << "\n";
        stats << "Shepherds: " << anthill.get_shepherd_count() << "\n";
        stats << "Collectors: " << anthill.get_collector_count() << "\n";
        stats << "Food: " << anthill.get_food_count() << "\n";
        stats << "Sticks: " << anthill.get_stick_count() << "\n";

        statsText.setString(stats.str());

        while (window.pollEvent(event)) if (event.type == Event::Closed) window.close();

        window.clear(Color(102, 204, 0));
        window.draw(circle);
        for (const auto& res : resources) if (res.is_visible()) window.draw(res.get_shape());
        for (auto& ant : anthill.colony) if (ant.is_visible()) window.draw(ant.get_shape());
        for (auto& enemy : raid) if (enemy.is_visible()) window.draw(enemy.get_shape());
        window.draw(statsText);
        window.display();
    }
    return 0;
}
#endif
