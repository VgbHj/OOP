// Copyright 2023 SomeName

#include "Six.h"
#include <algorithm>
#include <cstring>

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

    other._size = 0;
    other._array = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Six& num) {
    for(size_t i = 0; i < num._size; ++i){
        os << num._array[i];
    }
    return os;
}

int Six::take_int(int index=0) const{
    if(index >= this->_size){
        return 0;
    }

    return this->_array[index] - '0';
}

void Six::increase_array(){
    unsigned char * new_a = new unsigned char[this->_size+1];
    this->_size = this->_size+1;
    new_a[0] = '0';
    for (int i = 1; i < this->_size; ++i)
        new_a[i] = this->_array[i-1];
    delete [] this->_array;
    this->_array = new_a;
}

void Six::remove_leading_zeros(){
    unsigned char * new_a = new unsigned char[this->_size-1];
    this->_size = this->_size-1;
    new_a[0] = '0';
    for (int i = 1; i < this->_size; ++i)
        new_a[i] = this->_array[i+1];
    delete [] this->_array;
    this->_array = new_a;
}

Six Six::operator+(const Six& other){
    int carry = 0;
    int mx = std::max(this->_size,other._size);
    for (size_t i=0; i < mx || carry; ++i) {
        if (i == this->_size){
            this->increase_array();
        }
        this->_array[this->_size-i] = (unsigned char) ((int)this->_array[this->_size-i] + carry + (other.take_int(other._size-i)));
        carry = this->take_int(this->_size-i) >= BASE;
        if (carry)  this->_array[this->_size-i] = (unsigned char) ((int)this->_array[this->_size-i] - BASE);
    }

    // remove_leading_zeros();
    return *this;
}

Six Six::operator-(const Six& other){
    // int carry = 0;
    // for (size_t i=0; i<b.size() || carry; ++i) {
    //     a[i] -= carry + (i < b.size() ? b[i] : 0);
    //     carry = a[i] < 0;
    //     if (carry)  a[i] += base;
    // }
    // while (a.size() > 1 && a.back() == 0)
    //     a.pop_back();
}



Six::~Six() noexcept{
    if(_size > 0){
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}