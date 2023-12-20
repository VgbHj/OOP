#pragma once

#include "Figure.h"

class Rhombus : public Figure {
private:
    Point _p1;
    Point _p2;
    Point _p3;
    Point _p4;

public:
    Rhombus() = default;
    Rhombus(const Point&, const Point&, const Point&, const Point&);
    Rhombus(const std::initializer_list<Point>&);
    Rhombus(const Rhombus&);
    Rhombus(Rhombus&&);

    Rhombus& operator=(const Rhombus&);
    Rhombus& operator=(Rhombus&&);

    virtual ~Rhombus() = default;

    Point calculate_geometric_center() const override;
    double calculate_area() const override;

    bool operator==(const Rhombus&) const;
    bool operator!=(const Rhombus&) const;

    friend std::istream& operator>>(std::istream&, Rhombus&);
    friend std::ostream& operator<<(std::ostream&, const Rhombus&);
};