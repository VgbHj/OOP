#include <iostream>
#include "RhombusCreator.h"
#include "HexagonCreator.h"
#include "PentagonCreator.h"
#include "FiguresArray.h"

using namespace std;
int main() {
    FigureValidator* valid = new FigureValidator;
    valid->Validate(typeid(Rhombus), {Point(0,14), Point(-14,0), Point(0,-14), Point(14,0)});
    valid->Validate(typeid(Pentagon), {Point(5,17), Point(-14, 10), Point(-14,-10), Point(5,-17), Point(18,0)});
    valid->Validate(typeid(Hexagon), {Point(2,4), Point(-2,4), Point(-5,0), Point(-2,-4), Point(2,-4), Point(5,0)});

    FiguresArray f_arr;

    FigureCreator* rhombCreator = new RhombusCreator();
    FigureCreator* pentCreator = new PentagonCreator();
    FigureCreator* hexCreator = new HexagonCreator();
    Figure* rhomb = rhombCreator->CreateFigure({Point(0,14), Point(-14,0), Point(0,-14), Point(14,0)});
    Figure* hex = pentCreator->CreateFigure({Point(5,17), Point(-14, 10), Point(-14,-10), Point(5,-17), Point(18,0)});
    Figure* pent = hexCreator->CreateFigure({Point(2,4), Point(-2,4), Point(-5,0), Point(-2,-4), Point(2,-4), Point(5,0)});

    f_arr.AddElement(rhomb);
    f_arr.AddElement(hex);
    f_arr.AddElement(pent);

    f_arr.print_geometric_center();
    f_arr.print_area();
    f_arr.calculate_total_area();
}