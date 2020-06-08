// enums - nothing but an integer, just increase readbility of the code, and it also helps us to restrict \x variable in those enum values
// starts from 0 by default

#include <iostream>
#include "log.h"

enum Example : unsigned char
{
    A = 'a', B, C 
};

int main(void)
{
    Example x = A;

    if(x == 0)
        LOG("Ganesh");
    else
    {
        LOG(x);
        LOG(B);
    }
    

}