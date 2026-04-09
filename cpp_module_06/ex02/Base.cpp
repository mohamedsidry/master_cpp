#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


/**
 * @brief ~Base - destructor .
*/
Base::~Base(){}


/**
 * @brief generate - generates a new object randomly of types {A, B, C} .
 * @return new object.
*/
Base * generate(void)
{
    int random = rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

/**
 * @brief identify - print the object type pointed to by ptr .
 * @param [in] ptr pointer to object .
*/
void identify(Base * ptr)
{
    if (dynamic_cast<A *>(ptr))
        std::cout << "Type : A" << std::endl;
    else if (dynamic_cast<B *>(ptr))
        std::cout << "Type : B" << std::endl;
    else if (dynamic_cast<C *>(ptr))
        std::cout << "Type : C" << std::endl;
    else
        std::cout << "Type : Base" << std::endl;
}

/**
 * @brief identify - print the object type reference by ref .
 * @param [in] ref reference to object .
*/
void identify(Base & ref)
{
    try
    {
        (void)dynamic_cast<A&>(ref);
        std::cout << "Type : A" << std::endl;
        return ;
    }
    catch(const std::bad_cast& e){}
    try
    {
        (void)dynamic_cast<B&>(ref);
        std::cout << "Type : B" << std::endl;
        return ;
    } catch(const std::bad_cast & e){}

    try
    {
        (void)dynamic_cast<C&>(ref);
        std::cout << "Type : C" << std::endl;
        return ;
    } catch (const std::bad_cast& e){}

    std::cout << "Type : Base" << std::endl;
}

