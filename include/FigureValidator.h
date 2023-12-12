#pragma once

#include "RhombusValidator.h"
#include "PentagonValidator.h"
#include "HexagonValidator.h"
#include <vector>

class FigureValidator
{
    std::vector<IFigureValidator*>  validators = {
        new RhombusValidator,
        new PentagonValidator,
        new HexagonValidator
    };

public:
    void Validate(const std::type_info &type, const std::initializer_list<Point>& list){
        for(size_t i = 0; i < validators.size(); ++i){
            auto currentValidator = validators[i];

            if(currentValidator->CheckType(type)){
                currentValidator->Validate(list);
            }
        }
    }
};