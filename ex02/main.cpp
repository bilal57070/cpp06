#include "Base.hpp"
#include <ctime>

Base   *generate(void){
    int r = rand() % 3;

    if (r == 0)
        return (new A);
    else if (r == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base *p){
    if (dynamic_cast<A*>(p))
        std::cout << "the object is of type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "the object is of type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "the object is of type C" << std::endl;
    else
        std::cout << "unknown type" << std::endl;
}

void identify(Base &p){
    try{
        dynamic_cast<A&>(p);
        std::cout << "the onject is of type A" << std::endl;
        return;
    }
    catch (std::exception &e){ 
        std::cout << "not type A" << std::endl;
    }
    try{
        dynamic_cast<B&>(p);
        std::cout << "the onject is of type B" << std::endl;
        return;
    }
    catch (std::exception &e){
        std::cout << "not type B" << std::endl;
    }
    try{
        dynamic_cast<C&>(p);
        std::cout << "the onject is of type C" << std::endl;
        return;
    }
    catch (std::exception &e){
        std::cout << "not type C" << std::endl;
    }
}

int main() { 
/*-------------------------------------------------- */
    std::cout << "test A:" << std::endl;
    Base* obj2 = new A;
    
    std::cout << "  Using pointer:" << std::endl;
    identify(obj2);

    std::cout << "  Using reference:" << std::endl;
    identify(*obj2);
    
    delete obj2;
/*-------------------------------------------------- */
    std::cout << "test B:" << std::endl;
    Base* obj3 = new B;
    
    std::cout << "  Using pointer:" << std::endl;
    identify(obj3);

    std::cout << "  Using reference:" << std::endl;
    identify(*obj3);
    
    delete obj3;
/*-------------------------------------------------- */
    std::cout << "test C:" << std::endl;
    Base* obj4 = new C;
    
    std::cout << "  Using pointer:" << std::endl;
    identify(obj4);

    std::cout << "  Using reference:" << std::endl;
    identify(*obj4);
    
    delete obj4;
/*-------------------------------------------------- */
    std::cout << "test generate:" << std::endl;
    Base* obj1 = generate();

    std::cout << "  Using pointer:" << std::endl;
    identify(obj1);

    std::cout << "  Using reference:" << std::endl;
    identify(*obj1);

    delete obj1;
    return 0;
}