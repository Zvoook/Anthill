#include <SFML/Graphics.hpp>
#include "Ants.h"
using namespace sf;

#define COLONY
#ifdef COLONY
int main() {
	RenderWindow window(VideoMode(1920, 1080), L"Муравейник");
    Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) window.close();
        }
        window.clear(Color::Green);
        window.display();
    }
	return 0;
}
#endif
