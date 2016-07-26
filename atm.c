#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* LOGIN SYSTEM, ATM SIMULATION, MANIPULATION OF FILE I/O USING C
~ KAMRAN WITH A K, LAST UPDATED JULY 26th, 2016 ~  */

void init();
void options();
int framework(int option);
float add_to_chequings(float nChequings, float iChequings, float addChequings);
float sub_from_chequings(float nChequings, float iChequings, float subChequings);
float add_to_savings(float nSavings, float iSavings, float addSavings);
float sub_from_savings(float nSavings, float iSavings, float subSavings);
void transaction_type(float iSavings, float iChequings);
void withdraw(float iSavings, float iChequings);
void deposit(float iSavings, float iChequings);
void final_info();
void receipt();
void atm();
void sign_in();
void create_an_account();

int main(void) {

  init();

  return 0;

}

void init(void) {

  char pw[20];
  iRestart:
  system("clear");

  printf("\nWELCOME TO THE CHOUDHRY CONSOLIDATED ATM!\n");
  printf("_________________________________________\n");
  printf("\nWHAT IS THE START-UP ATM KEY?\n -> ");
  scanf("%s", pw);

  if (strcmp(pw, "1234") == 0) {  // START-UP ATM KEY = "1234"

    system("clear");
    options();

  }

  goto iRestart;

}

void options(void) {

  int option;

  stop:
  printf("\nWhat would you like to do? (*INPUT INTEGER ONLY*)\n  1 = SIGN IN  2 = CREATE AN ACCOUNT  3 = EXIT\n\n -> ");
  scanf("%d", &option);
  system("clear");

  if (option == 3) {

    exit(EXIT_SUCCESS);  //sys.exit() equivalent

  } else if (option == 1 || option == 2) {

    framework(option);  //calling framework for atm

  } else {

    goto stop;

  }

}

int framework(int option) {

  if (option == 1) {
	
	  sign_in();

  } else {

    create_an_account();

  }

  return 0;

}

void sign_in(void) {   //sign in

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
    int mPassword = strcmp(pwd, PASSER);

    if (mUsername == 0 && mPassword == 0) {

      fclose(file);
      atm();
      exit(EXIT_SUCCESS); //leave function

    }

  }

  fclose(file);
  system("clear");
  printf("\nINVALID USERNAME OR PIN #, TRY AGAIN...\n");
  goto tRestart;

}

void create_an_account(void) {   //create an account

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

void atm(void) {

  system("clear");
  printf("\n * Authentication Successful *");
  printf("\n  * Welcome to the C.C ATM! *");
  printf("\n    ----------$$$----------\n\n");

  float iChequings;
  float iSavings;

  printf("INITIAL VALUE for each type of account?\n\nCHEQUINGS -> $");
  scanf("%f", &iChequings);

  printf("SAVINGS -> $");
  scanf("%f", &iSavings);
  printf("~~~~~~~~~~~~~~~~~~~~~~\n");

  float iTotal = iChequings + iSavings;
  printf("INITIAL ACCOUNT VALUE -> $%.2f\n", iTotal);

  transaction_type(iSavings, iChequings);

}

void transaction_type(float iSavings, float iChequings) {

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
  char type[] = "WITHDRAW";
  float subSavings, subChequings;
  float nSavings, nChequings, nTotal;

  printf("\nWhich account would you like to %s from?\n", type);
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
  char type[] = "DEPOSIT";
  float addSavings, addChequings;
  float nSavings, nChequings, nTotal;

  printf("\nWhich account would you like to %s money into?\n", type);
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

void final_info() {

  //display all information of new account balances in terminal using for loop
  //"CURRENT ACCOUNT VALUE", keep things consistent
  //arguments needed before anything else

}

void receipt() {

  //create a file (.txt) receipt for transaction and create that in a specific directory

}

  //figure out way to add a "make another transaction" feature. ex) goto
