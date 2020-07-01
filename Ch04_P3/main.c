/**<
      Create a counting program that prompts the user for three
      inputs (shown next) that determine how and what to count.
      Store the user’s answers in variables. Use the acquired data to
      build your counting program with a for loop and display the
      results to the user.
      • Beginning number to start counting from
      • Ending number to stop counting at
      • Increment number */

#include <stdio.h>
#include <stdlib.h>

// FUNCTIONS DECLARATIONS
void counting_forwards(int b, int e, int i);
void counting_backwards(int b, int e, int i);
void counting(int b, int e, int i);

// PROGRAM BEGINS
int main()
{
    int beg, end, inc;

    printf("\n Beginning number to start counting from: ");
    scanf("%d", &beg);
    printf("\n Ending number to stop counting at: ");
    scanf("%d", &end);
    printf("\n Increment number: ");
    scanf("%d", &inc);

    //counting_forwards(beg, end, inc);
    counting(beg, end, inc);
    return 0;
}

// FUNCTION TO COUNTING FOWARDS
void counting_forwards(int b, int e, int i) {
   int j;

   for (j = b; j <= e; j+=i) {
       printf(" [%2d]", j);
   }
   printf("\n");
}

// FUNCTION TO COUNTING BACKWARDS
void counting_backwards(int b, int e, int i) {
   int j;

   for (j = b; j >= e; j-=i) {
       printf(" [%2d]", j);
   }
   printf("\n");
}

// CHECK WITCH CASE TO COUNT
void counting(int b, int e, int i) {
   if (b < e) {
         printf("\n Counting forwards...");
      counting_forwards(b, e, i);
   } else {
      printf("\n Counting backwards...");
      counting_backwards(b, e, i);
   }
}
