// Copyright 2022 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

#include "circle.h"
//Задача "Земля и веревка"
//Возвращает зазор между землей и веревкой в метрах
//radius_earth-радиус Земли в метрах
//added_length-добавленная длина веревки в метрах
double calculateRopeGap(double radius_earth, double added_length);

//Задача "Бассейн"
//pool_radius - радиус бассейна в метрах
//path_width - ширина дорожки в метрах
//concrete_price_per_sqm - цена за 1 кв.м бетона
//fence_price_per_meter - цена за 1 погонный метр ограды
//Возвращает структуру с результатами
struct PoolCostResult {
    double concrete_area;
    double concrete_cost;
    double fence_length;
    double fence_cost;
    double total_cost;
};

PoolCostResult calculatePoolCost(double pool_radius,
                                  double path_width,
                                  double concrete_price_per_sqm = 1000.0,
                                  double fence_price_per_meter = 2000.0);

#endif  // INCLUDE_TASKS_H_
