#include <stdio.h>

#include <stdlib.h>



void createCharset(char a[], int useLower, int useUpper, int useDigits, int useSpecial);



void generateRandomPassword(char a[], int charsetSize, int length);



int main() {

    int length;

    int useLower, useUpper, useDigits, useSpecial;



    printf("\t----------------------------------------\n");

    printf("\tWelcome to the Password Generator!\n");

    printf("\t----------------------------------------\n");



    int inputValid = 0;

    do {

        printf("Enter the password length (min. 8, max. 128): ");

        scanf("%d", &length);

        if (length >= 8 && length <= 128) {

            inputValid = 1;

        } else {

            printf("Invalid length. Please enter a value between 8 and 128.\n");

        }

    } while (!inputValid);



    inputValid = 0;

    do {

        printf("Include lowercase letters? (1 for Yes, 0 for No): ");

        scanf("%d", &useLower);

        if (useLower == 0 || useLower == 1) {

            inputValid = 1;

        } else {

            printf("Invalid input. Please enter 0 or 1.\n");

        }

    } while (!inputValid);



    inputValid = 0;

    do {

        printf("Include uppercase letters? (1 for Yes, 0 for No): ");

        scanf("%d", &useUpper);

        if (useUpper == 0 || useUpper == 1) {

            inputValid = 1;

        } else {

            printf("Invalid input. Please enter 0 or 1.\n");

        }

    } while (!inputValid);



    inputValid = 0;

    do {

        printf("Include digits? (1 for Yes, 0 for No): ");

        scanf("%d", &useDigits);

        if (useDigits == 0 || useDigits == 1) {

            inputValid = 1;

        } else {

            printf("Invalid input. Please enter 0 or 1.\n");

        }

    } while (!inputValid);



    inputValid = 0;

    do {

        printf("Include special characters? (1 for Yes, 0 for No): ");

        scanf("%d", &useSpecial);

        if (useSpecial == 0 || useSpecial == 1) {

            inputValid = 1;

        } else {

            printf("Invalid input. Please enter 0 or 1.\n");

        }

    } while (!inputValid);



    char charset[100];

    createCharset(charset, useLower, useUpper, useDigits, useSpecial);

    int charSize = 0;

    do {

        if (charset[charSize] == '\0') {

            break;

        }

        charSize++;

    } while (1);



    if (charSize == 0) {

        printf("\tError:\n\t No character set selected.\n\tPlease enable at least one.\n");

        return 1;

    }



    printf("Generated Password:\n");

    printf("\n__________________\n");

    generateRandomPassword(charset, charSize, length);

    printf("\n__________________\n");

    printf("\nPassword Generation Complete!\n");

    printf("Please save your password in a secure location.\n");



    return 0;

}



void createCharset(char a[], int useLower, int useUpper, int useDigits, int useSpecial) {

    char lower[] = "abcdefghijklmnopqrstuvwxyz";

    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char digits[] = "0123456789";

    char special[] = "!@#$%%^&*()-_=+[]{}<>?/";



    int index = 0;

    int i = 0;

    if (useLower) {

        do {

            a[index++] = lower[i++];

        } while (i < 26);

    }



    i = 0;

    if (useUpper) {

        do {

            a[index++] = upper[i++];

        } while (i < 26);

    }



    i = 0;

    if (useDigits) {

        do {

            a[index++] = digits[i++];

        } while (i < 10);

    }



    i = 0;

    if (useSpecial) {

        do {

            a[index++] = special[i++];

        } while (i < 32);

    }



    a[index] = '\0'; // Null-terminate the string

}



void generateRandomPassword(char a[], int charsetSize, int length) {

    unsigned int seed = 12345;



    int i = 0;

    do {

        seed = (1103515245 * seed + 12345) % 2147483648;

        int index = seed % charsetSize;

        printf("%c", a[index]);

        i++;

    } while (i < length);

}
