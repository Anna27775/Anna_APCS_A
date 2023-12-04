#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // find where to stop
    //return the number
    //else return 0
    int n = strlen(input); //Getting the length of the string
    int last_digit = input[n-1]-48; //input[n-1] = getting the decimal number value of the last digit (ascii) - 48 because 48 = 0 , gets the number. 
    input[n-1] = '\0';
    if (n > 0)
    {
        return (10* convert(input)+last_digit);
    }
    else
    {
        return 0;
    }
}
