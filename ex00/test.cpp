

#include <bits/stdc++.h>
#include <cmath>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;


int main() {
    // A massive number that fits in a double, but not a float
    // double dob = 1.5e40;
    // float f = static_cast<float>(dob);

    // bool hasdecimaldoble = (dob - std::floor(dob) != 0.0);
    // bool hasdecimalfloat = (f - std::floor(f) != 0.0);

    // std::cout << "check for float " << (std::isinf(f) ? "yes" : "no ") <<std::endl;
    // std::cout << "check for double " << (std::isinf(dob) ? "yes" : "no ") <<std::endl;
    char tr = static_cast< char>(200);
    std::cout << "value as signed char: " << (int )tr << std::endl;
    std::cout << "is digit " << std::isdigit(static_cast< char >(tr)) << std::endl;
    return 0;
}
