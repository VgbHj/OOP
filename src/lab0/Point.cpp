#include "Point.h"

Point::Point() : _x(0), _y(0) {}
Point::Point(double x, double y) : _x(x), _y(y) {}

Point::Point(const std::initializer_list<double>& list) {
    if (list.size() != 2) {
        throw std::invalid_argument("Need two cords (x, y)");
    }

    _x = *(list.begin());
    _y = *(list.end() - 1);
}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point::Point(Point&& other) {
    this->_x = std::move(other._x);
    this->_y = std::move(other._y);
}

double Point::distance(const Point& other) const{
    return sqrt(pow(other.get_x() - this->get_x(), 2) + pow(other.get_y() - this->get_y(), 2));
};

Point& Point::operator=(const Point& other) {
    if (this == &other) return *this;

    this->_x = other._x;
    this->_y = other._y;
    return *this;
}

Point& Point::operator=(Point&& other) {
    this->_x = std::move(other._x);
    this->_y = std::move(other._y);
    return *this;
}

const double Point::get_x() const {
    return _x;
}

const double Point::get_y() const {
    return _y;
}

void Point::set_x(double new_x) {
    if (this->_x == new_x) return;

    this->_x = new_x;
}

void Point::set_y(double new_y) {
    if (this->_y == new_y) return;

    this->_y = new_y;
}

bool Point::operator==(const Point& other) const {
    return (this->_x == other._x && this->_y == other._y);
}


std::istream& operator>>(std::istream& is, Point& point) {
    is >> point._x >> point._y;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << point._x << " " << point._y;
    return os;
}
