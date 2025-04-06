#pragma once
#include "Game Settings.h"
#include "Position.h"
class Resource {
private:
    res_type type;
    res_size size;
    Position pos;
    CircleShape shape;
    int id, ants_for_collecting;
    bool visible;
public:
    Resource(int id, res_type t = no_res, res_size s = small, Position p = Position()) : id(NULL), size(s), type(t), pos(p), visible(true) {
        ants_for_collecting = size * 2;
        shape.setRadius(small_resource_size);
        shape.setFillColor(Color::Red);
        shape.setPosition(pos.get_x(), pos.get_y());
    };
    void set_posit(float a, float b) { pos.set_pos(a, b); shape.setPosition(a, b); }
    res_type get_type() const { return type; }
    res_size get_size() const { return size; }
    Position get_posit() const { return pos; }
    int get_request_ants() const { return ants_for_collecting; }
    int get_id() const { return id; }
    bool is_visible() const { return visible; }
    void set_invisible() { visible = false; }
    void set_color(res_type type){
        if (type == food) shape.setFillColor(Color::Red);
        if (type == stick) shape.setFillColor(Color::Yellow);
    }
    void set_shape_size(int x) {shape.setRadius(x);}
    const CircleShape& get_shape() const { return shape; }
};
void create_cluster(int& res_on_map, vector<Resource>& resources, float x, float y, res_type type);