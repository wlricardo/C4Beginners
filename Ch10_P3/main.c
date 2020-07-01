/*
   Create a phone book program that allows users to enter names and phone
   numbers of friends and acquaintances. Create a structure to hold contact
   information and use calloc() to reserve the first memory segment. The
   user should be able to add or modify phone book entries through a menu.
   Use the realloc()function to add contiguous memory segments to the
   original memory block when a user adds a new phone book entry.
*/

#include <stdio.h>
#include <stdlib.h>

// Personalized structure
typedef struct {
   int id;
   char name[21];
   char phone[11];
} Contact;

// Functions definitions
void menu();
Contact* add_contact(Contact*);
void show_contacts(Contact*);
void find_contact(Contact*, int);
void update_contact(Contact*, int);

// Global variables
int total_contacts = 0;
Contact *my_list;

int main(void)
{
   int op;
   int contact_id;

   do
   {
      menu();
      scanf("%d", &op); fflush(stdin);

      switch (op)
      {
         case 1:
            system("CLS");
            my_list = add_contact(my_list);
            break;
         case 2:
            system("CLS");
            show_contacts(my_list);
            break;
         case 3:
            system("CLS");
            if (total_contacts == 0) {
               printf("\n Contact list empty !!\n");
               printf("\n\n PRESS [ENTER] TO CONTINUE...\n");
               getchar();
            } else {
               printf("\n Enter contact ID to find: ");
               scanf("%d", &contact_id); fflush(stdin);
               find_contact(my_list, contact_id);
            }
            break;
         case 4:
            system("CLS");
            if (total_contacts == 0) {
               printf("\n Contact list empty !!\n");
               printf("\n\n PRESS [ENTER] TO CONTINUE...\n");
               getchar();
            } else {
               printf("\n Enter contact ID to update: ");
               scanf("%d", &contact_id); fflush(stdin);
               update_contact(my_list, contact_id);
            }
            break;
         case 5:
            break;
         default:
            system("CLS");
            printf("\n Invalid option !!\n");
            printf("\n PRESS [ENTER] TO CONTINUE...\n");
            getchar();
      }
   } while (op != 5);

   return 0;
}

void menu() {
   system("CLS");
   printf("\n  MY CONTACT LIST : %d ENTRIES", total_contacts);
   printf("\n--------------------------------");
   printf("\n  [1] Add contact");
   printf("\n  [2] Show list");
   printf("\n  [3] Find contact");
   printf("\n  [4] Update contact");
   printf("\n  [5] Exit");
   printf("\n  >> ");
}

Contact* add_contact(Contact *c) {

   Contact *aux = NULL;

   printf("\n ADD CONTACT \n");
   if (total_contacts == 0) {
      c = (Contact*) calloc(1, sizeof(Contact));
      if (c == NULL) {
         printf("\n Out of memory !\n");
         exit(0);
      } else {
         (c+total_contacts)->id = 1001+total_contacts;
         printf("\n Enter contact name  : ");
         scanf("%[^\n]", (c+total_contacts)->name); fflush(stdin);
         printf(" Enter contact phone : ");
         scanf("%[^\n]", (c+total_contacts)->phone); fflush(stdin);
      }
      total_contacts++;
   } else {
      total_contacts++;
      int n = total_contacts-1;
      aux = (Contact*) realloc(c, total_contacts*sizeof(Contact));
      if (aux == NULL) {
         printf("\n Out of memory !\n");
         exit(0);
      } else {
         c = aux;
         (c+n)->id = 1000+total_contacts;
         printf("\n Enter contact name  : ");
         scanf("%[^\n]", (c+n)->name); fflush(stdin);
         printf(" Enter contact phone : ");
         scanf("%[^\n]", (c+n)->phone); fflush(stdin);
      }
   }
   printf("\n Contact added successfully !!");
   printf("\n\n PRESS [ENTER] TO CONTINUE...\n");
   getchar();
   return c;
}

void show_contacts(Contact *c) {
   int i;

   if (total_contacts == 0) {
      printf("\n Contact list empty !!\n");
   } else {
      printf("\n MY CONTACT LIST\n");
      for (i=0; i<total_contacts; i++) {
         printf("\n  ID # : %d", (c+i)->id);
         printf("\n  Name : %s", (c+i)->name);
         printf("\n Phone : %s", (c+i)->phone);
         printf("\n--------------------------------\n");
      }
   }
   printf("\n\n PRESS [ENTER] TO CONTINUE...\n");
   getchar();
}

void find_contact(Contact *c, int id) {
   int i;
   int key;
   int found=0;
   system("CLS");

   if (total_contacts == 0) {
      printf("\n Contact list empty !!\n");
   } else {
      for (i=0; i<total_contacts; i++) {
         if ((c+i)->id == id) {
            found = 1;
            key = i;
         }
      }
   }
   if (found) {
      printf("\n SHOW CONTACT\n");
      printf("\n    ID : %d", (c+key)->id);
      printf("\n  Name : %s", (c+key)->name);
      printf("\n Phone : %s", (c+key)->phone);
   } else {
      printf("\n Contact not found !!\n");
   }
   printf("\n\n PRESS [ENTER] TO CONTINUE...\n");
   getchar();
}

void update_contact(Contact *c, int id) {
   int i;
   int key;
   int found=0;
   system("CLS");

   if (total_contacts == 0) {
      printf("\n Contact list empty !!\n");
   } else {
      for (i=0; i<total_contacts; i++) {
         if ((c+i)->id == id) {
            found = 1;
            key = i;
         }
      }
   }
   if (found) {
      printf("\n PREVIOUS CONTACT INFO\n");
      printf("\n    ID : %d", (c+key)->id);
      printf("\n  Name : %s", (c+key)->name);
      printf("\n Phone : %s", (c+key)->phone);
      printf("\n---------------------------------");
      printf("\n\n UPDATE CONTACT\n");
      printf("\n   Contact ID : %d", (c+key)->id);
      printf("\n Update Name : ");
      scanf("%[^\n]", (c+key)->name); fflush(stdin);
      printf(" Update Phone : ");
      scanf("%[^\n]", (c+key)->phone); fflush(stdin);
      printf("\n\n Contact successfully updated !\n");
   } else {
      printf("\n\n Contact not found !!\n");
   }
   printf("\n\n PRESS [ENTER] TO CONTINUE...\n");
   getchar();
}
