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
    vector<Enemy> raid;
    vector<Resource> resources;
    int x = 0, y = 0, ticks = 0;

    //Resource spawn
    Clock time;
    float last_time = 0;
    for (int i = 0; i <= stick_claster_count + food_cluster_count; ++i) {
        do {
            x = rand() % (window_weidth - 2 * dist_btw_res) + dist_btw_res;
            y = rand() % (window_high - 2 * dist_btw_res) + dist_btw_res;
        } while ((x > window_weidth / 2 - 3 * start_radius) && (x < window_weidth / 2 + 3 * start_radius) ||
            (y > window_high / 2 - 3 * start_radius) && (y < window_high / 2 - 3 * start_radius));
        if (i <= food_cluster_count) create_cluster(resources, x, y, food);
        else create_cluster(resources, x, y, stick);
    }

     //Anthil setting
    CircleShape circle(start_radius);
    circle.setPosition(Vector2f(window_weidth / 2 - start_radius, window_high / 2 - start_radius));
    circle.setFillColor(Color(115, 66, 34));

    CircleShape enemy_hill_1(start_radius);
    enemy_hill_1.setPosition(Vector2f(-start_radius / 2, -start_radius / 2));
    enemy_hill_1.setFillColor(Color::Black);

    CircleShape enemy_hill_2(start_radius);
    enemy_hill_2.setPosition(Vector2f(window_high - start_radius * 1.5, window_weidth - start_radius * 1.5));
    enemy_hill_2.setFillColor(Color::Black);

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
    Text statsText("", font, 25);
    statsText.setFillColor(Color::White);
    statsText.setPosition(5, 5);

    while (window.isOpen()) {
        if (time.getElapsedTime().asMilliseconds() - last_time >= scene_update_time) {
            last_time = time.getElapsedTime().asMilliseconds();
            ticks++;
            anthill.upd_anthill(ticks);

            //Spawn entities
            if (ticks % enemy_wave_period == 0) {
                for (int i = 0; i < 5; ++i) raid.emplace_back(10, 10);
            }

            for (auto& ant : anthill.colony) {
                ant.look_around(resources);
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
        vector<Text> statsLines;  // Вместо одного statsText

        statsLines.clear();  // Обновляем каждый тик
        int line = 0;
        auto makeText = [&](const std::string& text, sf::Color color) {
            sf::Text t(text, font, 20);
            t.setFillColor(color);
            t.setPosition(10, 10 + line * 24);
            line++;
            statsLines.push_back(t);
            };

        // Теперь добавляем строки с цветами:
        makeText("Ants: " + std::to_string(anthill.get_ant_count()), Color::White);
        makeText("Enemies: " + std::to_string(raid.size()), Color::Red);
        makeText("Food: " + std::to_string(anthill.get_food_count()), Color(0, 255, 0));
        makeText("Sticks: " + std::to_string(anthill.get_stick_count()), Color(139, 69, 19)); // Коричневый

        makeText("---------------", sf::Color(200, 200, 200));
        makeText("Babies: " + std::to_string(anthill.get_baby_count()), Color::White);
        makeText("Sitters: " + std::to_string(anthill.get_sitter_count()), Color(255, 102, 178));
        makeText("Collectors: " + std::to_string(anthill.get_collector_count()), Color(255, 128, 0));
        makeText("Builders: " + std::to_string(anthill.get_builder_count()), Color::Yellow);
        makeText("Soldiers: " + std::to_string(anthill.get_soldier_count()), sf::Color::Black);
        makeText("Shepherds: " + std::to_string(anthill.get_shepherd_count()), sf::Color(0, 0, 204));
        makeText("Cleaners: " + std::to_string(anthill.get_cleaner_count()), sf::Color(102, 51, 0));

        while (window.pollEvent(event)) if (event.type == Event::Closed) window.close();
        window.clear(Color(102, 204, 0));
        window.draw(circle);
        window.draw(enemy_hill_1);
        window.draw(enemy_hill_2);
        for (const auto& res : resources) if (res.is_visible()) window.draw(res.get_shape());
        for (const auto& ant : anthill.colony) {
            if (ant.is_visible()) {
                window.draw(ant.get_shape());
                if (vision_circle) window.draw(ant.get_vision_circle());
            }
        }
        for (auto& enemy : raid) if (enemy.is_visible()) window.draw(enemy.get_shape());
        for (const auto& text : statsLines) {
            window.draw(text);
        }
        window.display();
    }
    return 0;
}
#endif