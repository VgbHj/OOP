// Copyright 2023 SomeName

#include "Six.h"
#include <algorithm>
#include <cstring>

#define BASE 6

Six::Six(): _array{} {}

Six::Six(const size_t &n, unsigned char t){
    for(size_t i = 0; i < n; ++i)
        _array.push_back(t);
}

Six::Six(const std::initializer_list<unsigned char> &t){
    for(auto c : t){
        _array.push_back(c);
    }
}

Six::Six(const std::string &t){
    for(size_t i = 0; i < t.size(); ++i) _array.push_back(t[i]);
}

Six::Six(const Six &other){
    _array = other._array;
}

Six::Six(Six &&other) noexcept{
    _array = other._array;

    other._array = {};
}

std::ostream& operator<<(std::ostream& os, const Six& num) {
    for(size_t i = 0; i < num._array.size(); ++i){
        os << num._array[i];
    }
    return os;
}

int Six::take_int(int index=0) const{
    if(index >= this->_array.size()){
        return 0;
    }

    return this->_array[index] - '0';
}

void Six::remove_leading_zeros(){
    std::vector<unsigned char> new_array(this->_array.size()-1);
    for(size_t i = 0; i < new_array.size(); ++i){
        new_array[i] = this->_array[i+1];
    }

    this->_array = new_array;
}
Six Six::operator+(const Six& other){
    int carry = 0;
    int mx = std::max(this->_array.size(),other._array.size());
    for (size_t i=0; i < mx || carry; ++i) {
        if (i == this->_array.size()){
            this->_array.resize(this->_array.size()+1);
            for(int j = 1; j < this->_array.size(); ++j) this->_array[j] = this->_array[j-1];
            this->_array[0] = '0';
        }
        this->_array[this->_array.size()-i] = (unsigned char) ((int)this->_array[this->_array.size()-i] + carry + (other.take_int(other._array.size()-i)));
        carry = this->take_int(this->_array.size()-i) >= BASE;
        if (carry)  this->_array[this->_array.size()-i] = (unsigned char) ((int)this->_array[this->_array.size()-i] - BASE);
    }

    remove_leading_zeros();
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



Six::~Six() noexcept{}