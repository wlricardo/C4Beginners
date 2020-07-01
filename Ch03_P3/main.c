/**<
     Create a dice game that uses two six-sided dice. Each time the
     program runs, use random numbers to assign values to each die
     variable. Output a “player wins” message to the user if the sum
     of the two dice is 7 or 11. Otherwise output the sum of the two
     dice and thank the user for playing */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIN 5
#define COL 3

int roll_dice() {
   srand(time(NULL));

   int i;
   int rnd;

   rnd = 1 + (rand() % 6);
   dice(rnd);

   return rnd;
}

void dice(int value) {
    int i;
    int j;

    switch (value)
    {
       case 1:
          printf("\n");
          for(i = 0; i < LIN; i++) {
             printf("   ");
             for (j = 0; j < COL; j++) {
                if (j==2) {
                   printf("%c", 219);
                } else {
                    printf(" ");
                }
             }
             printf("\n");
          }
       break;
       case 2:
          printf("\n");
          for(i = 0; i < LIN; i++) {
             printf("   ");
             for (j = 0; j < COL; j++) {
                if (((i==1) && (j <= 1)) || (i==3) && (j > 0)) {
                   printf(" ");
                } else {
                   printf("%c", 219);
                }
             }
             printf("\n");
          }
       break;
       case 3:
          printf("\n");
          for(i = 0; i < LIN; i++) {
             printf("   ");
             for (j = 0; j < COL; j++) {
                if ((j < 2) && (i % 2 != 0)) {
                   printf(" ");
                } else {
                   printf("%c", 219);
                }
             }
             printf("\n");
          }
       break;
       case 4:
          printf("\n");
          for(i = 0; i < LIN; i++) {
             printf("   ");
             for (j = 0; j < COL; j++) {
                if (((i==2) || (j==2)) || ((j==0) && (i<2))) {
                   printf("%c", 219);
                } else {
                   printf(" ");
                }
             }
             printf("\n");
          }
       break;
       case 5:
          printf("\n");
          for(i = 0; i < LIN; i++) {
             printf("   ");
             for (j = 0; j < COL; j++) {
                if (((i==1) && (j > 0)) || ((i==3) && (j < 2))) {
                   printf(" ");
                } else {
                   printf("%c", 219);
                }
             }
             printf("\n");
          }
       break;
       case 6:
          printf("\n");
          for(i = 0; i < LIN; i++) {
             printf("   ");
             for (j = 0; j < COL; j++) {
                if (((i==1) && (j > 0)) || ((i==3) && (j == 1))) {
                   printf(" ");
                } else {
                   printf("%c", 219);
                }
             }
             printf("\n");
          }
    }
}

int main()
{
   int sum = 0;
   int dice1, dice2;

   printf("\n Rolling dice1...\n");
   dice1=roll_dice();

   getchar();

   printf("\n Rolling dice2...\n");
   dice2=roll_dice();

   sum = dice1+dice2;
   printf("\n %c Dice1 : %d \n %c Dice2 : %d \n %c Sum   : %d", 178, dice1, 178, dice2, 178, sum);
   if ((sum == 7) || (sum == 11)) {
       printf("\n Player wins !!");
   }
   return 0;
}
