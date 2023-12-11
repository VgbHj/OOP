#pragma once

#include "IFigureValidator.h"
#include "RhombusValidator.h"
#include "PentagonValidator.h"
#include "HexagonValidator.h"
#include <vector>

class FigureValidator : IFigureValidator
{
private:
    std::vector<IFigureValidator> validators = {RhombusValidator(), HexagonValidator()};
public:
    void Validate(const std::type_info &type, const std::initializer_list<Point>& list){
        for(size_t i = 0; i < validators.size(); ++i){
            auto currentValidator = validators[i];

            if(currentValidator.CheckType(type)){
                currentValidator.Validate(list);
            }
        }
    }
};