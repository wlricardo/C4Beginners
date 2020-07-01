#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void display_board();
int verify_selection(int, int);
void check_for_winner();

/* Global variables */
char board[9];
char winner = ' ';
int current_player = 0;

/* *** MAIN FUNCTION *** */
int main()
{
   int x;
   int square_num = 0;

   for (x=0; x<9; x++) {
      board[x] = ' ';
   }

   display_board();

   while (winner == ' ') {
      printf("\n %c\n", winner);

      if (current_player == 1 || current_player == 0) {
         printf("\n Player X");
         printf("\n Enter a available square [1-9] : ");
         scanf("%d", &square_num); fflush(stdin);

         if (verify_selection(square_num, current_player)) {
            current_player = 1;
         } else {
            current_player = 2;
         }
      } else {
         printf("\n Player O");
         printf("\n Enter a available square [1-9] : ");
         scanf("%d", &square_num); fflush(stdin);

         if (verify_selection(square_num, current_player)) {
            current_player = 2;
         } else {
            current_player = 1;
         }
      }
      display_board();
      check_for_winner();
   }

   return 0;
}

/* Function display_board() */
void display_board() {
   system("CLS");
   printf("   \n\t|\t|\n");
   printf("   \t|\t|\n");
   printf("   %c\t|%c\t|%c\n", board[0], board[1], board[2]);
   printf(" -------+-------+--------\n");
   printf("   \t|\t|\n");
   printf("   %c\t|%c\t|%c\n", board[3], board[4], board[5]);
   printf(" -------+-------+--------\n");
   printf("   \t|\t|\n");
   printf("   %c\t|%c\t|%c\n", board[6], board[7], board[8]);
   printf("   \t|\t|\n");
}

/* Function verify_selection() */
int verify_selection(int square, int player) {
   if (board[square-1] == ' ' && (player == 1 || player == 0)) {
      board[square-1] = 'X';
      return 0;
   } else if (board[square - 1] == ' ' && player == 2){
      board[square-1] = 'O';
      return 0;
   } else {
      return 1;
   }
}

/* Function to check for winner */
void check_for_winner() {
   int x;
   int cat_total = 0;

   if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') {
      winner = 'X';
   } else if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') {
      winner = 'X';
   } else if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') {
      winner = 'X';
   } else if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') {
      winner = 'X';
   } else if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') {
      winner = 'X';
   } else if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') {
      winner = 'X';
   } else if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') {
      winner = 'X';
   } else if (board[2] == 'X' && board[4] == 'X' && board[8] == 'X') {
      winner = 'X';
   } else if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O') {
      winner = 'O';
   } else if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') {
      winner = 'O';
   } else if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') {
      winner = 'O';
   } else if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') {
      winner = 'O';
   } else if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') {
      winner = 'O';
   } else if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') {
      winner = 'O';
   } else if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') {
      winner = 'O';
   } else if (board[2] == 'O' && board[4] == 'O' && board[8] == 'O') {
      winner = 'O';
   }

   if (winner == 'X') {
      printf("\n X won !!\n");
      return;
   }
   if (winner == 'O') {
      printf("\n O won !!\n");
      return;
   }

   for (x=0; x<9; x++) {
      if (board[x] != ' ') {
         cat_total++;
      }
   }
   if (cat_total == 9) {
      winner = 'C';
      printf("\n CAT game !\n");
      return;
   }
}
