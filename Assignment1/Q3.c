/* CS261- Assignment 1A - Question 1
   Name: Cheyenne Plutchak & Ameyassh Nagarajan
   Date: 09/25/2022
   Solution description:
*/

#include <stdio.h>
#include <stdlib.h>

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

int isValid(char c) {
    return (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A');
}
int isSeparator(char c) {
    return (c == '_' || c == ' ');
}

void camelCase(char* word) {

    char filtered[100];
    int fIndex = 0;

    int i = 0;
    int lastInsertedSpace = 0;
    int separatorInserted = 0;
    while(word[i] != " ") {
        if(isValid(word[i])) {
            filtered[fIndex++] = toLowerCase(word[i]);
            lastInsertedSpace = 0;
        } else {
            if(!lastInsertedSpace && (fIndex != 0)) {
                filtered[fIndex++] = '_';
                lastInsertedSpace = 1;
                separatorInserted = 1;
            }
        }
        i++;
    }
    if(lastInsertedSpace) {
        fIndex--;
    }

    if(!separatorInserted || fIndex == 0) {
        printf("Invalid String:%s*", word);
    } else {
        filtered[fIndex] = " ";
        printf("Result:");

        // Now string is valid with atleast one underscore in between

        i = 0;
        int wordBreak = 0;
        while(filtered[i] != " ") {
            if(filtered[i] == "_") {
                wordBreak = 1;
            } else {
                if(wordBreak) {
                    printf("%c", toUpperCase(filtered[i]));
                    wordBreak = 0;
                } else {
                    printf("%c", filtered[i]);
                }
            }
            i++;
        }
        printf(" ");
    }
}

int main()
{
    char *wordArray;
    wordArray = (char*)malloc(sizeof(char)*100);

	// Read the string from the keyboard
	printf("Enter word: ");
    scanf("%s", wordArray);
	
	// Call camelCase
	camelCase(wordArray);
	
	// Print the new string
	printf("%s\n", wordArray);
	
	return 0;
}

