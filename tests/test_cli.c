#include <stdio.h>
#include "../include/repository.h"
#include "../include/package_manager.h"

int sum(int x, int y)
{
    return x + y;
}
int subtract(int x, int y)
{
    return x - y;
}
int multiply(int x, int y)
{
    return x * y;
}
 
int (*select(int choice))(int, int)
{
    switch (choice)
    {
        case INSTALL:
            return install_package;
        case 3:
            return multiply;
        default:
            return sum;
    }
}
int main(void)
{
    int (*operation)(int, int);   
    operation = select(1); 
    int result = operation(6, 4); 
    printf("result: %d \n", result); 
 
    return 0;
}