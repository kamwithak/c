#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int atm(int option);
int write();
int read();
void options();
void login();
void init();

int main(void) {

  init();
  return (0);

}

void init() {

  char pw[20];

  system("clear");

  printf("\nWELCOME TO THE CHOUDHRY CONSOLIDATED ATM!\n");
  printf("_________________________________________\n");
  printf("\nWHAT IS THE START-UP ATM KEY? \n -> ");
  scanf("%s", pw);

  system("clear");

    if (strcmp(pw, "885265om") == 0) {  // strcmp() returns 0 iff pw = "885265om"

      options();

    } else {

      printf("\nINVALID KEY... \nEXITING ATM SIMULATION ~\n\n");
      system("clear");
      exit(EXIT_SUCCESS);

    }

}

void options() {

  int option;

  stop:
  printf("\nWhat would you like to do? (*INPUT INTEGER ONLY*)\n 1 = SIGN IN  2 = CREATE AN ACCOUNT  3 = EXIT\n\n -> ");
  scanf("%d", &option);

    if (option == 3) {

      system("clear");
      exit(EXIT_SUCCESS);  //sys.exit() equivalent

    } else if (option == 1 || option == 2){

      system("clear");
      atm(option);  //calling framework for atm

    } else {

      goto stop;

    }

}

int atm(int option) {

    if (option == 1) {

      read(); //sign in

    } else {

      write(); //create an account

    }

  return (0);

}

int write() {   //create an account

  char user[50], pwd[50], line[50];
  printf("\nUsername: ");
  scanf("%s", user);
  printf("Password: ");
  scanf("%s", pwd);

  FILE *info;
  info = fopen("info.csv", "a");

  fprintf(info, "\n%s,%s\n", user, pwd);

  fclose(info);
  return 0;

  system("clear");

}

int read() {   //sign in

  char user[50], pwd[50], line[50];
  printf("\nUsername: ");
  scanf("%s", user);
  printf("Password: ");
  scanf("%s", pwd);

  FILE *info;
  info = fopen("info.csv", "r");

  while (fgets(line, sizeof(line), info) != NULL) {

    char *USER = strtok(line, ",");
    char *PASS = strtok(NULL, ",");

      printf("user- %s\n", USER);

  }

  fclose(info);

  return 0;

  system("clear");

}
