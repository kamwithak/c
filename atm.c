#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int framework(int option);
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

//      system("clear");
      framework(option);  //calling framework for atm

    } else {

//      system("clear");
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
  printf("\nUsername: ");
  scanf("%s", user);
  printf("PIN #: ");
  scanf("%s", pwd);

  FILE *info;
  info = fopen("info.csv", "a");

  fprintf(info, "%s,%s,%s\n", user, pwd, "\0");
  fclose(info);
  printf("\nSuccesfully Created Account!\n");

//  system("clear");

  options();

}

void read() {   //sign in

  char user[50], pwd[50], line[50];
  tRestart:
  printf("\nUsername: ");
  scanf("%s", user);
  printf("PIN #: ");
  scanf("%s", pwd);

  //system("clear");

  FILE *info;
  info = fopen("info.csv", "r");

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
          exit(EXIT_SUCCESS); //to leave a funtion in this case

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

  printf("\nSuccessfully Logged in!\n");
  printf("----------$$$----------\n");
  getchar();

}

// the next step -> chequings and savings,
// enter starting amount for each account. -> withdrawal/deposit option -> choose one or both, print final balance of overall account
// sign out to main menu.
