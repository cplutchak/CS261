/* CS261- Assignment 1A - Question 2
   Name: Cheyenne Plutchak & Ameyassh Nagarajan
   Date: 09/25/2022
   Solution description:
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c)
{
    // Swap the addresses stored in the pointer variables a and b
   

    int s;
    
    s = *a;
    *a = *b;
    *b = s;
    
    // Decrement the value of integer variable c
    c = c - 1;
    return c;
    // Return c
}

int main()
{
    // Declare three integers x,y and z and initialize them randomly to values in [0,10]
    int x, y, z;
    srand(time(NULL));
    x = rand() % 10 + 1;
    y = rand() % 10 + 1;
    z = rand() % 10 + 1;
    
    
    // Print the values of x, y and z
    printf("%d \n",x);
    printf("%d \n",y);
    printf("%d \n",z);
    
    // Call foo() appropriately, passing x,y,z as parameters
    foo(&x, &y, z);
    
    // Print the values of x, y and z
    printf("%d \n",x);
    printf("%d \n",y);
    printf("%d \n",z);
    
    // Print the value returned by foo
    printf("value returned by foo is %d", z);

 
    
    return 0;
}
