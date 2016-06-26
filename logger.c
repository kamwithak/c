#include <stdio.h>
#include <stdlib.h>
//username and password logger
void intro() {

  char message[] = "\n       Social Media Account Logger...";
  printf("%s\n", message);
  printf("~~~~~~~~~ Press to enter continue ~~~~~~~~~\n");
  getchar();

}
int init() {

  char type[20], user[20], pw[20];
  int limit, x=0;
  FILE *logger;
  logger = fopen("log.txt", "w");
    //how many accounts do you wana log?
    printf("How many accounts would you like to record? (0 to 10) (0 = EXIT)\n(INPUT INTEGER) // ");
    scanf("%d", &limit);

    if (limit == 0) {
      printf("Exiting program...\n");
      return 0;
    } else {
        while (x < limit) {

          printf("\nType of Social Media: ");
          scanf("%s", type);
          printf("Username: ");
          scanf("%s", user);
          printf("Password: ");
          scanf("%s", pw);

          fprintf(logger, "Type of Social Media:%s\nUsername:%s\nPassword:%s\n\n", type, user, pw);
          x++;

        }
          fclose(logger);
          printf("\nSuccessfully Logged...\nFile -> log.txt\nExiting program...\n\n");
          return 0;
      }
}
int main() {
  intro();
  init();
  return 0;
}
