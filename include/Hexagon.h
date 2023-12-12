#pragma once

#include "Figure.h"

class Hexagon : public Figure {
private:
    Point _p1;
    Point _p2;
    Point _p3;
    Point _p4;
    Point _p5;
    Point _p6;

public:
    Hexagon() = default;
    Hexagon(const Point&, const Point&, const Point&, const Point&, const Point&, const Point&);
    Hexagon(const std::initializer_list<Point>&);
    Hexagon(const Hexagon&);
    Hexagon(Hexagon&&);

    Hexagon& operator=(const Hexagon&);
    Hexagon& operator=(Hexagon&&);

    virtual ~Hexagon() = default;

    Point calculate_geometric_center() const override;
    double calculate_area() const  override;

    bool operator==(const Hexagon&) const;
    bool operator!=(const Hexagon&) const;

    friend std::istream& operator>>(std::istream&, Hexagon&);
    friend std::ostream& operator<<(std::ostream&, const Hexagon&);
};