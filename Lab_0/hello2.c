#include <stdio.h>
int main()
{
    //declare an character array
    char name[20];
    
    //prompt user to enter a name
    printf("Please enter your name: ");
    scanf("%[^\n]s", name);

    //prints welcome message and name
    printf("Welcome to CSE31, %s!\n", name);

    return 0;
}
