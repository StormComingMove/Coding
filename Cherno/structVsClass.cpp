// struct - variables are by default public. Inheritance is possible but little bit difficult

// class - variables are by default private 

#include <iostream>

#define LOG(x) std::cout << x << std::endl

struct animal{
	char* animal_name;
};



int main(void)
{
	LOG("Ganesh");
}