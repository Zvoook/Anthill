#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "Ants2.h"

#ifdef ANTS2
// Параметры окна и управления камерой
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float ZOOM_FACTOR = 1.1f;
const float PAN_SPEED = 10.0f;

// Для UI оставляем загрузку шрифта
sf::Font font;

// Функция загрузки ресурсов (только шрифт, так как геометрические фигуры не требуют текстур)
bool loadResources() {
    if (!font.loadFromFile("resources/arial.ttf")) {
        std::cerr << "Не удалось загрузить шрифт!" << std::endl;
        return false;
    }
    return true;
}

// Функция создания фигуры феромона (на основе CircleShape)
sf::CircleShape createPheromoneShape(const Pheromone& pheromone) {
    info_type type = pheromone.get_type();
    float intensity = pheromone.get_intensity() / 100.0f;
    sf::CircleShape shape(3.0f + intensity * 5.0f);

    switch (type) {
    case food_info:
        shape.setFillColor(sf::Color(0, 255, 0, static_cast<sf::Uint8>(100 * intensity)));
        break;
    case stick_info:
        shape.setFillColor(sf::Color(139, 69, 19, static_cast<sf::Uint8>(100 * intensity)));
        break;
    case enemy_info:
        shape.setFillColor(sf::Color(255, 0, 0, static_cast<sf::Uint8>(100 * intensity)));
        break;
    default:
        shape.setFillColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(100 * intensity)));
        break;
    }
    Position pos = pheromone.get_position();
    shape.setPosition(pos.x - shape.getRadius(), pos.y - shape.getRadius());
    return shape;
}

// Функция отрисовки информации о муравейнике (UI)
void drawAnthillInfo(sf::RenderWindow& window, const Anthill& anthill) {
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(14);
    text.setFillColor(sf::Color::White);

    std::string info = "Anthill Level: " + std::to_string(anthill.get_level()) +
        "\nFood: " + std::to_string(anthill.get_food_count()) +
        "\nSticks: " + std::to_string(anthill.get_stick_count()) +
        "\nAnts: " + std::to_string(anthill.get_ant_count()) +
        "\nCapacity: " + std::to_string(anthill.get_capacity());

    text.setString(info);
    text.setPosition(10, 10);

    window.draw(text);
}

// Функция отрисовки панели управления
void drawControls(sf::RenderWindow& window) {
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(12);
    text.setFillColor(sf::Color(200, 200, 200));

    std::string controls = "Controls:\n"
        "  WASD - Pan Camera\n"
        "  Mouse Wheel - Zoom In/Out\n"
        "  Space - Pause/Resume\n"
        "  R - Reset Zoom\n"
        "  Esc - Exit";

    text.setString(controls);
    text.setPosition(10, WINDOW_HEIGHT - 90);

    window.draw(text);
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Ant Colony Simulation");
    window.setFramerateLimit(60);

    if (!loadResources()) {
        return -1;
    }

    // Создаём муравейник в центре окна
    Position anthill_pos(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    Anthill anthill(anthill_pos);

    // Инициализируем камеру
    sf::View view = window.getDefaultView();

    bool paused = false;
    sf::Clock clock;
    float dt = 0.0f;

    while (window.isOpen()) {
        float elapsed = clock.restart().asSeconds();
        dt += elapsed;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                else if (event.key.code == sf::Keyboard::Space) {
                    paused = !paused;
                    std::cout << (paused ? "Simulation paused" : "Simulation resumed") << std::endl;
                }
                else if (event.key.code == sf::Keyboard::R) {
                    view = window.getDefaultView();
                }
            }
            else if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.delta > 0)
                    view.zoom(1.0f / ZOOM_FACTOR);
                else if (event.mouseWheelScroll.delta < 0)
                    view.zoom(ZOOM_FACTOR);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            view.move(0, -PAN_SPEED);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            view.move(0, PAN_SPEED);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            view.move(-PAN_SPEED, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            view.move(PAN_SPEED, 0);

        const float fixedStep = 1.0f / 60.0f;
        if (!paused && dt >= fixedStep) {
            dt -= fixedStep;
            anthill.update();
        }

        window.clear(sf::Color(50, 50, 50));
        window.setView(view);

        // Отрисовка феромонов
        const std::vector<Pheromone>& pheromones = anthill.get_pheromones();
        for (const Pheromone& pheromone : pheromones) {
            if (pheromone.is_active()) {
                sf::CircleShape pheromone_shape = createPheromoneShape(pheromone);
                window.draw(pheromone_shape);
            }
        }

        // Отрисовка ресурсов (используем геометрическую фигуру из Resource)
        const std::vector<Resource>& resources = anthill.get_resources();
        for (const Resource& resource : resources) {
            if (!resource.is_collected()) {
                window.draw(resource.get_shape());
            }
        }

        // Отрисовка врагов (используем геометрическую фигуру из Enemy)
        const std::vector<Enemy>& enemies = anthill.get_enemies();
        for (const Enemy& enemy : enemies) {
            if (!enemy.isDead()) {
                window.draw(enemy.get_shape());
            }
        }

        // Отрисовка муравейника (базы)
        window.draw(anthill.get_shape());

        // Отрисовка муравьев (используем геометрическую фигуру для тела)
        for (const auto& ant : anthill.get_ants()) {
            if (!ant->has_died()) {
                window.draw(ant->get_body());
            }
        }

        // Отрисовка UI (без камеры)
        window.setView(window.getDefaultView());
        drawAnthillInfo(window, anthill);
        drawControls(window);

        if (paused) {
            sf::Text pause_text;
            pause_text.setFont(font);
            pause_text.setCharacterSize(24);
            pause_text.setFillColor(sf::Color::Red);
            pause_text.setString("PAUSED");
            sf::FloatRect textRect = pause_text.getLocalBounds();
            pause_text.setOrigin(textRect.width / 2, textRect.height / 2);
            pause_text.setPosition(WINDOW_WIDTH / 2, 30);
            window.draw(pause_text);
        }

        window.display();
    }

    return 0;
}
#endif