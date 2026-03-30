



#include "ScalarConverter.h"


void    handl_char(std::string &str)
{
        char character = str[0];
        // char 
        std::cout << "char :" << character << std::endl;
        // int 
        std::cout << "int :" << static_cast<int>(character) << std::endl;
        // float 
        std::cout << "float :" << static_cast<float>(character) << "f" << std::endl;
        // double 
        std::cout << "double :" << static_cast<double>(character) << std::endl;
        return ;
}

void     ScalarConverter::convert(const std::string &str)
{
    // parsing to check the type of the input 
    std::string new_string = str;
    if (new_string.length() == 1 && !std::isdigit(new_string[0]))  // kassek matkhelich char ydoz hitach -double d = std::stod(s);- o s = "a" , ghadi throw exception 
        return handl_char(new_string);
    
    if(new_string.back() == 'f' &&  new_string != "+inf" && new_string != "nanf")
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
    if(std::isnan(dob) || std::isinf(dob) || dob > INT_MAX || dob < INT_MIN)
        std::cout << "int: impossible\n";
    else 
        std::cout << "int: " << static_cast<int>(dob) << "\n";
    // float
    std::cout << "float: " << static_cast<float>(dob) << "f\n";
    std::cout << "double: " << dob << "\n";
}



void ScalarConverter::convert(const std::string &str) {
    std::string new_string = str;

    // 1. Handle Single Char (e.g., "a", "*")
    if (new_string.length() == 1 && !std::isdigit(new_string[0])) {
        handle_char(new_string);
        return;
    }

    // 2. Handle numeric conversion with a safety net
    double dob;
    try {
        // Handling the 'f' suffix for floats manually for C++98 compatibility
        if (new_string.length() > 1 && new_string[new_string.length() - 1] == 'f' 
            && new_string != "+inf" && new_string != "-inf" && new_string != "nan") {
            new_string.erase(new_string.length() - 1);
        }
        
        // Use stod (C++11) or atof/strtod (C++98)
        dob = std::stod(new_string); 
    } catch (...) {
        // If "hello" or any garbage is passed, print impossible for everything
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }

    // 3. Display Char
    std::cout << "char: ";
    if (std::isnan(dob) || std::isinf(dob) || dob < 0 || dob > 127)
        std::cout << "impossible" << std::endl;
    else if (!isprint(static_cast<char>(dob)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(dob) << "'" << std::endl;

    // 4. Display Int
    std::cout << "int: ";
    if (std::isnan(dob) || std::isinf(dob) || dob > INT_MAX || dob < INT_MIN)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(dob) << std::endl;

    // 5. Display Float/Double with .0 precision
    print_floats(dob);
}


void print_floats(double dob) {
    // Check if there's a fractional part or if it's a special value
    bool hasDecimal = (dob - static_cast<long>(dob) != 0);

    std::cout << "float: " << static_cast<float>(dob);
    if (!hasDecimal && !std::isnan(dob) && !std::isinf(dob)) std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << dob;
    if (!hasDecimal && !std::isnan(dob) && !std::isinf(dob)) std::cout << ".0";
    std::cout << std::endl;
}
