

#pragma once 

#include <cmath>
#include <iostream>

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
