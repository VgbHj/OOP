#pragma once
#include <iostream>
#include <concepts>
#include <memory>
#include <assert.h>

template <class T>
class Array
{
public:
    Array() : _size(0), _array{nullptr}
    {}

    Array(const std::initializer_list<T> &t)
    {
        _array = std::shared_ptr<T[]>(new T[t.size()]);
        size_t i{0};
        for (auto &c : t)
            _array[i++] = c;
        _size = t.size();
    }

    Array(const Array &other)
    {
        _size = other._size;
        _array = std::shared_ptr<T[]>(new T[_size]);

        for (size_t i{0}; i < _size; ++i)
            _array[i] = other._array[i];
    }

    Array(Array &&other) noexcept
    {
        _size = other._size;
        _array = other._array;

        other._size = 0;
        other._array = nullptr;
    }

    T& operator[](size_t index){
        assert(index<_size);
        return _array[index];
    }

    size_t size() const{
        return _size;
    }

    ~Array() noexcept
    {
        std::cout << "destructor:" << _array.use_count() << std::endl;
        // if (_size > 0)
        // {
        //     _size = 0;
        //     delete[] _array;
        //     _array = nullptr;
        // }
    }


    void AddElement(std::shared_ptr<Figure<double>> f){
        size_t newSize = _size + 1;
        auto newArray = std::shared_ptr<T[]>(new T[_size]);

        for (size_t i = 0; i < _size; ++i) {
            newArray[i] = _array[i];
        }

        newArray[_size] = f;

        _array = newArray;
        _size = newSize;
    }
    void DeleteElementbyIndex(const int index){
        if (index < 0 || index >= _size) {
            std::cout << "Invalid index.\n";
            return;
        }

        for (int i = index; i < _size - 1; ++i) {
            _array[i] = _array[i + 1];
        }

        --_size;

        auto newArray = std::shared_ptr<T[]>(new T[_size]);

        for (int i = 0; i < _size; ++i) {
            newArray[i] = _array[i];
        }

        _array = newArray;
    }
    void print_geometric_center() const{
        std::cout << std::endl << "Geometric center" << std::endl;
        for (size_t i = 0; i < _size; ++i) {
            std::cout << i << " " << _array[i]->calculate_geometric_center().first << ' '  << _array[i]->calculate_geometric_center().second << std::endl;
        }
    }
    void print_area() const{
        std::cout << std::endl << "Area" << std::endl;
        for (size_t i = 0; i < _size; ++i) {
            std::cout << i << " " << _array[i]->calculate_area() << std::endl;
        }
    }
    double calculate_total_area() const{
        double total_area { 0 };
        for (size_t i = 0; i < _size; ++i) {
            total_area += (_array[i])->calculate_area();
        }

        return total_area;
    }


    friend std::ostream& operator<<(std::ostream& os, const Array& num) {
        for(size_t i = 0; i < num._size; ++i){
            os << num._array[i];
        }
        return os;
    }


private:
    size_t _size;
    std::shared_ptr<T[]> _array;
};