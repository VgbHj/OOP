#pragma once

#include "FigureCreator.h"

class RhombusCreator : public FigureCreator
{
public:
    Figure* CreateFigure(const std::initializer_list<Point>& list) const override{
        FigureValidator val;
        val.Validate(typeid(Rhombus),list);
        return new Rhombus(list);
    }
};
