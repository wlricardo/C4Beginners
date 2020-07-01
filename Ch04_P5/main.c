/**<
      Modify the Concentration Game to use a main menu. The menu
      should allow the user to select a level of difficulty and/or quit
      the game (a sample menu is shown below). The level of difficulty
      could be determined by how many separate numbers the user
      has to concentrate on and/or how many seconds the player has
      to concentrate. Each time the user completes a single game of
      Concentration, the menu should reappear allowing the user to
      continue at the same level, at a new level, or simply quit the
      game.
      1 Easy (remember 3 numbers in 5 seconds)
      2 Intermediate (remember 5 numbers in 5 seconds)
      3 Difficult (remember 5 numbers in 2 seconds)
      4 Quit */

#include <stdio.h>
#include <stdlib.h>

void show_menu();
void game(char g);
void easy_lvl();
void intermediate_lvl();
void dificult_lvl();

int main()
{
   char op = '\0';

   do
   {
      show_menu();
      op = getchar(); fflush(stdin);
      if (op != 'Q') {
         game(op);
      }
   } while (op != 'Q');

   return 0;
}

void game(char g) {
   switch (g)
   {
   case 'E':
      easy_lvl();
      break;
   case 'I':
      intermediate_lvl();
      break;
   case 'D':
      dificult_lvl();
      break;
   default:
      printf("\n Invalid option!!\n");
   }
}

void show_menu() {

   printf("\n SELECT A LEVEL :");
   printf("\n [E] EASY ");
   printf("\n [I] INTERMEDIATE ");
   printf("\n [D] DIFICULT ");
   printf("\n [Q] QUIT \n >> ");
}

void easy_lvl() {
   srand(time(NULL));

   int i;
   int r1 = 0;
   int r2 = 0;
   int r3 = 0;
   int n[3] = {0,0,0};
   int elapsed_time = 0;
   int current_time = 0;

   for (i = 0; i < 3; i++) {
      n[i] = rand()%100;
   }

   printf("\n Concentrate on the next three numbers: %d %d %d", n[0], n[1], n[2]);

   current_time = time(NULL);
   do
   {
      elapsed_time = time(NULL);
   } while ((elapsed_time - current_time) < 5);

   system("CLS");
   printf("\n Enter each # separated with one space: ");
   scanf("%d%d%d", &r1, &r2, &r3); fflush(stdin);

   if(n[0] == r1 && n[1] == r2 && n[2] == r3) {
      printf("\n Congratulations !!\n");
   } else {
      printf("\n Sorry...The correct numbers were %d, %d and %d\n", n[0], n[1], n[2]);
   }
}

void intermediate_lvl() {
   srand(time(NULL));

   int i, ok = 0;
   int r[5] = {0,0,0,0,0};
   int n[5] = {0,0,0,0,0};
   int elapsed_time = 0;
   int current_time = 0;

   // Generating random numbers
   for (i=0; i<5; i++) {
      n[i] = rand()%100;
   }

   printf("\n Concentrate on the next five numbers: %d %d %d %d %d", n[0], n[1], n[2], n[3], n[4]);

   current_time = time(NULL);

   do
   {
      elapsed_time = time(NULL);
   } while (elapsed_time - current_time < 5);

   system("CLS");
   printf("\n Enter each # separated with ENTER:\n");
   for (i=0; i<5; i++) {
         printf(" >> ");
      scanf("%d", &r[i]); fflush(stdin);
   }

   for (i=0; i<5; i++) {
      if (n[i] == r[i]) {
         ok++;
      }
   }

   if (ok == 5) {
      printf("\n Congratulations !!\n");
   } else {
      printf("\n Sorry...The correct numbers were %d, %d, %d, %d and %d\n", n[0], n[1], n[2], n[3], n[4]);
   }
}

void dificult_lvl() {
   srand(time(NULL));

   int i, ok = 0;
   int n[5] = {0,0,0,0,0};
   int r[5] = {0,0,0,0,0};
   int elapsed_time = 0;
   int current_time = 0;

   // Generate numbers
   for (i=0; i<5; i++) {
      n[i] = rand()%100;
   }

   printf("\n Concentrate on the next five numbers: %d %d %d %d %d", n[0], n[1], n[2], n[3], n[4]);

   current_time = time(NULL);

   do
   {
      elapsed_time = time(NULL);
   } while ((elapsed_time - current_time) > 2);

   system("CLS");
   printf("\n Enter each # separated with ENTER:\n");
   for (i=0; i<5; i++) {
      printf(" >> ");
      scanf("%d", &r[i]); fflush(stdin);
   }

   for (i=0; i<5; i++) {
      if (n[i] == r[i]) {
         ok++;
      }
   }

   if (ok == 5) {
      printf("\n Congratulations !!\n");
   } else {
      printf("\n Sorry...The correct numbers were %d, %d, %d, %d and %d\n", n[0], n[1], n[2], n[3], n[4]);
   }
}
