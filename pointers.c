#include <stdio.h>
#include "repo.h"

int main()
{
	int nigger = 12;
	struct nigger kamran;
	printf("Memory Address \t \t Name \t\t Value \n");
	
	int * pNigger = nigger;
	
	printf("%p \t %s \t %d \n", pNigger, "nigger", nigger);
	printf("%p \t %s \t %p \n", &pNigger, "pNigger", pNigger);
	
	//begin assigning variablets to the variable (database) "nigger"

	printf("Input a 4 digit #: ");
	scanf("%d", &kamran.userID);
	printf("Input your first name: ");
	scanf("%s", &kamran.firstName);
	printf("Input your last name: ");
	scanf("%s", &kamran.lastName);
	
	printf("What is your age?: ");
	scanf("%d", &kamran.age);
	printf("How heavy are you , fatass? [lbs]: ");
	scanf("%f", &kamran.weight);
	
	

	printf("\n%d\n", kamran.userID);
	printf("%s\n", kamran.firstName);
	printf("%s\n", kamran.lastName);
	printf("%d\n", kamran.age);
	printf("%.2f\n", kamran.weight);
	getchar();

return 0;
}