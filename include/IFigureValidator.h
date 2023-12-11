#pragma once

class IFigureValidator
{
public:
    virtual void Validate(const std::initializer_list<Point>& list);
    virtual bool CheckType(const std::type_info &type);
};