#ifndef SCALAR_HPP
#define SCALAR_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include <cstdlib>
# include <sstream>


class ScalarConverter {
    private:
        std::string ar;
    public:
        ~ScalarConverter();
        ScalarConverter(char *a);
        ScalarConverter(ScalarConverter const &cp);
        ScalarConverter& operator=(ScalarConverter const &cpi);
        static void convert(std::string arg);
};

int checktype(std::string arg);
bool isfloat(std::string arg);
bool isdouble(std::string arg);
bool isint(std::string arg);
void printchar(std::string arg);
void printint(std::string arg);
void printfloat(std::string arg);
void printdouble(std::string arg);
bool isother(std::string arg);
void printother(std::string arg);

#endif