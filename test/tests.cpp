// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double PI = 3.14159265358979323846;
const double EPS = 1e-9;

TEST(CircleTest, ConstructorWithRadius) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 5.0, EPS);
    EXPECT_NEAR(c.getArea(), PI * 25.0, EPS);
}

TEST(CircleTest, DefaultConstructor) {
    Circle c;
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(CircleTest, SetRadiusUpdatesFerenceAndArea) {
    Circle c(2.0);
    c.setRadius(3.0);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 3.0, EPS);
    EXPECT_NEAR(c.getArea(), PI * 9.0, EPS);
}

TEST(CircleTest, SetRadiusZero) {
    Circle c(5.0);
    c.setRadius(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(CircleTest, SetFerenceUpdatesRadiusAndArea) {
    Circle c(2.0);
    c.setFerence(2 * PI * 4.0);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 4.0, EPS);
    EXPECT_NEAR(c.getRadius(), 4.0, EPS);
    EXPECT_NEAR(c.getArea(), PI * 16.0, EPS);
}

TEST(CircleTest, SetFerenceZero) {
    Circle c(5.0);
    c.setFerence(0.0);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(CircleTest, SetAreaUpdatesRadiusAndFerence) {
    Circle c(2.0);
    c.setArea(PI * 9.0);
    EXPECT_NEAR(c.getArea(), PI * 9.0, EPS);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 3.0, EPS);
}

TEST(CircleTest, SetAreaZero) {
    Circle c(5.0);
    c.setArea(0.0);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
}

TEST(CircleTest, GetRadius) {
    Circle c(7.5);
    EXPECT_DOUBLE_EQ(c.getRadius(), 7.5);
}

TEST(CircleTest, GetFerence) {
    Circle c(2.0);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 2.0, EPS);
}

TEST(CircleTest, GetArea) {
    Circle c(3.0);
    EXPECT_NEAR(c.getArea(), PI * 9.0, EPS);
}

TEST(CircleTest, MultipleUpdatesConsistency) {
    Circle c(1.0);
    c.setRadius(2.0);
    EXPECT_NEAR(c.getArea(), PI * 4.0, EPS);
    c.setArea(PI * 9.0);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
    c.setFerence(2 * PI * 5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, EPS);
}

TEST(CircleTest, NegativeRadius) {
    Circle c(-5.0);
    EXPECT_NEAR(c.getRadius(), -5.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * PI * (-5.0), EPS);
    EXPECT_NEAR(c.getArea(), PI * 25.0, EPS);
}

TEST(CircleTest, SetNegativeRadius) {
    Circle c(3.0);
    c.setRadius(-4.0);
    EXPECT_NEAR(c.getRadius(), -4.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * PI * (-4.0), EPS);
    EXPECT_NEAR(c.getArea(), PI * 16.0, EPS);
}

TEST(RopeGapTest, EarthWithOneMeterAddition) {
    double earth_radius = 6378100.0;
    double gap = calculateRopeGap(earth_radius, 1.0);
    EXPECT_NEAR(gap, 1.0 / (2 * PI), EPS);
}

TEST(RopeGapTest, SmallCircle) {
    double radius = 1.0;
    double gap = calculateRopeGap(radius, 1.0);
    EXPECT_NEAR(gap, 1.0 / (2 * PI), EPS);
}

TEST(RopeGapTest, ZeroAddition) {
    double radius = 100.0;
    double gap = calculateRopeGap(radius, 0.0);
    EXPECT_NEAR(gap, 0.0, EPS);
}

TEST(RopeGapTest, NegativeAddition) {
    double radius = 100.0;
    double gap = calculateRopeGap(radius, -1.0);
    EXPECT_NEAR(gap, -1.0 / (2 * PI), EPS);
}


TEST(PoolCostTest, DefaultValues) {
    auto result = calculatePoolCost(3.0, 1.0);
    double expected_concrete_area = PI * (16.0 - 9.0);
    EXPECT_NEAR(result.concrete_area, expected_concrete_area, EPS);
    EXPECT_NEAR(result.concrete_cost, expected_concrete_area * 1000.0, EPS);
    EXPECT_NEAR(result.fence_length, 2 * PI * 4.0, EPS);
    EXPECT_NEAR(result.fence_cost, 2 * PI * 4.0 * 2000.0, EPS);
    EXPECT_NEAR(result.total_cost, result.concrete_cost + result.fence_cost, EPS);
}

TEST(PoolCostTest, ZeroWidthPath) {
    auto result = calculatePoolCost(5.0, 0.0);
    EXPECT_NEAR(result.concrete_area, 0.0, EPS);
    EXPECT_NEAR(result.concrete_cost, 0.0, EPS);
    EXPECT_NEAR(result.fence_length, 2 * PI * 5.0, EPS);
}

TEST(PoolCostTest, CustomPrices) {
    auto result = calculatePoolCost(3.0, 1.0, 500.0, 1000.0);
    double expected_concrete_area = PI * 7.0;
    EXPECT_NEAR(result.concrete_cost, expected_concrete_area * 500.0, EPS);
    EXPECT_NEAR(result.fence_cost, 2 * PI * 4.0 * 1000.0, EPS);
}

TEST(PoolCostTest, LargePool) {
    auto result = calculatePoolCost(100.0, 10.0);
    double expected_concrete_area = PI * (110.0 * 110.0 - 100.0 * 100.0);
    EXPECT_NEAR(result.concrete_area, expected_concrete_area, EPS);
    EXPECT_NEAR(result.fence_length, 2 * PI * 110.0, EPS);
}

TEST(PoolCostTest, VerySmallPool) {
    auto result = calculatePoolCost(0.5, 0.2);
    double expected_concrete_area = PI * (0.7 * 0.7 - 0.5 * 0.5);
    EXPECT_NEAR(result.concrete_area, expected_concrete_area, EPS);
    EXPECT_NEAR(result.fence_length, 2 * PI * 0.7, EPS);
}
