#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long credit = get_long("Number: ");
    long num = 0;
    long sum  = 0;
    int isValid = 0;
    
    //seperates the digits of every other number starting from the second to last
    //multiplies them by 2 and then sums
    for (long i = 10; (credit / i) != 0; i = i * 100)
    {
        num = credit / i;
        num = num % 10;
        
        if ((num * 2) < 10)
        {
            sum = sum + (num * 2);
        }
        else
        {
            sum = sum + ((num * 2) / 10);
            sum = sum + ((num * 2) % 10);
        }
    }
    
    //sums the remaining unused digits
    for (long i = 1; (credit / i) != 0; i = i * 100) 
    {
        if (i == 1)
        {
            sum = sum + credit % 10;
        }
        else
        {
            num = credit / i;
            sum = sum + (num % 10);
        }
        
    }
    
    //determines if credit card number is valid
    if ((sum % 10) == 0)
    {
        isValid = 1;
    }
    
    //determines the number of digits in the number
    int numDigits = 0;
    num = credit;
    while (num != 0)
    {
        num = num / 10;
        numDigits++;
    }
    
    //determines the first 2 digits in a number
    long startDigits = credit;
    while (startDigits > 99)
    {
        startDigits = startDigits / 10;
    }
    
    //determines whether the number is valid and what card company it is from
    if ((isValid == 1) && (numDigits == 16)) //evaluates numbers thast pass the validity test with 16 digits
    {
        if ((startDigits == 51) || (startDigits == 52) || (startDigits == 53) || (startDigits == 54) || (startDigits == 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((startDigits / 10) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if ((isValid == 1) && (numDigits == 13)) //evaluates numbers thast pass the validity test with 13 digits
    {
        if ((startDigits / 10) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVLAID\n");
        }
    }
    else if ((isValid == 1) && (numDigits == 15)) //evaluates numbers thast pass the validity test with 15 digits
    {
        if ((startDigits == 34) || (startDigits == 37))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    
}