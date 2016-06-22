#include <stdio.h>
int brodown();
int main()
{
    int agree;
		printf("The goal of this game is to get 10 Bro Downs....\n");
		args:
		printf("Would you like to play?  Yes = 1  No = 2\n");
		scanf("%d", &agree);
			if(agree == 1) {
				//the offerings 
				printf("Lets play!\n");
				getchar();
				brodown(); //the launch
			} else if(agree == 2)
				return 0;
			else { 
				printf("Incorrect Input... \n");
				goto args;
			}
}
int brodown() //the program
{
    for(int eric = 0; eric <= 100; eric++) {
		if(eric == 0)
			continue;
		else if(eric > 10) {
			printf("//////////////////////////////////\n");
			printf("\nYou got 10 Bro Downs, you won faggot!\nHit enter to exit...");
			break;
		} else {
			printf("%d. ", eric);
			printf("Bro Down!\n\n");
			printf("Press Enter to Claim...\n");
			getchar();
		}
	}
		getchar(); //new character
    return 0;
}