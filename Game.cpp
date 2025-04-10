#include "Game.h"

auto makeText = [&](const string& text, Color color, Font& font) {
    int line = 0;
    sf::Text t(text, font, 20);
    t.setFillColor(color);
    t.setPosition(10, 10 + line * 24);
    line++;
    Game::statsLines.push_back(t);
};

void Game::add_stats(Font& font)
{
    makeText("Ants: " + std::to_string(anthill.get_ant_count()), Color::White);
    makeText("Enemies: " + std::to_string(raid.size()), Color::Red);
    makeText("Food: " + std::to_string(anthill.get_food_count()), Color(0, 255, 0));
    makeText("Sticks: " + std::to_string(anthill.get_stick_count()), Color(139, 69, 19)); // Коричневый

    makeText("---------------", sf::Color(200, 200, 200));
    makeText("Babies: " + std::to_string(anthill.get_baby_count()), Color::White);
    makeText("Sitters: " + std::to_string(anthill.get_sitter_count()), Color(255, 102, 178));
    makeText("Collectors: " + std::to_string(game.anthill.get_collector_count()), Color(255, 128, 0));
    makeText("Builders: " + std::to_string(game.anthill.get_builder_count()), Color::Yellow);
    makeText("Soldiers: " + std::to_string(game.anthill.get_soldier_count()), sf::Color::Black);
    makeText("Shepherds: " + std::to_string(game.anthill.get_shepherd_count()), sf::Color(0, 0, 204));
    makeText("Cleaners: " + std::to_string(game.anthill.get_cleaner_count()), sf::Color(102, 51, 0));

}