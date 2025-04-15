#include "Game.h"
void Game::update(Font & font)
{
    Cemetery::set_current(&cemetery);
    ticks++;
    anthill.upd_anthill(ticks, resources);
    if (anthill.colony.size() > 0) has_started_colony = 1;
    statsLines.clear();
    add_stats(font);
    update_aphids();
    if (get_ticks() % enemy_wave_period == 0) raid.spawn_raid();
}

void Game::add_stats(Font& font) {
    int line = 0;
    auto makeText = [&](const string& text, Color color) {
        Text t(text, font, 18);
        t.setFillColor(color);
        t.setPosition(10, 10 + line * 20);
        statsLines.push_back(t);
        line++;
        };
    // Подсчет ресурсов типа "body" (трупы)
    int bodyResourcesCount = 0;
    for (const auto& res : resources) {
        if (res.is_visible() && res.get_type() == body) {
            bodyResourcesCount++;
        }
    }
    makeText("Ants: " + to_K(anthill.get_ant_count()) + " (" + to_K(anthill.get_max_ants()) + ")", Color::White);
    makeText("Enemies: " + to_string(raid.get_size()), Color::Red);
    makeText("Aphids: " + to_string(aphids.size()), Color(75, 0, 130));
    makeText("Food: " + to_K(anthill.get_food_count()) + " (" + to_K(anthill.get_max_food()) + ")", Color(0, 255, 0));
    makeText("Bodies: " + to_string(bodyResourcesCount), Color(134, 138, 142));
    makeText("Sticks: " + to_K(anthill.get_stick_count()) + " (FU: " + to_K(anthill.get_for_upd() - anthill.get_stick_count()) + ")", Color(139, 69, 19));
    makeText("---------------", Color(0, 0, 0));
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
    raid.crowd.clear();
    resources.clear();
    aphids.clear();
    statsLines.clear();
    ticks = 0;
    spawn_res();
}


void Game::spawn_res()
{
    for (int i = 0; i <= stick_claster_count + food_cluster_count; ++i) {
        int x, y;
        do {
            x = rand() % (window_width - 2 * dist_btw_res) + dist_btw_res;
            y = rand() % (window_height - 2 * dist_btw_res) + dist_btw_res;
        } while ((x > window_width / 2 - 3 * start_radius && x < window_width / 2 + 3 * start_radius) ||
            (y > window_height / 2 - 3 * start_radius && y < window_height / 2 + 3 * start_radius) || ((x < 0.2 * window_width) && (y < 0.3 * window_height)));
        if (i <= food_cluster_count) create_cluster(resources, x, y, food);
        else create_cluster(resources, x, y, stick);
    }
}

void Game::spawn_body()
{
    vector<size_t> ants_dead;
    for (size_t i = 0; i < anthill.colony.size(); i++) {
        if (anthill.colony[i].get_hp() <= 0 && !anthill.colony[i].is_already_dead()) {
            anthill.colony[i].dead(resources);
            ants_dead.push_back(i);
        }
    }
    for (int i = ants_dead.size() - 1; i >= 0; i--) {
        anthill.colony.erase(anthill.colony.begin() + ants_dead[i]);
    }
}

void Game::spawn_aphids() {
    for (int i = 0; i < aphid_cluster_count; ++i) {
        int x, y;
        do {
            x = rand() % (window_width - 2 * dist_btw_res) + dist_btw_res;
            y = rand() % (window_height - 2 * dist_btw_res) + dist_btw_res;
        } while ((x > window_width / 2 - 3 * start_radius && x < window_width / 2 + 3 * start_radius) ||
            (y > window_height / 2 - 3 * start_radius && y < window_height / 2 + 3 * start_radius) ||
            ((x < 0.2 * window_width) && (y < 0.3 * window_height)));

        int count = rand() % max_aphids_in_cluster + 1;
        create_aphid_cluster(aphids, x, y, count);
    }
}
