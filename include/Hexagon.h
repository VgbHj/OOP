#pragma once

#include "Pentagon.h"

class Hexagon : public Pentagon {
private:
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

    virtual Point calculate_geometric_center() const override;
    virtual double calculate_area() const  override;

    bool operator==(const Hexagon&) const;
    bool operator!=(const Hexagon&) const;

    friend std::istream& operator>>(std::istream&, Hexagon&);
    friend std::ostream& operator<<(std::ostream&, const Hexagon&);
};