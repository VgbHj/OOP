#pragma once

#include "Figure.h"

class IFigureValidator
{
protected:
    IFigureValidator() = default;
public:
    virtual ~IFigureValidator(){};
    virtual void Validate(const std::initializer_list<Point>& list) = 0;
    virtual bool CheckType(const std::type_info &type) = 0;
};