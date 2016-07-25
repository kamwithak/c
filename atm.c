#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* LOGIN SYSTEM, ATM SIMULATION, MANIPULATION OF FILE I/O USING C
~ KAMRAN WITH A K, LAST UPDATED JULY 24th, 2016 ~  */

int framework(int option);
float add_to_chequings(float nChequings, float iChequings, float addChequings);
float add_to_savings(float nSavings, float iSavings, float addSavings);
float sub_from_chequings(float nChequings, float iChequings, float subChequings);
float sub_from_savings(float nSavings, float iSavings, float subSavings);
void withdraw(float iSavings, float iChequings);
void deposit(float iSavings, float iChequings);
void proposal(float iSavings, float iChequings);
void finalInfo();
void receipt();
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

    if (strcmp(pw, "885265om") == 0) {  // START-UP ATM KEY = "885265om"

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

  FILE *file;
  file = fopen("accounts.csv", "a");

  fprintf(file, "%s,%s,%s\n", user, pwd, "\0");
  fclose(file);
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

  FILE *file;
  file = fopen("accounts.csv", "r");

  while (fgets(line, sizeof(line), file) != NULL) {

    char *USER = strtok(line, ",");
    char *PASSER = strtok(NULL, ",");

      int mUsername = strcmp(user, USER);
      int mPassword = strcmp(pwd, PASSER);  //return value of 0 iff srtings are same

  //    printf("%d username: %s\n", mUsername, USER);      ~ method of login system ~
  //    printf("%d password: %s\n", mPassword, PASSER);    ~ strcmp return value and string organized in a nice terminal ~

        if (mUsername == 0 && mPassword == 0) {

          fclose(file);
          system("clear");
          loggedIn();
          exit(EXIT_SUCCESS); //to leave function

        } else {

          continue;

        }

  }

  fclose(file);
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

  printf("What is your INITIAL VALUE for each type of account?\n\nCHEQUINGS -> $");
  scanf("%f", &iChequings);

  printf("SAVINGS -> $");
  scanf("%f", &iSavings);
  printf("~~~~~~~~~~~~~~~~~~~~~~\n");

  float iTotal = iChequings + iSavings;
  printf("INITIAL ACCOUNT VALUE -> $%.2f\n", iTotal);

  proposal(iSavings, iChequings);

}

void proposal(float iSavings, float iChequings) {

  int CHOICE;

  printf("\nWould you like to WITHDRAW or DEPOSIT?\n");
  printf("      1 = WITHDRAW  2 = DEPOSIT\n\n -> ");
  scanf("%d", &CHOICE);

  if (CHOICE == 1) {

    withdraw(iSavings, iChequings);

  } else if (CHOICE == 2) {

    deposit(iSavings, iChequings);

  } else {

// exit back to main menu, write this ASAP

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

    float x = sub_from_chequings(nChequings, iChequings, subChequings);
    printf("%.2f\n", x);

  } else if (CHOICE == 2) {

    float x = sub_from_savings(nSavings, iSavings, subSavings);
    printf("%.2f\n", x);

  } else {

    exit(EXIT_FAILURE);

  }

}

void deposit(float iSavings, float iChequings) {

// bring the variables into this function using arguments -> conduct transaction -> sperate function that prints final balance
// -> option to perform another transaction or main menu

  int CHOICE;
  char calculation[] = "DEPOSIT";
  float addSavings, addChequings;
  float nSavings, nChequings, nTotal;

  printf("\nWhich account would you like to %s money into?\n", calculation);
  printf("      1 = CHEQUINGS  2 = SAVINGS\n\n -> ");
  scanf("%d", &CHOICE);

  if (CHOICE == 1) {

    float x = add_to_chequings(nChequings, iChequings, addChequings);
    printf("%.2f\n", x);

  } else if (CHOICE == 2) {

    float x = add_to_savings(nSavings, iSavings, addSavings);
    printf("%.2f\n", x);

  } else {

    exit(EXIT_FAILURE); //goto this, fam

  }

}

float add_to_chequings(float nChequings, float iChequings, float addChequings) {

    printf("\nHow much?\n\n -> $");
    scanf("%f", &addChequings);
    nChequings = iChequings + addChequings;
    return nChequings;

}

float sub_from_chequings(float nChequings, float iChequings, float subChequings) {

    printf("\nHow much?\n\n -> $");
    scanf("%f", &subChequings);
    nChequings = iChequings - subChequings;
    return nChequings;

}

float add_to_savings(float nSavings, float iSavings, float addSavings) {

    printf("\nHow much?\n\n -> $");
    scanf("%f", &addSavings);
    nSavings = iSavings + addSavings;
    return nSavings;

}

float sub_from_savings(float nSavings, float iSavings, float subSavings) {

    printf("\nHow much?\n\n -> $");
    scanf("%f", &subSavings);
    nSavings = iSavings - subSavings;
    return nSavings;

}

void finalInfo() {

  //display all information of new account balances in terminal using for loop
  //"CURRENT ACCOUNT VALUE", keep things consistent
  //arguments needed before anything else

}

void receipt() {

  //create a file (.txt) receipt for transaction and create that in a specific directory

}

  //figure out way to add a "make another transaction" feature. ex) goto
