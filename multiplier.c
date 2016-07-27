#include <stdio.h>
#include <string.h>

int mult(int z, int y) {

	return z*y;

}

int main(void) {

	int x=0;
	int n;
	char intro[] = "Enter #: ";

	for(;;) {

		printf("%s", intro);
		scanf("%d", &n);
			break;
	}

	do {

		x++;
		printf("\n%d. ", x);

		for(int y=0;y<n;y++) {

			while(1) {

				printf(":-) ");
					break;

			}

		}

	} while(x<n); 

	int answer = mult(n, n);
	printf("\n\n%d x %d = %d :-) in total\n\n", n, n, answer);

	return 0;
	
}
