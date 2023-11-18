#include <iostream>

#include "Six.h"

using namespace std;

int main() {
    Six n1 {'5', '5', '5', '5'};
    Six n2 {'1'};
    cout << n1 << '\n';
    cout << n2 << '\n';
    cout << n1-n2 << '\n';
    n1 = n2;
    bool f = n1 == n2;
    cout << f;
}