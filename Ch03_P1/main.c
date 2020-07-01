/*
    Build a number guessing game that uses input validation
    (isdigit() function) to verify that the user has entered a digit
    and not a non-digit (letter). Store a random number between
    1 and 10 into a variable each time the program is run. Prompt
    the user to guess a number between 1 and 10 and alert the user
    if he was correct or not
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>

#define NUM 100

// FUNCTIONS DECLARATIONS
int validate_number(char *value);


// PROGRAM STARTS HERE
int main()
{
    srand(time(NULL));

    int rnd_number;
    char str_guess[3];
    int int_guess;
    int attempts = 0;

    rnd_number = 1 + (rand() % NUM);

    /* COUNTING ATTEMPTS */
    do
    {
        printf("\n What is your guess ? \n >> ");
        int_guess = validate_number(&str_guess);

        /* CHECKING IF NUMBER IS BETWEEN 1 AND 100 */
        if(int_guess > 100) {
            printf("\n Only integers between 1 and 100 allowed !");
        } else {
            attempts++;
            if (int_guess > rnd_number)
            {
                printf("\n Your guess is bigger than the actual number...");
            }
            else
            {
                printf("\n Your guess is smaller than the actual number...");
            }
        }
    } while ((int_guess != rnd_number) || (int_guess > 100));

    /* SHOWING RESULTS */
    printf("\n\n That's right !! %d is the secret !!", int_guess);
    printf("\n You found the number after %d attempts.\n\n", attempts);

    return 0;
}

// AVOID USER TO TYPE NON DIGITS CHARACTERS
int validate_number(char *value) {
    int i = 0;
    int number;
    char aux;

    do
    {
        aux = getch();
        if (isdigit(aux))
        {
            value[i] = aux;
            i++;
            printf("%c", aux);
        }
        else if (aux == 8 && i)
        {
            value[i] = '\0';
            i--;
            printf("\b \b");
        }
    } while (aux != 13);
    value[i] = '\0';

    number = atoi(value);
    return number;
}
