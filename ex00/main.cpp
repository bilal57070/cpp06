#include "scalar.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cout << "wrong nbr arg" << std::endl;
    }
    ScalarConverter test(av[1]);
    test.convert(av[1]);
    return (0);
}