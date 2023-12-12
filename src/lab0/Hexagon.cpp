#include "Hexagon.h"

Hexagon::Hexagon(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5, const Point& p6) : _p1(p1), _p2(p2), _p3(p3), _p4(p4), _p5(p5), _p6(p6) {
    
}
Hexagon::Hexagon(const std::initializer_list<Point>& list) {
    _p1 = *(list.begin());
    _p2 = *(list.begin()+1);
    _p3 = *(list.begin()+2);
    _p4 = *(list.begin()+3);
    _p5 = *(list.begin()+4);
    _p6 = *(list.end() - 1);
}
Hexagon::Hexagon(const Hexagon& other) :  _p1(other._p1), _p2(other._p2), _p3(other._p3), _p4(other._p4), _p5(other._p5), _p6(other._p6) {}
Hexagon::Hexagon(Hexagon&& other){
        this->_p1 = std::move(other._p1);
        this->_p2 = std::move(other._p2);
        this->_p3 = std::move(other._p3);
        this->_p4 = std::move(other._p4);
        this->_p5 = std::move(other._p5);
        this->_p6 = std::move(other._p6);
}

Hexagon& Hexagon::operator=(const Hexagon& other){
    if (this == &other) return *this;

        this->_p1 = other._p1;
        this->_p2 = other._p2;
        this->_p3 = other._p3;
        this->_p4 = other._p4;
        this->_p5 = other._p5;
        this->_p6 = other._p6;
        return *this;
}
Hexagon& Hexagon::operator=(Hexagon&& other){
    this->_p1 = std::move(other._p1);
    this->_p2 = std::move(other._p2);
    this->_p3 = std::move(other._p3);
    this->_p4 = std::move(other._p4);
    this->_p5 = std::move(other._p5);
    this->_p6 = std::move(other._p6);
    return *this;
}

Point Hexagon::calculate_geometric_center() const {
    return Point({(_p1.get_x() + _p2.get_x() + _p3.get_x() + _p4.get_x() + _p5.get_x() + _p6.get_x()) / 6.0}, {(_p1.get_y() + _p2.get_y() + _p3.get_y() + _p4.get_y() + _p5.get_y() + _p6.get_y()) / 6.0});
}

double Hexagon::calculate_area() const  {
    double area = 0.5 * fabs((_p1.get_x()*_p2.get_y() - _p2.get_x()*_p1.get_y()) + (_p2.get_x()*_p3.get_y() - _p3.get_x()*_p2.get_y()) + (_p3.get_x()*_p4.get_y() - _p4.get_x()*_p3.get_y()) + (_p4.get_x()*_p5.get_y() - _p5.get_y()*_p4.get_y()) + (_p5.get_x()*_p1.get_y() - _p1.get_x()*_p5.get_y()));
    return area;
}

bool Hexagon::operator==(const Hexagon& other) const{
    return  this->_p1 == other._p1 &&
            this->_p2 == other._p2 &&
            this->_p3 == other._p3 &&
            this->_p4 == other._p4 &&
            this->_p5 == other._p5 &&
            this->_p6 == other._p6;
}

std::istream& operator>>(std::istream& is, Hexagon& Hexagon){
    is >> Hexagon._p1 >> Hexagon._p2 >> Hexagon._p3 >> Hexagon._p4 >> Hexagon._p5 >> Hexagon._p6;
    return is; 
}

std::ostream& operator<<(std::ostream& os, const Hexagon& rombus){
    os << "Point_1 coordinates: " << rombus._p1 << std::endl;
    os << "Point_2 coordinates: " << rombus._p2 << std::endl;
    os << "Point_3 coordinates: " << rombus._p3 << std::endl;
    os << "Point_4 coordinates: " << rombus._p4 << std::endl;
    os << "Point_5 coordinates: " << rombus._p5 << std::endl;
    os << "Point_6 coordinates: " << rombus._p5 << std::endl;
    return os;
    
}