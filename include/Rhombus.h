#pragma once

#include "Figure.h"
#include <vector>
#include <cmath>

template<class T>
class Rhombus : public Figure<T> {
using point = std::pair<T,T>;
private:
    std::vector<point> _points;

    T distance(const point p1, const point p2 ) const{
        return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
    };
public:
    Rhombus() = default;
    Rhombus(const point& p1, const point& p2, const point& p3, const point& p4){
        _points.push_back(p1);
        _points.push_back(p2);
        _points.push_back(p3);
        _points.push_back(p4);
        
    } 
    Rhombus(const std::initializer_list<point>& list){
        _points.insert(_points.end(), list.begin(), list.end());
    }
    Rhombus(const Rhombus<T>& other) : _points(other._points) {} 
    Rhombus(Rhombus<T>&& other){
        this->_points = std::move(other._points);
    }

    Rhombus<T>& operator=(const Rhombus<T>& other){
        if (this == &other) return *this;
        this->_points = other._points;
        return *this;
    }
    Rhombus<T>& operator=(Rhombus<T>&& other){
        this->_points = std::move(other._points);
        return *this;
    }

    virtual ~Rhombus() = default;

    point calculate_geometric_center() const override{
        return point((_points[0].first + _points[1].first + _points[2].first + _points[3].first) / 4.0, (_points[0].second + _points[1].second + _points[2].second + _points[3].second) / 4.0);

    }
    T calculate_area() const override{
        T d1 = distance(_points[0], _points[1]);
        T d2 = distance(_points[2], _points[3]);
        T area = 0.5 * d1 * d2;
        return area;
    }

    bool operator==(const Rhombus& other) const{
        bool flag = true;
        for(size_t i = 0; i < _points.size(); ++i){
            flag = (_points[i] == other._points[i]);
        }

        return flag;
    }

    friend std::istream& operator>>(std::istream& is, Rhombus& romb){
        is >> romb._points[0].fisrt >> romb._points[0].second >>
        romb._points[1].fisrt >> romb._points[1].second >>
        romb._points[2].fisrt >> romb._points[2].second >>
        romb._points[3].fisrt >> romb._points[3].second;
        return is; 
    }
    friend std::ostream& operator<<(std::ostream& os, const Rhombus& romb){
        os << "Point_1 coordinates: " << romb._points[0].first << ' ' << romb._points[0].second << std::endl;
        os << "Point_2 coordinates: " << romb._points[1].first << ' ' << romb._points[1].second << std::endl;
        os << "Point_3 coordinates: " << romb._points[2].first << ' ' << romb._points[2].second << std::endl;
        os << "Point_4 coordinates: " << romb._points[3].first << ' ' << romb._points[3].second << std::endl;
        
        return os;
    }
};