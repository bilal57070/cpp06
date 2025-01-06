#include "Serializer.hpp"

serializer::serializer(){}

serializer::~serializer(){}

serializer::serializer(const serializer &cp){
    *this = cp;
}

serializer& serializer::operator=(const serializer &cpi){
    if (this == &cpi){
        return *this;
    }
    return *this;
}

uintptr_t serializer::serialize(Data* ptr){
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* serializer::deserialize(uintptr_t raw){
    return (reinterpret_cast<Data *>(raw));
}