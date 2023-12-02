#include "Pentagon.h"

Pentagon::Pentagon(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5) : Rhombus(p1, p2, p3, p4), _p5(p5) {}
    Pentagon::Pentagon(const std::initializer_list<Point>& list) {
    if (list.size() != 5) {
        throw std::invalid_argument("Need five points(p1, p2, p3, p4, p5)");
    }
    

    _p1 = *(list.begin());
    _p2 = *(list.begin()+1);
    _p3 = *(list.begin()+2);
    _p4 = *(list.begin()+3);
    _p5 = *(list.end() - 1);
}
    Pentagon::Pentagon(const Pentagon& other) :  Rhombus::Rhombus(other), _p5(other._p5){}
    Pentagon::Pentagon(Pentagon&& other) : Rhombus::Rhombus(other){
        this->_p5 = std::move(other._p5);
    }

    Pentagon& Pentagon::operator=(const Pentagon& other){
        if (this == &other) return *this;
        Rhombus::operator=(other);
        this->_p5 = other._p5;
        return *this;
    }
    Pentagon& Pentagon::operator=(Pentagon&& other){
        Rhombus::operator=(other);
        this->_p5 = std::move(other._p5);
        return *this;
    }

    Point Pentagon::calculate_geometric_center() const {
        return Point({(_p1.get_x() + _p2.get_x() + _p3.get_x() + _p4.get_x() + _p5.get_x()) / 5.0}, {(_p1.get_y() + _p2.get_y() + _p3.get_y() + _p4.get_y() + _p5.get_y()) / 5.0});
    }
    double Pentagon::calculate_area() const  {
        double area = 0.5 * fabs((_p1.get_x()*_p2.get_y() - _p2.get_x()*_p1.get_y()) + (_p2.get_x()*_p3.get_y() - _p3.get_x()*_p2.get_y()) + (_p3.get_x()*_p4.get_y() - _p4.get_x()*_p3.get_y()) + (_p4.get_x()*_p5.get_y() - _p5.get_y()*_p4.get_y()) + (_p5.get_x()*_p1.get_y() - _p1.get_x()*_p5.get_y()));
        return area;
    }
    bool Pentagon::operator==(const Pentagon& other) const{
        return  Rhombus::operator==(other) &&
                this->_p5 == other._p5;
    }

    std::istream& operator>>(std::istream& is, Pentagon& pentagon){
        is >> static_cast<Rhombus&>(pentagon) >> pentagon._p5;
        return is; 
    }
    std::ostream& operator<<(std::ostream& os, const Pentagon& pentagon){
        os << static_cast<const Rhombus&>(pentagon);
        os << "Point_5 coordinates: " << pentagon._p5 << std::endl;
        return os;
        
    }