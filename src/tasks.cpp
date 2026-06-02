// Copyright 2022 UNN-CS
#include "tasks.h"
#include <cmath>

const double PI = 3.14159265358979323846;

double calculateRopeGap(double radius_earth, double added_length) {
    Circle earth(radius_earth);
    double old_ference = earth.getFerence();
    double new_ference = old_ference + added_length;
    Circle new_circle;
    new_circle.setFerence(new_ference);
    return new_circle.getRadius() - earth.getRadius();
}

PoolCostResult calculatePoolCost(double pool_radius,
                                  double path_width,
                                  double concrete_price_per_sqm,
                                  double fence_price_per_meter) {
    Circle pool(pool_radius);
    Circle pool_with_path(pool_radius + path_width);

    double concrete_area = pool_with_path.getArea() - pool.getArea();
    double concrete_cost = concrete_area * concrete_price_per_sqm;
    double fence_length = pool_with_path.getFerence();
    double fence_cost = fence_length * fence_price_per_meter;
    double total_cost = concrete_cost + fence_cost;

    return {concrete_area, concrete_cost, fence_length, fence_cost,
            total_cost};
}
