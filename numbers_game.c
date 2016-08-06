#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cycle(int target); //prototype needed to call cycle() before declaration

int getNumber() {

	int i;
	printf(" -> ");
	scanf("%d", &i);
	return i;

}

void getComparison(int input, int target) {

	if (target > input) {

		printf("Higher...\n");
		cycle(target);

	} else if (target < input) {

		printf("Lower...\n");
		cycle(target);

	} else if (target == input) {

		printf("Correct guess! TARGET NUMBER = %d\n", target);
		exit(EXIT_SUCCESS);

	} 
			// put the strings of this function into array's
}

void cycle(int target) {

	int input = getNumber(); 
	getComparison(input, target);

}

int main(void) {

	char msg[] = "Guess the TARGET NUMBER (0 to 10)";
	char line[] = "---------------------------------";
	printf("%s\n%s\n", msg, line);

	srand(time(NULL)); //init random seed
	int target = rand() % 11; // generate target # between 0 and 10

	cycle(target);

	return 0;

}
