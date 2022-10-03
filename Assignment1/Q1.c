/* CS261- Assignment 1A - Question 1
   Name: Cheyenne Plutchak & Ameyassh Nagarajan
   Date: 09/25/2022
   Solution description:
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student
{
	int id;
	int score;
};

struct student* allocate()
{
     // Allocate memory for ten students*/
     struct student *studArray = (struct student*)malloc(sizeof(struct student)*10);
     
     // Return the pointer*/
     return studArray;
}

void generate(struct student* students)
{
     /* Seed random number generator */
     srand(time(NULL));

     /* Generate random and unique IDs and random scores for ten students, 
		IDs being between 1 and 10, scores between 0 and 100 */
     int i = 0;     
     for(i; i<10; i++){
          students[i].id=rand()%11;
          students[i].score=rand()%101;
     }     
     
}

void output(struct student* students)
{
     /* Output information about the ten students in the format:
        ID1 Score1
        ID2 score2
        ID3 score3
        ...
        ID10 score10*/

      int i = 0;
      for(i; i<10; i++){
          printf("ID%d %d\n",students[i].id,students[i].score);
      }  
}

void summary(struct student* students)
{
     /* Compute and print the minimum, maximum and average scores of the 
		ten students */

     int min = students[0].score;

     int i = 1;     
     for(i; i<10; i++){
          if(students[i].score < min){
               min = students[i].score;
          }
     } 

     int max = students[0].score;

     for(i; i<10; i++){
          if(students[i].score > max){
               max = students[i].score;
          }
     } 

     int sum;
     int j = 0;
     for(j; j<10; j++){
          sum = sum + students[j].score;
     }

     float avg = (float)sum / j;

     printf("Minimum Score:%d\n",min);
     printf("Maximum Score:%d\n",max);
     printf("Average Score:%.2f\n\n",avg);     
}

void deallocate(struct student* stud)
{
     // Deallocate memory from stud
     if(stud == NULL){
          printf("Memory not allocated.\n");
          exit(0);
     }
     else{
          free(stud);
     }
}

int main()
{
    struct student* stud = NULL;
    
    // Call allocate
    stud = allocate();
    
    // Call generate
    generate(stud);
    
    // Call output
    output(stud);
    
    // Call summary
    summary(stud);
    
    // Call deallocate
    deallocate(stud);

    return 0;
}
