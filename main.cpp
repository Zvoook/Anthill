#include "Ants.h"
#define weidth 1920
#define high 1080
#define update_time 250
#define stick_claster_count 2
#define food_cluster_count 3

#define COLONY
#ifdef COLONY
int main() {
    Clock time;
    float last_time = 0;
    vector<Ant> colony, new_gen;
    vector<Resource> resourses;
    int count = 0;
    for (int i = 0; i <= stick_claster_count + food_cluster_count; ++i) {
        int x = abs(rand() % weidth - 300);
        int y = abs(rand() % high - 100);
        if (count <= food_cluster_count) create_cluster(resourses, x, y, food);
        else create_cluster(resourses, x, y, stick);
    }

    while (1) {
        if (time.getElapsedTime().asMilliseconds() - last_time >= update_time) {
            last_time = time.getElapsedTime().asMilliseconds();
            for (auto& ant : colony) ant.update();
        }
    }

	RenderWindow window(VideoMode(weidth, high), L"Муравейник");
    Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) if (event.type == Event::Closed) window.close();
        window.clear(Color::Green);
        window.display();
    }
	return 0;
}
#endif
