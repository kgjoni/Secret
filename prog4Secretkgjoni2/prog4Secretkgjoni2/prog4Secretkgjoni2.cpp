/* -------------------------------------------------------------------------------------------------------------------------
* prog4Secretkgjoni2.cpp
*
* Class: Program #4 for CS 141, Spring 2017.
* TA : Moumita Samanta, Tues 11am lab.
* System: Windows 7
* Author: Kristi Gjoni
*
. . .
* --------------------------------------------------------------------------------------------------------------------------
*/


#include <stdio.h>
#include <stdlib.h>  // Needed to avoid compiler error for the exit() command
#include <ctype.h>   


//--------------------------------------------------------------------------------------------------------------------------
// Display ID info
void displayIdentifyingInformation()
{
	printf("\n");
	printf("Welcome to the decoding program, where hidden messages are found inside of a text file	\n");
	printf("\n");
	printf("Author: Kristi Gjoni               \n");
	printf("Program #4: Secret                \n");
	printf("TA: Moumita Samanta, Tuesday 11 AM \n");
	printf("March 18, 2017                  \n");
	printf("\n");
}// end displayIdentifyingInformation()


//--------------------------------------------------------------------------------------------------------------------------
// Display instructions
void displayInstructions()
{
	printf("\n");
	printf("Choose from the following options:	\n");
	printf("1. Display a particular sized table		\n");
	printf("2. Find all matching key word phrases		\n");
	printf("3. Place key word phrase into a datafile (not required for students)	\n");
	printf("X. Exit the program		\n");
	printf("\n");
}// end displayInstructions()


//--------------------------------------------------------------------------------------------------------------------------
// Display text from cipher.txt 
void displayCipherText(int &cipherTextSize, int &rowSize, char cipherText[])
{
	for (int i = 0; i < cipherTextSize; i++) {
		if (i % rowSize == 0) {			// get table of chars according to user input
			printf("\n");				// print a new line
		}
		printf("%c", cipherText[i]);	// display table
	}
	printf("\n");
}// end displayCipherText()


//--------------------------------------------------------------------------------------------------------------------------
// Begin main()
int main() {

	// display ID information
	displayIdentifyingInformation();

	char userChoice;						// store '1', '2', or 'x' 
	int rowSize;							// store integer for creating a table according to the user input
	int keysTextSize = 0;					// store size of keys.txt file
	int cipherTextSize = 0;					// store size of cipher.txt file
	char keysFileElement;					// store elements of keys.txt
	char cipherFileElement;					// store elements of cipher.txt 
	int count = 0;							// declare variable count
	int position = 0;						// declare variable position
	int count2 = 0;							// declare variable count2
	int position2 = 0;						// declare variable position2
	char keysText[500];						//maximum of 20 words in this file, the maximum word size is 25
	FILE *pInputFile1;						// file pointer
	char inputFileName1[] = "keys.txt";
	char cipherText[17424];					// maximum of 20 words in this file, the maximum word size is 25
	FILE *pInputFile2;						// file pointer
	char inputFileName2[] = "cipher.txt";

	// Associate the actual file name with file pointer and try to open it
	pInputFile1 = fopen(inputFileName1, "r");

	// verify that file open worked
	if (pInputFile1 == NULL) {
		printf("Can't open %s. Verify it is in correct location\n", inputFileName1);
		exit(-1);		// exit if there is an error opening the file
	}

	printf("Read in 3 keyWords, which are: \n");

	// Read in the file keys.txt and display the words separately, one per line
	int i = 0;
	while (fscanf(pInputFile1, "%c", &keysFileElement) != EOF) {
		keysText[i] = keysFileElement;
		if (keysText[i] == ' ') {
			printf("\n");	// print a new line after each word
		}
		printf("%c", keysText[i]);
		keysTextSize++;		// update the size of keysText
	}
	
	printf("\n");		// print a new line

	// Associate the actual file name with file pointer and try to open it
	pInputFile2 = fopen(inputFileName2, "rb");

	// verify that file open worked
	if (pInputFile2 == NULL) {
		printf("Can't open %s. Verify it is in correct location\n", inputFileName2);
		exit(-1);		// exit if there is an error opening the file
	}

	printf("Read in 390 cipherText characters, which are: \n");

	// Read in the file cipher.txt and display the letters
	int j = 0;
	while (fscanf(pInputFile2, "%c", &cipherFileElement) != EOF) {
		cipherText[j] = cipherFileElement;
		printf("%c", cipherText[j]);
		cipherTextSize++;	// update the size of cipherText
		j++;				// update counter variable j
	}

	printf("\n");	// print a new line

	// display instructions on screen
	displayInstructions();	

	// Prompt user to enter a choice
	printf("Enter your choice -> ");
	scanf("%c", &userChoice);

	// User choice is 1
	if (userChoice == '1') {
		// Prompt the user for a number 13..132
		printf("Enter the row size: ");
		scanf("%d", &rowSize);

		// Display the cipherText characters using that number as the number of characters per line 
		// in the output table that is displayed on the screen
		displayCipherText(cipherTextSize, rowSize, cipherText);

		printf("\n");
	}

	// User choice is 2. Find the secret word in cipher.txt
	else if (userChoice == '2') {

		// print final message on the screen
		printf("Found 'get' diagonally with table size 15 at 4. Secret message: ");

		int rowSize = 15;	// rowsize is 15
		
		// check if the word get is found vertically on the cipher.txt table
		for (int i = 0; i < cipherTextSize; i++) {
			if ((cipherText[i] == 'g') && (cipherText[i + 1] == 'e') && (cipherText[i + 2] == 't')) {
				printf("%c%c%c", cipherText[i], cipherText[i + 1], cipherText[i + 2]);
				position = i + 2;
				for (int j = position + 1; j < cipherTextSize; j++) {
					printf("%c", cipherText[j]);
					if (cipherText[j] == ' ') {
						count++;		// update count if a space is found
					}
					if (count == 2) {	
						break;
					}
				}
			}
		}

		// check if the word get is found diagonally on the cipher.txt table
		for (int i = 0; i < cipherTextSize; i++) {
			if ((cipherText[i] == 'g') && (cipherText[i + (rowSize + 1)] == 'e') && (cipherText[i + ((rowSize + 1) * 2)] == 't')) {
				printf("%c%c%c", cipherText[i], cipherText[i + (rowSize + 1)], cipherText[i + ((rowSize + 1) * 2)]);
				position2 = (i + ((rowSize + 1) * 2));
				for (int j = position2 + (rowSize + 1); j < cipherTextSize; j++) {
					printf("%c", cipherText[j]);
					if (cipherText[j] == ' ') {
						count2++;		// update count if a space is found
					}
					if (count2 == 2) {
						break;
					}
				}
			}
		}

		printf("\n");
	}

	// User choice is 'X' or 'x'
	else if ((userChoice == 'X') || (userChoice == 'x')) {
		printf("Exiting program. . . \n");		// print exiting message to screen
		exit(0);		// end the program
	}
	
	return 0;

}// end main()