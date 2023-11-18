#pragma once
#include <cstddef>
#include <array>
#include <string>
#include <iostream>

class Six
{
private:
    size_t _size;
    unsigned char *_array;
public:
    Six();
    Six(const size_t & n, unsigned char t = 0);
    Six(const std::initializer_list<unsigned char> &t);
    Six(const std::string &t);
    Six(const unsigned char *);

    Six(const Six& other);
    Six(Six&& other) noexcept;
    virtual ~Six() noexcept;


    Six& operator=(const Six&) noexcept;


    Six operator+(const Six&);
    Six operator-(const Six&);
    Six& operator+=(const Six&);
    Six& operator-=(const Six&);
    Six& operator++(int);
    Six& operator--(int);

    bool operator>(const Six&) const;
    bool operator<(const Six&) const;
    bool operator>=(const Six&) const;
    bool operator<=(const Six&) const;
    bool operator==(const Six&) const;
    bool operator!=(const Six&) const;

    int BASE_to_int() const;
    std::string int_to_BASE(int num);

    friend std::ostream& operator << (std::ostream &os, const Six &num);
};