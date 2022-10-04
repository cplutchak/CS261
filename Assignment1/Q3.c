/* CS261- Assignment 1A - Question 1
   Name: Cheyenne Plutchak & Ameyassh Nagarajan
   Date: 09/25/2022
   Solution description:
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char toUpperCase(char ch)
{
    // Convert ch to upper case, assuming it is in lower case currently
    if(ch >= 'a' && ch <= 'z'){
        ch = ch - 32;
    }
    return ch;
}

char toLowerCase(char ch)
{
    // Convert ch to lower case, assuming it is in upper case currently
    if(ch >= 'A' && ch <= 'Z'){
        ch = ch + 32;
    }
    return ch;                          
}

int stringLength(char s[])
{
    // Return the length of the string
    int count = 0;

    while (s[count]!= '\0'){
        count++;
    }
    return count;
}

void camelCase( char* word){
    int i = 0, j = 0;

    while((word[j] = word[i]) != '\0'){
        if((word[j] >= 'a' && word[j] <= 'z') || (word[j] >= 'A' && word[j] <= 'Z')) {
            word[j] = toLowerCase(word[j]);
            j++, i++;
            continue;
        }
        while(!((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z'))) i++;
        if(word[i])
            word[j++] = toUpperCase(word[i++]);
    }
    word[0] = toLowerCase(word[0]);
}

int isValid(char *word){
    int i;
    for(i = 0; word[i] != '\0'; ++i)
    {
        if(((word[i] >= 'a' && word[i] <= 'z'))){
            return 0;
        }
        if(((word[i] >= '1' && word[i] <= '9'))){
            return 0;
        }
        else return 1;
    }
}

int main()
{
    char *wordArray;
    wordArray = (char*)malloc(sizeof(char)*100);

	// Read the string from the keyboard
	printf("Enter word: ");
    scanf("%s", wordArray);

    if(isValid(wordArray) == 0){
        printf("Invalid input string\n");
        return -1;
    }
	
	// Call camelCase
	camelCase(wordArray);
	
	// Print the new string
	printf("%s\n", wordArray);
	
	return 0;
}

