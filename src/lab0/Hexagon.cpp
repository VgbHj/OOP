#include "Hexagon.h"

Hexagon::Hexagon(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5, const Point& p6) : Pentagon(p1, p2, p3, p4, p5), _p6(p6) {}
    Hexagon::Hexagon(const std::initializer_list<Point>& list) {
    if (list.size() != 6) {
        throw std::invalid_argument("Need six points(p1, p2, p3, p4, p5, p6)");
    }
    

    _p1 = *(list.begin());
    _p2 = *(list.begin()+1);
    _p3 = *(list.begin()+2);
    _p4 = *(list.begin()+3);
    _p5 = *(list.begin()+4);
    _p6 = *(list.end() - 1);

}
    Hexagon::Hexagon(const Hexagon& other) :  Pentagon::Pentagon(other), _p6(other._p6){}
    Hexagon::Hexagon(Hexagon&& other) : Pentagon::Pentagon(other){
        this->_p6 = std::move(other._p6);
    }

    Hexagon& Hexagon::operator=(const Hexagon& other){
        if (this == &other) return *this;
        Pentagon::operator=(other);
        this->_p6 = other._p6;
        return *this;
    }
    Hexagon& Hexagon::operator=(Hexagon&& other){
        Pentagon::operator=(other);
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
        return  Pentagon::operator==(other) &&
                this->_p6 == other._p6;
    }

    std::istream& operator>>(std::istream& is, Hexagon& Hexagon){
        is >> static_cast<Pentagon&>(Hexagon) >> Hexagon._p6;
        return is; 
    }
    std::ostream& operator<<(std::ostream& os, const Hexagon& Hexagon){
        os << static_cast<const Pentagon&>(Hexagon);
        os << "Point_6 coordinates: " << Hexagon._p6 << std::endl;
        return os;
        
    }