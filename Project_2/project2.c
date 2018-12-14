#include <stdio.h>

int maxBars(int price, int exchangeRate, int wallet);
int newBars(int exchangeRate, int wrappers);

int main {

    int price, exchangeRate, wallet;

    printf("Welcome to BobCat Candy, home to the famous BobCat Bars!\n");
    
    printf("Please enter the price of a BobCat Bar:\n");
    scanf("%d", price);

    printf("Please enter the number of wrappers needed to exchange for a new bar:\n");
    scanf("%d", amount);

    printf("How, how much do you have?\n");
    scanf("%d", wallet);

    printf("Good! Let me run the numbers...\n");
    
    printf("With $%d, you will receive a maximum of %d BobCat Bars!\n", wallet, maxBars(price, exchangeRate, wallet));

    return 0;
}

int maxBars(int exchangeRate, int price, int wallet) {
    int maxBars = 0;
    if(wallet >= price) {
        maxBars += wallet / price;
        printf("First you buy %d bars.", maxBars);
        return maxBars + newBars(newbars, exchangeRate);
    }
    return 0;
}

int newBars(int wrappers, int exchangeRate) {
    int newBars = 0;
    if(wrappers >= exchangeRate) {
        newBars += wrappers / exchangeRate;
        printf("Then, you will get another %d bars.", newBars);
        newBars += wrappers % exchangeRate;
        return newBars(newbars, exchangeRate);
    }
    return 0;
}