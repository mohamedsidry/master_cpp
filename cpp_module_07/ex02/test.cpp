#include "test.hpp"
#include "User.hpp"
template <typename T>


void echo(T& item);
void randomize(unsigned int & ref);
void user_on_test(void)
{
    Array<User> users(5);
    for (unsigned int i = 0; i < 5; i++)
    {
        users[i].setFirstName("first_name" + std::to_string(i));
        users[i].setLastName("last_name" + std::to_string(i));
        users[i].setMail(std::string("school-1337+student") + std::to_string(i) + "@gmail.com");
        users[i].getSkills()[0] = "C";
        users[i].getSkills()[1] = "C++";
        users[i].getSkills()[2] = "Bash";
        users[i].getSkills()[3] = "Python";
        users[i].getSkills()[4] = "Flutter";
        users[i].getSkills()[5] = "Java Script";
        users[i].getSkills()[6] = "Php";
    }
    users.iter(echo<User>);
    User user;
    int tmp(0);
    uintptr_t ss = reinterpret_cast<uintptr_t>(&tmp);
    std::cout << ss << std::endl << &user << std::endl;
}




void random_test(void)
{
    srand(time(NULL));
    Array<unsigned int> randoms(100);
    randoms.iter(randomize);
    randoms.iter(echo<unsigned int&>);
    //ForEach<unsigned int, void (*)(unsigned int&)> obj; obj(randoms, randoms.size(), randomize);
    //obj(randoms,randoms.size(), [](unsigned int &it){ std::cout << GREEN << it << RESET << ", ";});
}

void randomize(unsigned int & ref)
{
    ref = rand() % 100;
}


template <typename T>
void echo(T& item)
{
    std::cout <<  item << " "  << std::endl;
}


void ll(void)
{
    system("leaks -q executable");
}
