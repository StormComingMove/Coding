// static - has two means inside class and outside

// outside - static is only belongs to that translation unit

// inside class - static variable or func is common for class or all the objects created by class
// static func will always refer or have only static variables

// local static - 

#include <iostream>

#define LOG(x) std::cout << x << std::endl

static int s_Variable = 10;

int main()
{
    LOG(s_Variable);
}