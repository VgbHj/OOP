#pragma once

#include "Figure.h"
#include "FigureValidator.h"

class FigureCreator
{
public:
    virtual ~FigureCreator(){};
    virtual Figure* CreateFigure(const std::initializer_list<Point>& list) const = 0;
};
