#pragma once

#include "Rhombus.h"

class Pentagon : public Rhombus {
protected:
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

    virtual Point calculate_geometric_center() const override;
    virtual double calculate_area() const  override;

    bool operator==(const Pentagon&) const;
    bool operator!=(const Pentagon&) const;

    friend std::istream& operator>>(std::istream&, Pentagon&);
    friend std::ostream& operator<<(std::ostream&, const Pentagon&);
};