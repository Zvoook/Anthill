class Informer {
public:
    Informer(info_type type) : info(type), subs(0) {}
    info_type get_type() const { return info; }
    void add_sub(shared_ptr<Ant> ant) { subs.push_back(ant); }
    void remove_sub(shared_ptr<Ant> ant) { subs.erase(remove(subs.begin(), subs.end(), ant), subs.end()); }
    void send_info(const Position& pos, int size = 0, const Vector2f& direction = Vector2f(0, 0)) {
        for (auto& ant : subs) { ant->receive_info(info, pos, size, direction);}
    }
    void notice_food(const Position& pos, int size = 0) {
        for (auto& ant : subs) {ant->food_found(pos, size);}
    }
    void notice_stick(const Position& pos, int size = 0) {
        for (auto& ant : subs) {ant->stick_found(pos, size);}
    }
    void notice_corpse(const Position& pos, int size = 0) {
        for (auto& ant : subs) {ant->corpse_found(pos, size);}
    }
    void notice_aphid(const Position& pos, int size = 0) {
        for (auto& ant : subs) { ant->aphid_found(pos, size); }
    }
    void notice_trash(const Position& pos, int size = 0) {
        for (auto& ant : subs) { ant->trash_found(pos, size); }
    }
    /*void notice_enemy_sitter(const Position& pos, const Vector2f& direction = Vector2f(0, 0)) {
        for (auto& ant : subs) { ant->sitter_reaction(pos, direction); }
    }
    void notice_enemy_collector(const Position& pos, const Vector2f& direction = Vector2f(0, 0)) {
        for (auto& ant : subs) { ant->collector_reaction(pos, direction); }
    }
    void notice_enemy_builder(const Position& pos, const Vector2f& direction = Vector2f(0, 0)) {
        for (auto& ant : subs) { ant->builder_reaction(pos, direction); }
    }
    void notice_enemy_shepperd(const Position& pos, const Vector2f& direction = Vector2f(0, 0)) {
        for (auto& ant : subs) { ant->shepperd_reaction(pos, direction); }
    }
    void notice_enemy_soldier(const Position& pos, const Vector2f& direction = Vector2f(0, 0)) {
        for (auto& ant : subs) { ant->soldier_reaction(pos, direction); }
    }
    void notice_enemy_cleaner(const Position& pos, const Vector2f& direction = Vector2f(0, 0)) {
        for (auto& ant : subs) { ant->cleaner_reaction(pos, direction); }
    }*/
private:
    info_type info;
    vector<shared_ptr<Ant>> subs;
};
