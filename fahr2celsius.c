#include <stdio.h>

void converter(void) {

    int x = 0;
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;


  while (x == 0) {
      fahr = lower;
      printf("Fahrenheit\tCelsius\n");
      x++;
  }

  while (fahr <= upper) {

      celsius = 5 * (fahr-32) / 9;
      printf("%d\t\t%d\n", fahr, celsius);
      fahr = fahr + step;
  }

}

int main() {

 converter();
 return 0;

}
