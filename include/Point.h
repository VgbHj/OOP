#pragma once

#include <iostream>
#include <cmath>

class Point {
private:
    double _x;
    double _y;

public:
    Point();
    Point(double, double);
    Point(const std::initializer_list<double>&);
    Point(const Point&);
    Point(Point&&);

    Point& operator=(const Point&);
    Point& operator=(Point&&);

    const double get_x() const;
    const double get_y() const;

    void set_x(double);
    void set_y(double);

    double distance(const Point& other) const;

    bool operator==(const Point& other) const;

    friend std::istream& operator>>(std::istream&, Point&);
    friend std::ostream& operator<<(std::ostream&, const Point&);
};