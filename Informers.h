#pragma once
#include "Ant.h"
#include "Resource.h"
#include "Position.h"
#include <vector>
#include <cmath>

class Informers {
public:
    static void update(std::vector<Ant>& ants, std::vector<Resource>& resources) {
        for (Resource& res : resources) {
            if (!res.is_visible() || res.get_quantity() <= 0)
                continue;
            int requiredRole = -1;
            if (res.get_type() == food)
                requiredRole = 2;
            else if (res.get_type() == stick)
                requiredRole = 3;
            else if (res.get_type() == body || res.get_type() == trash)
                requiredRole = 6;
            if (requiredRole == -1)
                continue;
            for (Ant& ant : ants) {
                if (ant.get_role() != requiredRole || ant.has_valid_target()) continue;

                Position antPos = ant.get_pos();
                Position resPos = res.get_posit();
                float dx = antPos.x - resPos.x;
                float dy = antPos.y - resPos.y;
                float distance = std::sqrt(dx * dx + dy * dy);
                float vision = ant.get_vision_circle().getRadius();

                if (distance <= vision) {
                    ant.set_target(res.get_posit());
                    if (res.get_quantity() > res.get_request_ants()) {
                        for (Ant& helper : ants) {
                            if (&helper == &ant)
                                continue;
                            if (helper.get_role() == requiredRole && !helper.has_valid_target()) {
                                Position hPos = helper.get_pos();
                                float hdx = hPos.x - resPos.x;
                                float hdy = hPos.y - resPos.y;
                                float hdist = std::sqrt(hdx * hdx + hdy * hdy);
                                if (hdist <= helper.get_vision_circle().getRadius()) {
                                    helper.set_target(res.get_posit());
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
};
