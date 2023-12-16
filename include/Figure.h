#pragma once

template<class T>
class Figure {
protected:
    Figure() = default;

public:
    virtual ~Figure() = default;

    virtual std::pair<T,T> calculate_geometric_center() const = 0;
    virtual T calculate_area() const = 0;
};