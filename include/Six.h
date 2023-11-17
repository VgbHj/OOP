#pragma once
#include <cstddef>
#include <array>
#include <string>
#include <iostream>
#include <vector>

class Six
{
private:
    std::vector<unsigned char> _array;
    void remove_leading_zeros();
public:
    Six();
    Six(const size_t & n, unsigned char t = 0);
    Six(const std::initializer_list<unsigned char> &t);
    Six(const std::string &t);

    Six(const Six& other);
    Six(Six&& other) noexcept;
    virtual ~Six() noexcept;

    Six operator+(const Six&);
    Six operator-(const Six&);

    int take_int(int index) const;

    bool operator>(const Six&) const;
    bool operator<(const Six&) const;
    bool operator=(const Six&) const;


    friend std::ostream& operator << (std::ostream &os, const Six &num);
};

/*

*/
