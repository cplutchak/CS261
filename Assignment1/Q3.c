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


void camelCase(char* word) 
{
    /*Convert to camelCase*/
    int sLength = stringLength(word);
    int i,j,first=0,change=0;

    //remove staring char '_',*,numbers,$ from starting
    for (i = 0; i < sLength; i++){
        if (word[0] == '_' || (word[0] >= 33 && word[0] <=64)){
            for (j = 0; j < sLength; j++){
                word[j] = word[j + 1];
            }
        --sLength;
        }
    }

    //remove any special chars if any in the string
    for (i = 0; i < sLength; i++){
        if (word[i] == '_' || (word[i] >= 33 && word[i] <= 64)){
            if (first == 0){
                word[i] = '_';
                first = 1;
            }

            for (j = i+first; j < sLength; j++){
                word[j] = word[j + 1];

            }
        --sLength;
        }
    }

    //remove trailing _ from word
    i = sLength-1;

    while (word[i] == '_'){
        i = --sLength;
    }

    word[i+1] = '\0';
    sLength = i + 1;

    //check if all the words upper before _
    for (i = 0; i < sLength; i++){
        if (word[i] == '_'){
            break;
        }
    if(isupper(word[i]))
    word[i] = toLowerCase(word[i]);
    }

    for(i = 0; i < sLength; i++){
        if (word[i] == '_'){
            if (islower(word[i + 1])){
                word[i] = toUpperCase(word[i + 1]);
                change = 1;
            }
            else{
                word[i + 1] = toLowerCase(word[i + 1]);
                change = 0;
            }

    //move all the elements after ith loc to left
        if(change == 1)
            for (j = i+1; j < sLength; j++){
                word[j] = word[j + 1];
            }
            --sLength;
        }
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

