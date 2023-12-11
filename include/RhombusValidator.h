#pragma once

#include "IFigureValidator.h"
#include "Rhombus.h"

class RhombusValidator : public IFigureValidator{

double calculateDistance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.get_x() - p1.get_x(), 2) + pow(p2.get_y() - p1.get_y(), 2));
}

bool areEqual(double a, double b) {
    return fabs(a - b) < 1e-6;
}

public:
    void Validate(const std::initializer_list<Point>& list) override{
        const Point& A = *(list.begin());
        const Point& B = *(list.begin()+1);
        const Point& C = *(list.begin()+2);
        const Point& D = *(list.end() - 1);
        double AB = calculateDistance(A, B);
        double BC = calculateDistance(B, C);
        double CD = calculateDistance(C, D);
        double DA = calculateDistance(D, A);
        double AC = calculateDistance(A, C);
        double BD = calculateDistance(B, D);

        // Check if all sides have equal length
        if (!areEqual(AB, BC) || !areEqual(BC, CD) || !areEqual(CD, DA) || !areEqual(DA, AB)) {
            throw std::invalid_argument("Введенные точки не образуют ромб");
        }

        // Calculate midpoints of diagonals
        Point M = {(A.get_x() + C.get_x()) / 2, (A.get_y() + C.get_y()) / 2};
        Point N = {(B.get_x() + D.get_x()) / 2, (B.get_y() + D.get_y()) / 2};

        // Check if diagonals bisect each other at right angles
        double slopeAC = (C.get_y() - A.get_y()) / (C.get_x() - A.get_x());
        double slopeBD = (D.get_y() - B.get_y()) / (D.get_x() - B.get_x());

        if(!areEqual(slopeAC * slopeBD, -1)){
            throw std::invalid_argument("Введенные точки не образуют ромб");
        } 
    }    

    bool CheckType(const std::type_info &type) override{
        return typeid(Rhombus) == type;
    }
};