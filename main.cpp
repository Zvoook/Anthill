#include <SFML/Audio.hpp>
#include "Ant.h"
#include "Enemy.h"

#define Colony
#ifdef Colony
int main() {
    srand(static_cast<unsigned>(time(nullptr)));  //randomazing
    
    vector<Ant> colony;
    vector<Enemy> raid;
    vector<Resource> resources;
    int res_on_map = 0, x = 0, y = 0, ticks=0;

    Clock time;
    float last_time = 0;
    for (int i = 0; i <= stick_claster_count + food_cluster_count; ++i) {
        do {
            x = rand() % (window_weidth - 2 * dist_btw_res) + dist_btw_res;
            y = rand() % (window_high - 2 * dist_btw_res) + dist_btw_res;
        } while ((x > window_weidth / 2 - 3 * start_hill_size) && (x < window_weidth / 2 + 3 * start_hill_size) || (y > window_high / 2 - 3 * start_hill_size) && (y < window_high / 2 - 3 * start_hill_size));
        if (i <= food_cluster_count) create_cluster(resources, x, y, food);
        else create_cluster(resources, x, y, stick);
    }

    //generating ant colony
    for (int i = 0; i < 50; ++i) {
        do {
            x = rand() % window_weidth;
            y = rand() % window_high;
        } while ((x < window_weidth / 2 - start_hill_size/2) || (x > window_weidth / 2 + start_hill_size/2) || (y < window_high / 2 - start_hill_size/2) || (y > window_high / 2 + start_hill_size/2));
        colony.emplace_back(x, y);
    }

    //generate anthill
    CircleShape circle(start_hill_size);
    circle.setPosition(Vector2f(window_weidth/2 - start_hill_size, window_high/2 - start_hill_size));
    circle.setFillColor(Color(115, 66, 34));

    //Window render
	RenderWindow window(VideoMode(window_weidth, window_high), L"Colony Simulator");
    Image icon;
    if (!icon.loadFromFile("anthill.png")) {
        return -1;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    Music backgroundMusic;
    if (!backgroundMusic.openFromFile("Voroniny.ogg")) {
        return -1;
    }
    backgroundMusic.setLoop(true);
    backgroundMusic.setVolume(100);
    backgroundMusic.play();

    Event event;

    while (window.isOpen()/* && colony.size()>0*/) {
        if (time.getElapsedTime().asMilliseconds() - last_time >= update_time) {
            ticks++;
            last_time = time.getElapsedTime().asMilliseconds();
            for (auto& ant : colony) {
                ant.move();
                if (ant.get_hp() > 0) {
                    ant.up_time();
                    if (ant.get_age() % stage_time == 0 && ant.get_age()) ant.upd_role();
                }
                else colony.erase(remove_if(colony.begin(), colony.end(),
                    [](const auto& ant) { return ant.get_hp() <= 0; }),colony.end());
            }
            if (ticks % enemy_wave_period == 0) for (int i = 0; i < 5; ++i) raid.emplace_back(10, 10);
            for (auto& enemy : raid) {
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
        for (const auto& res : resources) if (res.is_visible()) window.draw(res.get_shape());
        for (auto& ant : colony) if (ant.is_visible()) window.draw(ant.get_shape());
        for (auto& enemy : raid) if (enemy.is_visible()) window.draw(enemy.get_shape());
        window.display();
    }
	return 0;
}
#endif