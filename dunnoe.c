#include <stdio.h> 

int main()
{
	
int xxiv, erupt, game;
double numb;

printf("Assign X Value: ");
scanf("%d", &xxiv);

printf("Welcome to the game...\nThe goal is to type in a # for Y so that it is greater than or equal to %d!\n\n", xxiv);
printf("You don't really have a choice, would you like to play this game?\nYES = 1   NO = 2\n... ");
scanf("%d", &game);

	if(game == 1)
		{
		printf("\n///////////////////////\nLet us play!\n");
		printf("Enter a value for Y such that it is above or equal to %d: ", xxiv);
		scanf("%lf", &numb);
		  
		if(numb>=xxiv)
			{
			printf("\nCongratulations! The value of Y is either greater than or equal to X!");
			printf("\nTo exit this game, solve the following equation...\n(1 + 3) - 1 = ?\n");
			scanf("%d", &erupt);
			}
			
		if(erupt == 3)
			{
			printf("\nCorrect answer!\nConcluding this program...");
			}
		else if(erupt != 3)
			{
			printf("\nSorry, the value you currently inputed (%.2lf) is not greater than %d...\n", numb, xxiv);
			printf("\nIncorrect answer... please try again!"); 
			}
		}
	else;
		{
		printf("\n#OFFTHISFAM\n");
		}

	return 0;
}