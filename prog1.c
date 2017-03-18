#include <stdio.h>
#include <stdlib.h>
/*
    PROGRAM ASSUMES A TEXT FILE WITH NO ZERO VALUES
    ASSUMPTION MADE BECAUSE SEQUENCES START AT ONE 
    WRITTEN BY KAMRAN CHOUDHRY 
*/

int fib(int n) {

    //fibonacci sequence algorithm
    int f[n+1];
    f[1] = f[2] = 1;

    for (int i = 3; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];
}

void fetch(int arr[], int sum) {

	int fibArr[500];
	printf("\nThe sum of numbers is %d\n\n", sum);
	printf("The Fibonacci Sequence of each number is:\n\n");

	for (int j = 0 ; j < 500 ; j++) {

		int q = arr[j];

		if (q == 0) {

			break; //assumes NO ZERO value

		} else {

			fibArr[j] = fib(q);
			printf("Fib(%d) is %d\n\n", q, fibArr[j]);

		}

    }

}

int main(int argc, char *argv[]) {

    //open "input.txt" in reading mode
    FILE *input;
    input = fopen("input.txt", "r");

    //init array
    //assuming there are at max 500 numbers in the file
    //of which there is NO ZERO value in the list (fib sequence starts at 1)
    int arr[500];
    int sum = 0;

    //error / reading of file / calculation of sum
    if (input == NULL) {

    	printf("Error reading \"input.txt\"...");

    }
    for (int i = 0 ; i < 500 ; i++) {

        fscanf(input, "%d", &arr[i]);

        //once a ZERO is discovered in array (end of file) -> break loop
        if (arr[i] == 0)
        	break;

		sum += arr[i];

    }

    fetch(arr, sum);
    fclose(input);
    return 0;
}
