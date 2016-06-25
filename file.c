#include <stdio.h>
//contacts name and number saved in file.
void edit(){

  char *name;
  int number, x=1;
  FILE *f;
  f = fopen("info.txt", "a");

  while (x<=3){
    printf("\nNew contact name: ");
    scanf("%s", name);
    printf("New contact number: ");
    scanf("%d", &number);
    fprintf(f, "Name:%s\nPhone #:%d\n\n", name, number);
    x++;
  }

  printf("\n");
  fclose(f);

}

int main(){

  edit();
  return 0;

}
