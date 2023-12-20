#pragma once
    
#include <iomanip>
#include <random>

#include <typeinfo> 
#include "Point.h"

class Figure {
protected:
    Figure() = default;

public:
    virtual ~Figure() = default;

    virtual Point calculate_geometric_center() const = 0;
    virtual double calculate_area() const = 0;
};