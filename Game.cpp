#include "fix_for_macos.hpp"
#include "Game.h"
void Game::add_stats(Font& font) {
    int line = 0;
    auto makeText = [&](const string& text, Color color) {
        Text t(text, font, 20);
        t.setFillColor(color);
        t.setPosition(10, 10 + line * 24);
        statsLines.push_back(t);
        line++;
    };
    makeText("Ants: " + std::to_string(anthill.get_ant_count()), Color::White);
    makeText("Enemies: " + std::to_string(raid.get_size()), Color::Red);
    makeText("Food: " + std::to_string(anthill.get_food_count()), Color(0, 255, 0));
    makeText("Sticks: " + std::to_string(anthill.get_stick_count()), Color(139, 69, 19));
    makeText("---------------", Color(200, 200, 200));
    makeText("Babies: " + std::to_string(anthill.get_baby_count()), Color::White);
    makeText("Sitters: " + std::to_string(anthill.get_sitter_count()), Color(255, 102, 178));
    makeText("Collectors: " + std::to_string(anthill.get_collector_count()), Color(255, 128, 0));
    makeText("Builders: " + std::to_string(anthill.get_builder_count()), Color::Yellow);
    makeText("Soldiers: " + std::to_string(anthill.get_soldier_count()), Color::Black);
    makeText("Shepherds: " + std::to_string(anthill.get_shepherd_count()), Color(0, 0, 204));
    makeText("Cleaners: " + std::to_string(anthill.get_cleaner_count()), Color(102, 51, 0));
}

void Game::reset() {
    anthill = Anthill();
    raid.kill_raid();
    resources.clear();
    statsLines.clear();
    ticks = 0;
    spawn_res();
}

void Game::spawn_res()
{
    for (int i = 0; i <= stick_claster_count + food_cluster_count; ++i) {
        int x, y;
        do {
            x = rand() % (window_weidth - 2 * dist_btw_res) + dist_btw_res;
            y = rand() % (window_high - 2 * dist_btw_res) + dist_btw_res;
        } while ((x > window_weidth / 2 - 3 * start_radius && x < window_weidth / 2 + 3 * start_radius) ||
            (y > window_high / 2 - 3 * start_radius && y < window_high / 2 + 3 * start_radius));
        if (i <= food_cluster_count) create_cluster(resources, x, y, food);
        else create_cluster(resources, x, y, stick);
    }
}
