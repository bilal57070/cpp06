#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <string>
# include <iostream>
# include <stdint.h>


typedef struct Data
{
    std::string v;
    int         val;
}               Data;


class serializer {
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private:
        serializer();
        ~serializer();
        serializer(const serializer &cp);
        serializer& operator=(const serializer &cpi);
};




#endif