



#include "ScalarConverter.h"


static void     convet(const std::string &str)
{
    // parsing to check the type of the input 
    std::string new_string = str;
    if(new_string.back() == 'f' && new_string != "+inf" && new_string != "+inf" && new_string != "nanf")
        new_string.pop_back();
    double dob = std::stod(new_string);
    // char
    if (dob < 0 || dob > 127 || std::isnan(dob) || std::isinf(dob))
        std::cout << "char: impossible\n";
    else if(!isprint(static_cast<char>(dob)))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(dob) << "'\n";
    
    // int 
    if(std::isnan(dob) || std::isinf(dob) || dob > __INT_MAX__ || dob < __INT_MIN__ )
}





// int
if (std::isnan(dob) || std::isinf(dob) || dob > INT_MAX || dob < INT_MIN)
    std::cout << "int: impossible\n";
else
    std::cout << "int: " << static_cast<int>(dob) << "\n";

// float
std::cout << "float: " << static_cast<float>(dob) << "f\n";

// double
std::cout << "double: " << dob << "\n";