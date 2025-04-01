#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <memory>

using namespace std;

enum roles { baby = 1, sitter = 3, collector = 7, builder = 7, solder = 15, sheppert = 7, cleaner = 5 };
enum character { passive, agressive };
enum info_type { food_info, stick_info, enemy };
enum res_type { no_res, food, stick, body, trash };

double hipotenuse(int a, int b) { return sqrt(pow(a, 2) + pow(b, 2)); }

class Position {
    int x, y;
    Position(int a=0, int b=0) :x(a), y(b) {};
    float distance(const Position& last) { hipotenuse(x - last.x, y - last.y); }
    bool operator==(const Position& last) { return x == last.x && y == last.y; }
};

class Resource {
private:
    res_type type;
    int size;
    Position pos;
    bool collected;
public:
    Resource(res_type t = no_res, int s = 1, Position p) : size(s), collected(false), type(t), pos(p) { };
    res_type get_type() { return type; }
    int get_size() { return size; }
    Position get_position() { return pos; }
    void decrease_size() { if (size > 0) size--; }
    void collect() { collected = true; }
    bool is_collect() { return collected; }
};
