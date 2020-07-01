 /*
    Modify the Cryptogram program to use a different type of key
    system or algorithm. Consider using a user-defined key or a
    different character set.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu();
void encrypt(char*, int);
void decrypt(char*, int);
int new_key(int);

int key = 0;

int main(void) {

  srand(time(NULL));

  char myString[21] = {0};
  int select = 0;

  do {

    menu();
    scanf("%d", &select); fflush(stdin);

    switch (select) {
      case 1:
        printf("\n Enter a plain text do encrypt: ");
        scanf("%[^\n]", myString);
        encrypt(myString, key);
        break;
      case 2:
        printf("\n Decrypt cipher text: ");
        scanf("%[^\n]", myString);
        decrypt(myString, key);
        break;
      case 3:
        printf("\n Inform key's length: ");
        scanf("%d", &key);
        key = 1+(rand()%key);
        printf("\n New kwy generated !\n");
        break;
      case 4:
        printf("\n End of program\n");
        break;
      default:
        printf("\n Invalid option !!\n");
    }
  } while (select != 4);
  return 0;
}

void menu() {
  printf("\n Select a Cryptography Option: ");
  printf("\n 1  Encrypt Clear Text");
  printf("\n 2  Decrypt Cipher Text");
  printf("\n 3  Generate New Key");
  printf("\n 4  Quit");
  printf("\n >> ");
}

void encrypt(char *string, int key) {
  int x = 0;

  if (key == 0) {
    key = new_key(4);
  }

  while (string[x]) {
    string[x] += key;
    x++;
  }

  x=0;
  printf("\n Encrypted message is: ");
  while (string[x]) {
    printf("%c", string[x]);
    x++;
  }
  printf("\n\n");
}

void decrypt(char *string, int key) {
  int x = 0;

  if (key == 0) {
    key = new_key(4);
  }

   while (string[x]) {
    string[x] -= key;
    x++;
  }

  x=0;
  printf("\n Decrypted message is: ");
  while (string[x]) {
    printf("%c", string[x]);
    x++;
  }
  printf("\n\n");
}

int new_key(int length) {
  key = 1+(rand() % length);
  return  key;
}
