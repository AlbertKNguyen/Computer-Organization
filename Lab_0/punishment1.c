#include <stdio.h>
int main()
{
    //declare and initialzie repeat integer
    int repeat = 0;

    //program will repeat until user enters invalid value
    while(repeat >= 0)
    {
	//prompt user to enter number of times to repeat
        printf("Enter the number of lines for the punishment: ");
        scanf("%d", &repeat);
        
	//if input is valid, print out messages
        if(repeat >= 0) 
        {
            for(int counter = 1; counter <= repeat; counter++) {
                printf("C programming language is the best!");
            }
  	    printf("\n");
        }
	//if input is invalid, print error message
        else {
	    printf("You entered an incorrect value for the number of lines!");
        }

        printf("\n");
    }
    return 0;
}
