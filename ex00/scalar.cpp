#include "scalar.hpp"

ScalarConverter::~ScalarConverter(){
}

ScalarConverter::ScalarConverter(char *a){
    ar = a;
}

ScalarConverter::ScalarConverter(ScalarConverter const &cp){
    *this = cp;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &cpi){
    ar = cpi.ar;
    return *this;
}

void ScalarConverter::convert(std::string arg){
    if (checktype(arg) == 1){
        printchar(arg);
    }
    else if (checktype(arg) == 2){
        printint(arg);
    }
    else if (checktype(arg) == 3){
        printfloat(arg);
    }
    else if (checktype(arg) == 4){
        printdouble(arg);
    }
    else if (checktype(arg) == 5){
        printother(arg);
    }
    else
        std::cout << "invalid input" << std::endl;
}

void    printchar(std::string arg){
    char c = arg[0];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    if (isprint(c) && !(isdigit(c)))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << d << ".0" << std::endl;
}

void    printint(std::string arg){
    int i = std::atoi(arg.c_str());
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    if (isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << d << ".0" << std::endl;
}

void    printfloat(std::string arg){
    float f = std::atof(arg.c_str());
    int i = static_cast<int>(f);
    char c = static_cast<char>(f);
    double d = static_cast<double>(f);
    if (isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    if (f - i == 0)
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    if (d - i == 0)
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void    printdouble(std::string arg){
    double d = std::strtod(arg.c_str(), NULL);
    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);

    if (isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    if (f - i == 0)
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    if (d - i == 0)
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void printother(std::string arg){
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (arg == "+inf" || arg == "+inff"){
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (arg == "-inf" || arg == "-inff"){
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (arg == "nan"){
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else{
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}