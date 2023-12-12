#pragma once

#include "IFigureValidator.h"
#include "Hexagon.h"

class HexagonValidator : public IFigureValidator{

double calculateDistance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.get_x() - p1.get_x(), 2) + pow(p2.get_y() - p1.get_y(), 2));
}

bool areEqual(double a, double b) {
    return fabs(a - b) < 1e-6;
}


public:
    HexagonValidator() = default; 

    void Validate(const std::initializer_list<Point>& list) override{
        if (list.size() != 6) {
            throw std::invalid_argument("Need six points(p1, p2, p3, p4, p5, p6)");
        }

        const Point& A = *(list.begin());
        const Point& B = *(list.begin()+1);
        const Point& C = *(list.begin()+2);
        const Point& D = *(list.begin()+3);
        const Point& E = *(list.begin()+4);
        const Point& F = *(list.end() - 1);
        
        // Check if there are six unique points
        if (A.get_x() == B.get_x() && A.get_y() == B.get_y() && A.get_x() == C.get_x() && A.get_y() == C.get_y() && A.get_x() == D.get_x() && A.get_y() == D.get_y() &&
            A.get_x() == E.get_x() && A.get_y() == E.get_y() && A.get_x() == F.get_x() && A.get_y() == F.get_y()) {
            throw std::invalid_argument("Введенные точки не образуют шестиугольник");
        }

        double AB = calculateDistance(A, B);
        double BC = calculateDistance(B, C);
        double CD = calculateDistance(C, D);
        double DE = calculateDistance(D, E);
        double EF = calculateDistance(E, F);
        double FA = calculateDistance(F, A);

        // Check if the distances between consecutive vertices are non-zero
        if (areEqual(AB, 0) || areEqual(BC, 0) || areEqual(CD, 0) || areEqual(DE, 0) || areEqual(EF, 0) || areEqual(FA, 0)) {
            throw std::invalid_argument("Введенные точки не образуют шестиугольник");
        }

    }    

    bool CheckType(const std::type_info &type) override{
        return typeid(Hexagon) == type;
    }
};