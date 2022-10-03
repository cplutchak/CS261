/* CS261- Assignment 1A - Question 0
   Name: Ameyassh Nagarajan 
   Date:
   Solution description:
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

void fooA(int* iptr)
{
  
     // Print the value and address of the integer pointed to by iptr
     printf("output from fooA \n");
     printf("----------------- \n");
	 printf("value of the interger pointed by iptr is %d \n", *iptr);
	 printf("address of the integer pointed by iptr is %p \n", iptr);
	 
	 
          
     // Increment the value of the integer pointed to by iptr by 5
    
    *iptr = *iptr + 5;
		 
     // Print the address of iptr itself
	 printf("address of iptr is %p \n", &iptr);

	 printf("----------------- \n");
}


void fooB(int* jptr)
{
  
     // Print the value and address of the integer pointed to by jptr
     printf("output from fooB \n");
     printf("----------------- \n");
	 printf("value of the integer pointed by jptr is %d \n", *jptr);
	 printf("address of the integer pointed by jptr is %p \n", &jptr);
               
     // Decrement jptr by 1
    jptr = jptr - 1;
	 
      
     // Print the address of jptr itself
	 printf("the address of jptr is  %p \n", &jptr);
	 printf("----------------- \n");
	 
}


int main()
{
	
	
	
	
	
	
	
    
    // Declare an integer x and initialize it randomly to a value in [0,10]
	srand(time(NULL));
	int x = rand()%10 + 1;
    // int x = 5;
    // Print the value and address of x
	printf("value of x is %d \n", x);
	printf("address of x is %p \n", &x);
    
    // Call fooA() with the address of x
	fooA(&x);
    
    // Print the value of x
	printf("value of x is %d \n", x);
	printf("----------------- \n");
	/*value of x has changed after we pass it to fooA.
	Because we are changing the value of the integer
	thats is being pointed at by iptr, since iptr points to x the value of x changes.
	*/
	
    
    // Call fooB() with the address of x
	fooB(&x);
    
    // Print the value and address of x
	printf("value of x is %d \n", x);
	printf("address of x is %p \n", &x);
	printf("----------------- \n");
	/*the address of x has changed after we pass it to fooB.
	Because we are decreasing the value of jptr by 1.
	Since jptr stores the address of x it changes the address of x.
	*/
    
    return 0;
}
