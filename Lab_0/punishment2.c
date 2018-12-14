#include <stdio.h>
int main()
{
    //initialize and declare repeat integer
    int repeat = 0;
    //intialize the typo integer
    int typo;

    //program repeats if inputs are valid
    while(repeat >= 0)
    {
	//prompt user to enter number of times to repeat
        printf("Enter the number of lines for the punishment: ");
        scanf("%d", &repeat);        

	//if repeat value is invalid, print out error message and exit program
	if(repeat < 0) {
	    printf("You entered an incorrect value for the number of lines!\n");
	    return 0;
	}

	//prompt user to enter which line to have a typo
	printf("Enter the line for which we want to make a typo: ");
	scanf("%d", &typo);

	//if typo value if invalid, print out error message and exit program
	if(typo < 1 || typo > repeat) {
	    printf("You entered an incorrect value for the line typo!\n");
	    return 0;
	}

	//print out the message repeat number of times with a typo in 1 of the lines
        for(int counter = 1; counter <= repeat; counter++) {
	    if(counter == typo) {
		printf("C programming language is the bet! ");
	    }
	    else {
                printf("C programming language is the best!");
	    }
	}
  	printf("\n\n");

    }
    return 0;
}
