#include "Ant.h"

#define Colony
#ifdef Colony
int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    Clock time;
    float last_time = 0;
    vector<Ant> colony;
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
    Ant Jora(500,100), Zahar(1000,800);
    colony.push_back(Jora);
    colony.push_back(Zahar);
   /* while (1) {
        if (time.getElapsedTime().asMilliseconds() - last_time >= update_time) {
            last_time = time.getElapsedTime().asMilliseconds();
            for (auto& ant : colony) {
                if (ant.get_hp() > 0) ant.aged(); 
                if (ant.get_age() % stage_time_per_ticks && ant.get_age()< stage_time_per_ticks*life_stages) ant.upd_role();
            }
        }
    }*/

    CircleShape circle(start_hill_size);
    circle.setPosition(Vector2f(window_weidth/2 - start_hill_size, window_high/2 - start_hill_size));
    circle.setFillColor(Color(115, 66, 34));
	RenderWindow window(VideoMode(window_weidth, window_high), L"Colony Simulator");
    Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) if (event.type == Event::Closed) window.close();
        window.clear(Color(102,204,0));
        window.draw(circle);
        for (const auto& res : resources) {
            window.draw(res.get_shape());
            window.draw(Jora.get_shape());
            window.draw(Zahar.get_shape());
        }
        window.display();
    }
	return 0;
}
#endif