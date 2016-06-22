#include <stdio.h>

int main()
{
	//float nigger = 1313.141434;
	//double niggerz = 2131.312312;
	int yage, numb;
	char finitial, linitial, newline;
	
	//printf("%.2lf\n", niggerz);
	//printf("%.2f", nigger);
	
	
	printf("First Initial: ");
	scanf("%c%c", &finitial, &newline);

	printf("Last Initial: ");
	scanf("%c%c", &linitial, &newline); 

	printf("Your initials are %c%c!\n", finitial, linitial);
	printf("\n///////////////////\n\n");

	printf("How old are you: ");
	scanf("%d", &yage);

	printf("You're %d years old!\n", yage);
	printf("\n///////////////////\n\n");
	
	label:
	printf("How many seconds are in a minute?\n\n");
	scanf("%d", &numb);
	
	if(numb == 60)
		{
		printf("\n///////////////////\n\nCorrect, you must be a genius!\n");
		}
	else
		{
		printf("\n///////////////////\n\nSorry, that is not the correct answer....\n\n");
		goto label;
		}
	
	return 0;
	
}