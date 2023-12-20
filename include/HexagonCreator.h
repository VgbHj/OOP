#pragma once

#include "FigureCreator.h"

class HexagonCreator : public FigureCreator
{
public:
    Figure* CreateFigure(const std::initializer_list<Point>& list) const override{
        FigureValidator val;
        val.Validate(typeid(Hexagon),list);
        return new Hexagon(list);
    }
};
