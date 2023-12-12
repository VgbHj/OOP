#pragma once

#include "FigureCreator.h"

class PentagonCreator : public FigureCreator
{
public:
    Figure* CreateFigure(const std::initializer_list<Point>& list) const override{
        FigureValidator val;
        val.Validate(typeid(Pentagon),list);
        return new Pentagon(list);
    }
};
