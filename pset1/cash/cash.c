#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0.0);
    
    //converts dollars to an integer of cents
    int cents = round(dollars * 100);
    
    int numCoins = 0;

    //finds number of quaters
    numCoins = numCoins + (cents / 25);
    cents = cents % 25;
    
    //finds number of dimes
    numCoins = numCoins + (cents / 10);
    cents = cents % 10;
    
    //finds number of nickels
    numCoins = numCoins + (cents / 5);
    cents = cents % 5;
        
    //finds number or pennies
    numCoins = numCoins + (cents / 1);
    
    printf("%i\n", numCoins);
}