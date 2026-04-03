



#include "ScalarConverter.h"


void    handle_char(std::string &str)
{
        char character = str[0];
        std::cout << "char :" << character << std::endl;
        std::cout << "int :" << static_cast<int>(character) << std::endl;
        std::cout << "float :" << static_cast<float>(character) << "f" << std::endl;
        std::cout << "double :" << static_cast<double>(character) << std::endl;
        return ;
}


void print_floats(double dob)
{
    // Check if there's a fractional part or if it's a special value
    bool hasDecimal = (dob - static_cast<long>(dob) != 0);

    std::cout << "float: " << static_cast<float>(dob);
    if (!hasDecimal && !std::isnan(dob) && !std::isinf(dob)) std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << dob;
    if (!hasDecimal && !std::isnan(dob) && !std::isinf(dob)) std::cout << ".0";
    std::cout << std::endl;
}


void ScalarConverter::convert(const std::string &str) {
    std::string new_string = str;

     // Char (e.g., "a", "*")
    if (new_string.length() == 1 && !std::isdigit(new_string[0])) {
        handle_char(new_string);
        return;
    }

        // Check if the string is a pseudo-literal (science string)
        bool isSpecialFloat = (new_string == "nanf" || new_string == "+inff" || 
                       new_string == "-inff" || new_string == "inff");

        // Check if it's a normal float (ends in 'f' and isn't just the letter 'f')
        bool isNormalFloat = (new_string.length() > 1 && 
                      new_string[new_string.length() - 1] == 'f' && 
                      new_string != "+inf" && new_string != "-inf" && new_string != "nan");

        if (isSpecialFloat || isNormalFloat) {
        new_string.erase(new_string.length() - 1);
        }
        else if (new_string.length() > 1 && new_string[new_string.length() - 1] == 'f') {
        // For normal floats like 42.0f, we strip the f
        new_string.erase(new_string.length() - 1);
        }

    // 2. Handle numeric conversion with a safety net
        double dob;
        
        // Use stod (C++11) or atof/strtod (C++98)
        char *end; 
        dob = std::strtod(new_string.c_str(), &end);  // end pointer to tell you where it stops reading the string 
        if(*end != '\0')
        {
            std::cout << "char: impossible"<< std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return ;
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
