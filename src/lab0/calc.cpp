#include "calc.h"

int sum_of_bin_digits(int a){
    int sum = 0;
    while(a){
        sum += a%2;
        a /= 2;
    }

    sum < 0 ? sum *= -1 : sum;
    return sum;
}

int sum_of_bin_range(int x, int y){
    int sum = 0;
    for(int i = x; i <= y; ++i){
        sum += sum_of_bin_digits(i);
    }
    return sum;
}