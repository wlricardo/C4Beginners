/**<
      Create a math quiz program that prompts the user for how many
      questions to ask. The program should congratulate the player if
      he or she gets the correct answer or alert the user of the correct
      answer in the event the question is answered incorrectly.
      The math quiz program should also keep track of how many
      questions the player has answered correctly and incorrectly and
      display these running totals at the end of the quiz. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int i;
   int r=0;
   int w=0;
   int num_of_questions;

   printf("\n How many questions would you like to answer ? \n >> ");
   scanf("%d", &num_of_questions); fflush(stdin);

   r=math_quiz(num_of_questions);
   w=num_of_questions-r;

   printf("\n\n TOTAL OF CORRECT ANSWERS: %d", r);
   printf("\n TOTAL OF WRONG ANSWERS: %d\n", w);

   return 0;
}

int math_quiz(int n) {
   srand(time(NULL));

   int i;
   int n1, n2;
   int ans, res;

   int op;
   int right = 0;
   int wrong = 0;

   for (i=0; i<n; i++)
   {
      n1=rand()%20;
      n2=1+(rand()%20);
      op=1+(rand()%4);
      switch (op)
      {
         case 1:
            printf("\n %3d + %3d : ", n1, n2);
            res=n1+n2;
            break;
         case 2:
            printf("\n %3d - %3d : ", n1, n2);
            res=n1-n2;
            break;
         case 3:
            printf("\n %3d x %3d : ", n1, n2);
            res=n1*n2;
            break;
         case 4:
            printf("\n %3d MOD %3d : ", n1, n2);
            res=n1%n2;
            break;
      }
      scanf("%d", &ans); fflush(stdin);

      if (ans ==  res) {
         printf("\n Congratulation!! It is correct!!\n");
         right++;
      } else {
         printf("\n %c Sorry...The right answer is %d.\n", 7, res);
         wrong++;
      }
   }

   return right;
}
