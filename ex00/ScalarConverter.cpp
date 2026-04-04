




#include "ScalarConverter.h"

static void print_floats(double dob) {
    bool hasDecimal = (dob - static_cast<long>(dob) != 0);

    std::cout << "float: " << static_cast<float>(dob);
    if (!hasDecimal && !std::isnan(dob) && !std::isinf(dob)) 
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << dob;
    if (!hasDecimal && !std::isnan(dob) && !std::isinf(dob)) 
        std::cout << ".0";
    std::cout << std::endl;
}

static void handle_char(const std::string &str) {
    if (str.length() == 1) {
        char character = str[0]; // Access the first character
        std::cout << "char: '" << character << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(character) << std::endl;
        print_floats(static_cast<double>(character));
    } else {
        std::cout << "char: impossible" << std::endl;
    }
}

void ScalarConverter::convert(const std::string &str) {
    std::string new_string = str;

    if (new_string.empty()) 
    {
        std::cout << "string is empty" << std::endl;    
        return;
    }
    
    if (new_string.length() == 1 && !std::isdigit(static_cast<unsigned char>(new_string[0]))) { 
        handle_char(new_string);
        return;
    }

    bool isSpecialFloat = (new_string == "nanf" || new_string == "+inff" || 
                           new_string == "-inff" || new_string == "inff");

    bool isNormalFloat = (new_string.length() > 1 && 
                          new_string[new_string.length() - 1] == 'f' && 
                          new_string != "+inf" && new_string != "-inf" && new_string != "nan");

    if (isSpecialFloat || isNormalFloat) {
        new_string.erase(new_string.length() - 1);
    }

    char *end;
    double dob = std::strtod(new_string.c_str(), &end); // it return 0.0 when it meets a char at beginning of the string 
                                                        // kat skipi waitespace "    42" dayza  
    if (*end != '\0') 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }

    std::cout << "char: ";
    if (std::isnan(dob) || std::isinf(dob) || dob < 0 || dob > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(dob)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(dob) << "'" << std::endl;

    std::cout << "int: ";
    if (std::isnan(dob) || std::isinf(dob) || dob > INT_MAX || dob < INT_MIN)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(dob) << std::endl;

    print_floats(dob);
}