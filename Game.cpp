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
    makeText("Ants: " + to_string(anthill.get_ant_count()), Color::White);
    makeText("Enemies: " + to_string(raid.get_size()), Color::Red);
    makeText("Food: " + to_string(anthill.get_food_count()), Color(0, 255, 0));
    makeText("Sticks: " + to_string(anthill.get_stick_count()), Color(139, 69, 19));
    makeText("---------------", Color(200, 200, 200));
    makeText("Babies: " + to_string(anthill.get_baby_count()), Color::White);
    makeText("Sitters: " + to_string(anthill.get_sitter_count()), Color(255, 102, 178));
    makeText("Collectors: " + to_string(anthill.get_collector_count()), Color(255, 128, 0));
    makeText("Builders: " + to_string(anthill.get_builder_count()), Color::Yellow);
    makeText("Soldiers: " + to_string(anthill.get_soldier_count()), Color::Black);
    makeText("Shepherds: " + to_string(anthill.get_shepherd_count()), Color(0, 0, 204));
    makeText("Cleaners: " + to_string(anthill.get_cleaner_count()), Color(102, 51, 0));
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
            (y > window_high / 2 - 3 * start_radius && y < window_high / 2 + 3 * start_radius) || ((x < 0.2 * window_weidth) && (y<0.3*window_high)));
        if (i <= food_cluster_count) create_cluster(resources, x, y, food);
        else create_cluster(resources, x, y, stick);
    }
}