



// #include "ScalarConverter.h"


// static void     convet(const std::string &str)
// {
    
// }


#include <iostream>
#include <string>
#include <cmath>


int main() {

    std::string input1 = "nan";
    std::string input2 = "inf";

    try{
        int x1 = std::stoi(input1);
        std::cout << "x1: " << x1 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "خطأ عند تحويل '" << input1 << "': " << e.what() << std::endl;
    }

    try {
        int x2 = std::stoi(input2); // ❌ سيعطي خطأ أيضاً
        std::cout << "x2: " << x2 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "خطأ عند تحويل '" << input2 << "': " << e.what() << std::endl;
    }


}