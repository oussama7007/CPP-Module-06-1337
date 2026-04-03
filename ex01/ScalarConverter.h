#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <cmath>
#include <iostream>
#include <climits>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cctype>

class ScalarConverter 
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);
        ScalarConverter &operator=(const ScalarConverter &obj);    
    
    public:
        static void convert(const std::string &str);
};

#endif