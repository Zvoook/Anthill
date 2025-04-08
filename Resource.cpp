// #include "Resource.h"
//
// void create_cluster(int& res_on_map, vector<Resource>& resources, float x, float y, res_type type)
// {
//     int res_in_cluster = rand() % 10 + 5;
//     for (int i = 0; i < res_in_cluster; ++i) {
//         float shift_x = (rand() % 100) - 50;
//         float shift_y = (rand() % 100) - 50;
//         res_on_map++;
//         int n = rand() % 100;
//         res_size size;
//         if (n < probability_of_small_resources) { size = small; }
//         else if (n < probability_of_small_resources + probability_of_medium_resources) { size = medium; }
//         else { size = big; }
//         Resource res(res_on_map, type, size);
//         res.set_posit(x + shift_x, y + shift_y);
//         resources.push_back(res);
//     }
// }