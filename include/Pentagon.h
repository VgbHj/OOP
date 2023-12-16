#pragma once

#include "Figure.h"
#include <vector>
#include <cmath>

template<class T>
class Pentagon : public Figure<T> {
using point = std::pair<T,T>;
private:
    std::vector<point> _points;

    T distance(const point p1, const point p2 ) const{
        return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
    };
public:
    Pentagon() = default;
    Pentagon(const point& p1, const point& p2, const point& p3, const point& p4, const point& p5){
        _points.push_back(p1);
        _points.push_back(p2);
        _points.push_back(p3);
        _points.push_back(p4);
        _points.push_back(p5);
        
    } 
    Pentagon(const std::initializer_list<point>& list){
        _points.insert(_points.end(), list.begin(), list.end());
    }
    Pentagon(const Pentagon<T>& other) : _points(other._points) {} 
    Pentagon(Pentagon<T>&& other){
        this->_points = std::move(other._points);
    }

    Pentagon<T>& operator=(const Pentagon<T>& other){
        if (this == &other) return *this;
        this->_points = other._points;
        return *this;
    }
    Pentagon<T>& operator=(Pentagon<T>&& other){
        this->_points = std::move(other._points);
        return *this;
    }

    virtual ~Pentagon() = default;

    point calculate_geometric_center() const override{
        return point((_points[0].first + _points[1].first + _points[2].first + _points[3].first + _points[4].first) / 5.0, (_points[0].second + _points[1].second + _points[2].second + _points[3].second  + _points[4].second) / 5.0);
    }
    T calculate_area() const override{
        T area = 0.5 * fabs((_points[0].first*_points[1].second - _points[1].first*_points[0].second) + (_points[1].first*_points[2].second - _points[2].first*_points[1].second) + (_points[2].first*_points[3].second - _points[3].first*_points[2].second) + (_points[3].first*_points[4].second - _points[4].second*_points[3].second) + (_points[4].first*_points[0].second - _points[0].first*_points[4].second));
        return area;
    }

    bool operator==(const Pentagon& other) const{
        bool flag = true;
        for(size_t i = 0; i < _points.size(); ++i){
            flag = (_points[i] == other._points[i]);
        }

        return flag;
    }

    friend std::istream& operator>>(std::istream& is, Pentagon& pent){
        is >> pent._points[0].fisrt >> pent._points[0].second >>
        pent._points[1].fisrt >> pent._points[1].second >>
        pent._points[2].fisrt >> pent._points[2].second >>
        pent._points[3].fisrt >> pent._points[2].second >>
        pent._points[4].fisrt >> pent._points[3].second;
        return is; 
    }
    friend std::ostream& operator<<(std::ostream& os, const Pentagon& pent){
        os << "Point_1 coordinates: " << pent._points[0].first << ' ' << pent._points[0].second << std::endl;
        os << "Point_2 coordinates: " << pent._points[1].first << ' ' << pent._points[1].second << std::endl;
        os << "Point_3 coordinates: " << pent._points[2].first << ' ' << pent._points[2].second << std::endl;
        os << "Point_4 coordinates: " << pent._points[3].first << ' ' << pent._points[3].second << std::endl;
        os << "Point_5 coordinates: " << pent._points[4].first << ' ' << pent._points[4].second << std::endl;
        
        return os;
    }
};