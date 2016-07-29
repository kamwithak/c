#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* LOGIN SYSTEM, ATM SIMULATION, MANIPULATION OF FILE I/O USING C
~ KAMRAN WITH A K, LAST UPDATED JULY 29th, 2016 ~  */

void init(void);
void options(void);
void framework(int option);
float add_to_chequings(float nChequings, float iChequings, float addChequings);
float sub_from_chequings(float nChequings, float iChequings, float subChequings);
float add_to_savings(float nSavings, float iSavings, float addSavings);
float sub_from_savings(float nSavings, float iSavings, float subSavings);
void transaction_type(float iSavings, float iChequings);
void withdraw(float iSavings, float iChequings);
void deposit(float iSavings, float iChequings);
void transaction(void);
void transaction_success(float nS, float nC, float nT);
void transaction_failure(float iS, float iC);
void final_info(float nS, float nC, float nT);
void granted(void);
int negative_checker(float nS, float nC, float nT);
void atm(void);
void sign_in(void);
void create_an_account(void);

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

  } 

  goto stop;

}

void framework(int option) {

  if (option == 1) {

    sign_in();

  } else {

    create_an_account();

  }

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
      granted();
      exit(EXIT_SUCCESS); //leave function

    }

  }

  fclose(file);
  system("clear");
  printf("\nINVALID USERNAME OR PIN #, TRY AGAIN...\n");
  goto tRestart;

}

void granted(void) {

  system("clear");
  printf("\n * Authentication Successful *");
  printf("\n  * Welcome to the C.C ATM! *");
  printf("\n    ----------$$$----------\n\n");
  atm();

}

void atm(void) {

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

  printf("\nWould you like to WITHDRAW, DEPOSIT, or RETURN TO MAIN MENU?\n");
  printf("     1 = WITHDRAW  2 = DEPOSIT  3 = RETURN TO MAIN MENU\n\n -> ");
  scanf("%d", &CHOICE);

  if (CHOICE == 1) {

    withdraw(iSavings, iChequings);

  } else if (CHOICE == 2) {

    deposit(iSavings, iChequings);

  } else {

    system("clear");
    options();

  }

}

void withdraw(float iSavings, float iChequings) {

  int CHOICE;
  char type[] = "WITHDRAW";
  float subSavings, subChequings;
  float nSavings, nChequings, nTotal;
  KONG:

  printf("\nWhich account would you like to %s from?\n", type);
  printf("      1 = CHEQUINGS  2 = SAVINGS\n\n -> ");
  scanf("%d", &CHOICE);

  if (CHOICE == 1) {

    nChequings = sub_from_chequings(nChequings, iChequings, subChequings);
    nSavings = iSavings;
    nTotal = nChequings + nSavings;

    int x = negative_checker(nSavings, nChequings, nTotal);
    
    if (x == 1) {

      transaction_success(nSavings, nChequings, nTotal);
    
    } else if (x == 0) {

      transaction_failure(iSavings, iChequings);
      
    } else {

      goto KONG;

    }

  } else if (CHOICE == 2) {

    nSavings = sub_from_savings(nSavings, iSavings, subSavings);
    nChequings = iChequings;
    nTotal = nSavings + nChequings;

    int x = negative_checker(nSavings, nChequings, nTotal);
    
    if (x == 1) {

      transaction_success(nSavings, nChequings, nTotal);
    
    } else if (x == 0) {

        transaction_failure(iSavings, iChequings);
      
    } else {

        goto KONG;

    }

  } 

}

void deposit(float iSavings, float iChequings) {

  int CHOICE;
  char type[] = "DEPOSIT";
  float addSavings, addChequings;
  float nSavings, nChequings, nTotal;
  KONG:

  printf("\nWhich account would you like to %s money into?\n", type);
  printf("      1 = CHEQUINGS  2 = SAVINGS\n\n -> ");
  scanf("%d", &CHOICE);

  if (CHOICE == 1) {

    nChequings = add_to_chequings(nChequings, iChequings, addChequings);
    nSavings = iSavings;
    nTotal = nChequings + nSavings;

    int x = negative_checker(nSavings, nChequings, nTotal);

    if (x == 1) {

      transaction_success(nSavings, nChequings, nTotal);
    
    } else if (x == 0) {

      transaction_failure(iSavings, iChequings);

    } else {

      goto KONG;

    }

  } else if (CHOICE == 2) {

    nSavings = add_to_savings(nSavings, iSavings, addSavings);
    nChequings = iChequings;
    nTotal = nSavings + nChequings;

    int x = negative_checker(nSavings, nChequings, nTotal);

    if (x == 1) {

      transaction_success(nSavings, nChequings, nTotal);
    
    } else if (x == 0) {

      transaction_failure(iSavings, iChequings);
      
    } else {

      goto KONG;

    }

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

void transaction_failure(float iS, float iC) {
  
  char msg[] = "\nTransaction Incomplete!\nNot enough $$$'s... try again.";
  printf("%s\n", msg);
  transaction_type(iS, iC);

}

void transaction_success(float nS, float nC, float nT) {

  char msg[] = "\nSuccessful Transaction!";
  char quest[] = "1 = MAKE ANOTHER TRANSACTION\n2 = VIEW FINAL BALANCE\n3 = EXIT";
  int CHOICE;

  printf("%s\n", msg);
  printf("-----------------------\n");
  printf("%s\n\n-> ", quest);
  scanf("%d", &CHOICE);

  for(;;) {

    if (CHOICE == 1) {

     	transaction_type(nS, nC);

    } else if (CHOICE == 2) {

    	final_info(nS, nC, nT);

    } else {

      exit(EXIT_SUCCESS);

    }

        break; //NOTE FOR ME: not sure if need break; here, once program is complete, get rid of this and see what's good.
  }


}

int negative_checker(float nS, float nC, float nT) {

  if (nC < 0 || nS < 0 || nT < 0) {

    	return 0;

  } else {

    	return 1;

  }

}

void final_info(float nS, float nC, float nT) {

  char banner[] = "\nFinal Balance!";
  char line[] = "--------------";

  printf("%s\n%s\n", banner, line);
  printf("CHEQUINGS -> $%.2f\n", nC);
  printf("SAVINGS -> $%.2f\n", nS);
  printf("~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("TOTAL ACCOUNT VALUE -> $%.2f\n\n", nT);

}
