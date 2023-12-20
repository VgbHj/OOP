#include "Rhombus.h"

Rhombus::Rhombus(const Point& p1, const Point& p2, const Point& p3, const Point& p4) : _p1(p1), _p2(p2), _p3(p3), _p4(p4) {
    // FigureValidator* valid;
    // valid->Validate(typeid(this), {p1, p2, p3, p4});
}
Rhombus::Rhombus(const std::initializer_list<Point>& list) {
    _p1 = *(list.begin());
    _p2 = *(list.begin()+1);
    _p3 = *(list.begin()+2);
    _p4 = *(list.end() - 1);
}
Rhombus::Rhombus(const Rhombus& other) :  _p1(other._p1), _p2(other._p2), _p3(other._p3), _p4(other._p4) {}
Rhombus::Rhombus(Rhombus&& other){
        this->_p1 = std::move(other._p1);
        this->_p2 = std::move(other._p2);
        this->_p3 = std::move(other._p3);
        this->_p4 = std::move(other._p4);
}

Rhombus& Rhombus::operator=(const Rhombus& other){
    if (this == &other) return *this;

        this->_p1 = other._p1;
        this->_p2 = other._p2;
        this->_p3 = other._p3;
        this->_p4 = other._p4;
        return *this;
}
Rhombus& Rhombus::operator=(Rhombus&& other){
    this->_p1 = std::move(other._p1);
    this->_p2 = std::move(other._p2);
    this->_p3 = std::move(other._p3);
    this->_p4 = std::move(other._p4);
    return *this;
}

Point Rhombus::calculate_geometric_center() const {
    return Point({(_p1.get_x() + _p2.get_x() + _p3.get_x() + _p4.get_x()) / 4.0}, {(_p1.get_y() + _p2.get_y() + _p3.get_y() + _p4.get_y()) / 4.0});
}

double Rhombus::calculate_area() const  {
    double d1 = this->_p1.distance(this->_p3);
    double d2 = this->_p2.distance(this->_p4);
    double area = 0.5 * d1 * d2;
    return area;
}

bool Rhombus::operator==(const Rhombus& other) const{
    return  this->_p1 == other._p1 &&
            this->_p2 == other._p2 &&
            this->_p3 == other._p3 &&
            this->_p4 == other._p4;
}

std::istream& operator>>(std::istream& is, Rhombus& rombus){
    is >> rombus._p1 >> rombus._p2 >> rombus._p3 >> rombus._p4;
    return is; 
}

std::ostream& operator<<(std::ostream& os, const Rhombus& rombus){
    os << "Point_1 coordinates: " << rombus._p1 << std::endl;
    os << "Point_2 coordinates: " << rombus._p2 << std::endl;
    os << "Point_3 coordinates: " << rombus._p3 << std::endl;
    os << "Point_4 coordinates: " << rombus._p4 << std::endl;
    return os;
    
}