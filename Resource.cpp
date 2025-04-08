#include "Resource.h"
void create_cluster(int& res_on_map, vector<Resource>& resources, float x, float y, res_type type)
{
    int res_in_cluster = rand() % max_resource_in_claster + 1;
    for (int i = 0; i < res_in_cluster; ++i) {
        float shift_x = (rand() % dist_btw_res) - dist_btw_res/2;
        float shift_y = (rand() % dist_btw_res) - dist_btw_res/2;
        res_on_map++;
        int n = rand() % 100;
        res_size size;
        if (n < probability_of_small_resources) { size = small; }
        else if (n < probability_of_small_resources + probability_of_medium_resources) { size = medium; }
        else { size = big; }
        Resource res(res_on_map, type, size);
        res.set_posit(x + shift_x, y + shift_y);
        res.set_color(type);
        res.set_shape_size(size);
        resources.push_back(res);
    }
}

void Resource::set_color(res_type type)
{
    if (type == food) shape.setFillColor(Color(0, 153, 0));
    if (type == stick) shape.setFillColor(Color(115, 66, 34));
}