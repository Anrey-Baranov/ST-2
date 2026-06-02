// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>

const double PI = 3.14159265358979323846;

Circle::Circle(double radius)
    : radius_(radius),
      ference_(2 * PI * radius),
      area_(PI * radius * radius) {}

void Circle::updateFromRadius() {
    ference_ = 2 * PI * radius_;
    area_ = PI * radius_ * radius_;
}

void Circle::updateFromFerence() {
    radius_ = ference_ / (2 * PI);
    area_ = PI * radius_ * radius_;
}

void Circle::updateFromArea() {
    radius_ = std::sqrt(area_ / PI);
    ference_ = 2 * PI * radius_;
}

void Circle::setRadius(double radius) {
    radius_ = radius;
    updateFromRadius();
}

void Circle::setFerence(double ference) {
    ference_ = ference;
    updateFromFerence();
}

void Circle::setArea(double area) {
    area_ = area;
    updateFromArea();
}

double Circle::getRadius() const { return radius_; }
double Circle::getFerence() const { return ference_; }
double Circle::getArea() const { return area_; }
