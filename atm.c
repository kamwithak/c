#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int framework(int option);
void withdraw(float iSavings, float iChequings);
void proposal(float iSavings, float iChequings);
void read();
void loggedIn();
void write();
void options();
void login();
void init();

int main(void) {

  init();
  return (0);

}

void init() {

  char pw[20];
  iRestart:
  system("clear");

  printf("\nWELCOME TO THE CHOUDHRY CONSOLIDATED ATM!\n");
  printf("_________________________________________\n");
  printf("\nWHAT IS THE START-UP ATM KEY?\n -> ");
  scanf("%s", pw);

    if (strcmp(pw, "885265om") == 0) {  // strcmp() returns 0 iff pw = "885265om"

      system("clear");
      options();

    } else {

      goto iRestart;

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

    } else if (option == 1 || option == 2) {

      system("clear");
      framework(option);  //calling framework for atm

    } else {

      system("clear");
      goto stop;

    }

}

int framework(int option) {

    if (option == 1) {

      read(); //sign in

    } else {

      write(); //create an account

    }

  return (0);

}

void write() {   //create an account

  char user[50], pwd[50];
  printf("MENU ~ CREATE AN ACCOUNT\n");
  printf("------------------------");
  printf("\nUsername: ");
  scanf("%s", user);
  printf("PIN #: ");
  scanf("%s", pwd);

  FILE *info;
  info = fopen("accounts.csv", "a");

  fprintf(info, "%s,%s,%s\n", user, pwd, "\0");
  fclose(info);
  system("clear");

  printf("\nSuccesfully Created Account! ~ \n");

  options();

}

void read() {   //sign in

  char user[50], pwd[50], line[50];
  printf("MENU ~ SIGN IN\n");
  printf("--------------");
  tRestart:
  printf("\nUsername: ");
  scanf("%s", user);
  printf("PIN #: ");
  scanf("%s", pwd);

  system("clear");

  FILE *info;
  info = fopen("accounts.csv", "r");

  while (fgets(line, sizeof(line), info) != NULL) {

    char *USER = strtok(line, ",");
    char *PASSER = strtok(NULL, ",");

      int mUsername = strcmp(user, USER);
      int mPassword = strcmp(pwd, PASSER);  //return value of 0 iff == 0

  //    printf("%d username: %s\n", mUsername, USER);      ~ method of login system ~
  //    printf("%d password: %s\n", mPassword, PASSER);    ~ strcmp return value and string organized in a nice terminal ~

        if (mUsername == 0 && mPassword == 0) {

          fclose(info);
          system("clear");
          loggedIn();
          exit(EXIT_SUCCESS); //to leave the loop

        } else {

          continue;

        }

  }

  fclose(info);
  // program only goes past this point iff program goes through entire file and zero matches are found
  system("clear");
  printf("\nINVALID USERNAME OR PIN #, TRY AGAIN...\n");
  goto tRestart;

}

void loggedIn() {

  printf("\n * Authentication Successful *");
  printf("\n  * Welcome to the C.C ATM! *");
  printf("\n    ----------$$$----------\n\n");

  float iChequings;
  float iSavings;

  printf("What is the INITIAL VALUE for each type of account?\n\nCHEQUINGS -> $");
  scanf("%f", &iChequings);

  printf("SAVINGS -> $");
  scanf("%f", &iSavings);
  printf("~~~~~~~~~~~~~~~~~\n");

  float iTotal = iChequings + iSavings;
  printf("TOTAL INITIAL VALUE -> $%.2f\n", iTotal);

  proposal(iSavings, iChequings);

}

void proposal(float iSavings, float iChequings) {

  int CHOICE;

  printf("\nWould you like to WITHDRAW or DEPOSIT?\n");
  printf("      1 = WITHDRAW  2 = DEPOSIT\n\n -> ");
  scanf("%d", &CHOICE);

  if (CHOICE == 1) {

    withdraw(iSavings, iChequings); //currently working on

  } else if (CHOICE == 2) {

//    deposit(); finish this next

  } else {

// exit back to main menu, do this after

  }

}

void withdraw(float iSavings, float iChequings) {

// bring the variables into this function using arguments -> conduct transaction -> sperate function that prints final balance
// -> option to perform another transaction or main menu

  int CHOICE;
  char calculation[] = "WITHDRAW";
  float subSavings, subChequings;
  float nSavings, nChequings, nTotal;

  printf("\nWhich account would you like to %s from?\n", calculation);
  printf("      1 = CHEQUINGS  2 = SAVINGS\n\n -> ");
  scanf("%d", &CHOICE);

  if (CHOICE == 1) {

    printf("\nHow much?\n -> $");
    scanf("%f", &subChequings);
    nChequings = iChequings - subChequings;
    printf("\nNew CHEQUINGS account value: %.2f\n", nChequings);

  } else if (CHOICE == 2) {

    printf("\nHow much?\n -> $");
    scanf("%f", &subSavings);
    nSavings = iSavings - subSavings;
    printf("\nNew SAVINGS account value: %.2f\n", nSavings);

  } else {

    exit(EXIT_FAILURE);

  }

}
