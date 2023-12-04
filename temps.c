// Practice working with structs - user-defined data type avalible in C
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CITIES 10 // number of cities

typedef struct // type definition structure
{
    string city; // city name global
    int temp;    // temperature global
} avg_temp;      // structure = avg_temp -> Name of the array

avg_temp temps[NUM_CITIES]; // size of the array which is 10

void sort_cities(void);

int main(void) // main function
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order/ Using Bubble Sort

void sort_cities(void)
{
    // Add your code here
    bool stop;
    do
    {
        stop = true;
        for (int i = 0; i<9; i++)
        {
            if (temps[i+1].temp > temps[i].temp) // makes the printing descending instead of ascending
            {
                stop = false;
                avg_temp temp = temps[i];
                temps[i]=temps[i+1];
                temps[i+1] = temp;
            }
        }
    }
    while (!stop);
}
