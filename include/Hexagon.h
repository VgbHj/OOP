#pragma once

#include "Figure.h"
#include <vector>
#include <cmath>

template<class T>
class Hexagon : public Figure<T> {
using point = std::pair<T,T>;
private:
    std::vector<point> _points;

    T distance(const point p1, const point p2 ) const{
        return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
    };
public:
    Hexagon() = default;
    Hexagon(const point& p1, const point& p2, const point& p3, const point& p4, const point& p5, const point& p6){
        _points.push_back(p1);
        _points.push_back(p2);
        _points.push_back(p3);
        _points.push_back(p4);
        _points.push_back(p5);
        _points.push_back(p6);
        
    } 
    Hexagon(const std::initializer_list<point>& list){
        _points.insert(_points.end(), list.begin(), list.end());
    }
    Hexagon(const Hexagon<T>& other) : _points(other._points) {} 
    Hexagon(Hexagon<T>&& other){
        this->_points = std::move(other._points);
    }

    Hexagon<T>& operator=(const Hexagon<T>& other){
        if (this == &other) return *this;
        this->_points = other._points;
        return *this;
    }
    Hexagon<T>& operator=(Hexagon<T>&& other){
        this->_points = std::move(other._points);
        return *this;
    }

    virtual ~Hexagon() = default;

    point calculate_geometric_center() const override{
        return point((_points[0].first + _points[1].first + _points[2].first + _points[3].first + _points[4].first + _points[5].first) / 6.0, (_points[0].second + _points[1].second + _points[2].second + _points[3].second  + _points[4].second  + _points[5].second) / 6.0);
    }
    T calculate_area() const override{
        T area = 0.5 * fabs((_points[0].first*_points[1].second - _points[1].first*_points[0].second) + (_points[1].first*_points[2].second - _points[2].first*_points[1].second) + (_points[2].first*_points[3].second - _points[3].first*_points[2].second) + (_points[3].first*_points[4].second - _points[4].second*_points[3].second) + (_points[4].first*_points[0].second - _points[0].first*_points[4].second));
        return area;
    }

    bool operator==(const Hexagon& other) const{
        bool flag = true;
        for(size_t i = 0; i < _points.size(); ++i){
            flag = (_points[i] == other._points[i]);
        }

        return flag;
    }

    friend std::istream& operator>>(std::istream& is, Hexagon& romb){
        is >> romb._points[0].fisrt >> romb._points[0].second >>
        romb._points[1].fisrt >> romb._points[1].second >>
        romb._points[2].fisrt >> romb._points[2].second >>
        romb._points[3].fisrt >> romb._points[2].second >>
        romb._points[4].fisrt >> romb._points[2].second >>
        romb._points[5].fisrt >> romb._points[3].second;
        return is; 
    }
    friend std::ostream& operator<<(std::ostream& os, const Hexagon& romb){
        os << "Point_1 coordinates: " << romb._points[0].first << ' ' << romb._points[0].second << std::endl;
        os << "Point_2 coordinates: " << romb._points[1].first << ' ' << romb._points[1].second << std::endl;
        os << "Point_3 coordinates: " << romb._points[2].first << ' ' << romb._points[2].second << std::endl;
        os << "Point_4 coordinates: " << romb._points[3].first << ' ' << romb._points[3].second << std::endl;
        os << "Point_5 coordinates: " << romb._points[4].first << ' ' << romb._points[4].second << std::endl;
        os << "Point_6 coordinates: " << romb._points[5].first << ' ' << romb._points[5].second << std::endl;
        
        return os;
    }
};