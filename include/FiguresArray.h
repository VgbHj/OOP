#pragma once 

#include <Figure.h>
#include <cassert>

class FiguresArray
{
private:
    size_t _size;
    Figure** _array;
public:
    FiguresArray();
    FiguresArray(const size_t & n, Figure* t);
    FiguresArray(const std::initializer_list<Figure*> &t);
    FiguresArray(const FiguresArray *);

    FiguresArray(const FiguresArray& other);
    FiguresArray(FiguresArray&& other);
    virtual ~FiguresArray();

    void AddElement(Figure* f);
    void DeleteElementbyIndex(const int ind);
    void print_geometric_center() const;
    void print_area() const;
    double calculate_total_area() const;
    Figure* operator[](size_t index) const;
    size_t get_size() const;

    FiguresArray& operator=(const FiguresArray&);
    friend std::ostream& operator << (std::ostream &os, const FiguresArray &arr);
};
