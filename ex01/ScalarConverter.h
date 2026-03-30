

#pragma once 

#include <cmath>
#include <iostream>
#include  <climits>
#include <cstdlib> //header is typically used for string → number conversion in C++98?
class ScalarConverter 
{

    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &obj);
        ScalarConverter(const ScalarConverter &obj);    
    public:
        static void  convert(const std::string &str) ;
};
