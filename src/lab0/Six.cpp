
// Copyright 2023 SomeName

#include "Six.h"
#include <algorithm>
#include <cstring>
#include <math.h>

#define BASE 6

Six::Six(): _size(0), _array{nullptr} {}

Six::Six(const size_t &n, unsigned char t){
    _array = new unsigned char[n];
    for(size_t i = 0; i < n; ++i)
        _array[i] = t;
    _size = n;
}

Six::Six(const std::initializer_list<unsigned char> &t){
    _array = new unsigned char[t.size()];
    size_t i{0};
    for(auto c : t){
        _array[i++] = c;
    }
    _size = t.size();
}

Six::Six(const std::string &t){
    _array = new unsigned char[t.size()];
    _size = t.size();
    for(size_t i = 0; i < _size; ++i) _array[i] = t[i];
}


Six::Six(const Six &other){
    _size = other._size;
    _array = new unsigned char[_size];

    for(size_t i = 0; i < _size; ++i) _array[i] = other._array[i];
}

Six::Six(Six &&other) noexcept{
    _size = other._size;
    _array = other._array;

    other.~Six();
}
std::ostream& operator<<(std::ostream& os, const Six& num) {
    for(size_t i = 0; i < num._size; ++i){
        os << num._array[i];
    }
    return os;
}


int Six::BASE_to_int() const{
    int num = 0;
    for(size_t i = 0; i < _size; ++i){
        num += (_array[_size-i-1] - '0') * pow(BASE, i);
    }

    return num;
}

int log_a_to_base_b(int a, int b)
{
    return log2(a) / log2(b);
}

std::string Six::int_to_BASE(int num){
    int new_size = log_a_to_base_b(num, BASE) + (num >= pow(BASE, log_a_to_base_b(num, BASE)));
    std::string new_s;
    while(num){
        new_s = new_s + std::to_string(num%BASE);
        num /= BASE;
    }

    std::reverse(new_s.begin(), new_s.end());

    return new_s;
}

Six Six::operator+(const Six& other){
    int a = BASE_to_int(), b = other.BASE_to_int();
    return Six(int_to_BASE(a+b));
}

Six Six::operator-(const Six& other){
    int a = BASE_to_int(), b = other.BASE_to_int();
    return Six(int_to_BASE(a-b));

}

Six& Six::operator=(const Six& other) noexcept{
    if(&other != this)
    {
        _size = other._size;
        _array = new unsigned char[_size];

        for(size_t i = 0; i < _size; ++i) _array[i] = other._array[i];
    }
    return *this;
}

Six& Six::operator+=(const Six& other){
    *this = *this + other;
    return *this;
}

Six& Six::operator-=(const Six& other){
    *this = *this - other;
    return *this;
}

Six& Six::operator++(int){
    int a = BASE_to_int();
    Six tmp_S = Six(int_to_BASE(a+1));
    *this = tmp_S;
    return *this;
}

Six& Six::operator--(int){
    int a = BASE_to_int();
    Six tmp_S = Six(int_to_BASE(a-1));
    *this = tmp_S;
    return *this;
}

bool Six::operator<(const Six& other) const{
    return this->BASE_to_int() < other.BASE_to_int();
}
bool Six::operator>(const Six& other) const{
    return this->BASE_to_int() > other.BASE_to_int();
}
bool Six::operator==(const Six& other) const{
    return this->BASE_to_int() == other.BASE_to_int();
}
bool Six::operator<=(const Six& other) const{
    return this->BASE_to_int() <= other.BASE_to_int();
}
bool Six::operator>=(const Six& other) const{
    return this->BASE_to_int() >= other.BASE_to_int();
}
bool Six::operator!=(const Six& other) const{
    return this->BASE_to_int() != other.BASE_to_int();
}


Six::~Six() noexcept{
    if(_size > 0){
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}