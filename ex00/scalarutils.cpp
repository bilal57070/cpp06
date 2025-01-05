#include "scalar.hpp"

int checktype(std::string arg){
    if(arg.size() == 1 && std::isprint(arg[0]) && !(isdigit(arg[0])))
        return (1);
    else if (isint(arg) == 1)
        return (2);
    else if (isfloat(arg))
        return (3);
    else if (isdouble(arg) == 1)
        return (4);
    else if (isother(arg) == 1)
        return (5);
    return (0);
}

bool isfloat(std::string arg){
    if (!arg.empty() && arg[arg.length() - 1] == 'f') {
            arg.erase(arg.length() - 1);
        }

        std::istringstream iss(arg);
        float f;
        iss >> f;

        if (iss.fail() || !iss.eof()) {
            return false;
        }
        return true;
    /*if (arg[arg.size() - 1] != 'f'){
        return false;
    }
    try{
        std::cout << "fef";
        char *end;
        //float f;
        size_t s;

        std::strtod(arg.c_str(), &end);
        s = static_cast <size_t> (end - arg.c_str());
        if (s != 0)
            return false;
    } 
    catch (const std::invalid_argument&) {
        return false;
    } catch (const std::out_of_range&) {
        return false;
    }
    return true;   */
}

bool  isdouble(std::string arg){
        std::istringstream iss(arg);
        double d;
        iss >> d;

        if (iss.fail() || !iss.eof()) {
            return false;
        }
        return true;
    /*try{
        char *end;
       // double d;
        size_t s;

        std::strtod(arg.c_str(), &end);
        s = static_cast <size_t> (end - arg.c_str());
        if (s != 0)
            return false;
    } 
    catch (const std::invalid_argument&) {
        return false;
    } catch (const std::out_of_range&) {
        return false;
    }
    return true;*/
}

bool isint(std::string arg){
    int i = 0;

    if (arg[i] == '-' || arg[i] == '+')
        i++;
    while (arg[i]){
        if (!std::isdigit(arg[i]))
            return false;
        i++;
    }
    return true;
}

bool isother(std::string arg){
    std::string other[] = {"-inff", "+inff", "-inf", "+inf", "nan"};

    for(int i = 0; i < 6; i++){
        if (arg == other[i])
            return true;
    }
    return false;
}