#pragma once

#include "Figure.h"

class Pentagon : public Figure {
private:
    Point _p1;
    Point _p2;
    Point _p3;
    Point _p4;
    Point _p5;

public:
    Pentagon() = default;
    Pentagon(const Point&, const Point&, const Point&, const Point&, const Point&);
    Pentagon(const std::initializer_list<Point>&);
    Pentagon(const Pentagon&);
    Pentagon(Pentagon&&);

    Pentagon& operator=(const Pentagon&);
    Pentagon& operator=(Pentagon&&);

    virtual ~Pentagon() = default;

    Point calculate_geometric_center() const override;
    double calculate_area() const  override;

    bool operator==(const Pentagon&) const;
    bool operator!=(const Pentagon&) const;

    friend std::istream& operator>>(std::istream&, Pentagon&);
    friend std::ostream& operator<<(std::ostream&, const Pentagon&);
};