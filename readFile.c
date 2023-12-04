#define SIZE1 5000
#define SIZE2 10000
#define SIZE3 50000
int *readFile(string fileName, int size, int size2);  //pointer to return and int array
int linearSearch(int array[], int guess, int size);  //linear search
int binarySearch(int array[], int guess, int size);
int *bubbleSort(int array[], int size);
int *selectionSort(int array[], int size);
void printArray(int array[], int size);
void Menu();
void writeArray(int array[], int size);

int main(void)
{
    bool readf=false;
    int choice = 0;
    do{
        Menu();
        choice = get_int("Please enter your choice 1-5: \n");
        if(choice == 5)
        {
            printf("Thank you for visiting, see you later\n");
            return 0;
        }
        int *array;
        string fileName;
        int size;
        int guess=0;
        char check;
        int indx;
        if (!readf)
        {
            fileName = get_string("Enter File name:  ");
            size = get_int("Enter the File size:5000, 10000, or 50000? \n");
            FILE* file=(fopen(fileName, "r"));
            if(!file)
            {
            printf("\n Unable to open : %s ", fileName);
            return -1;
            }
            fclose(file);
            array=readFile(fileName, size, 5);   // call of the function
            readf=true;

        }
        switch(choice)
        {
            case 1:

                    guess = get_int ("What value are you looking for: " );
                    indx = linearSearch(array, guess, size);
                    printf("the index is %i \n", indx);

                break;


            case 2:
                check= get_char("is the file sorted? \n");
                if(check == 'y')
                {
                        guess = get_int ("What value are you looking for " );
                        indx = binarySearch(array, guess, size);
                        printf("the index is %i \n", indx);

                }
                else
                {
                    printf("Sorry, you need a sorted file in order to search.\n");
                }
                break;
            case 3:
                check= get_char("Did you create a file and selected its size? y or n? \n");
                if(check == 'y')
                {
                    check = get_char("Selection 'S' or Bubble 'B' Sort?\n");
                    if(check == 'B')
                    {
                        array = bubbleSort(array, size);

                    }
                    else
                    {
                        array = selectionSort(array, size);

                    }
                }
                else
                {
                   choice = 1;
                }
            case 4:
            check = get_char("Do you want the data to print 'P' on the screen or save 'S' in a file?\n");
            if(check == 'P')
            {
                printArray(array, size);
            }
            else
            {
               writeArray(array, size);
            }

        }

     } while(choice !=5);
}
int *readFile(string fileName, int size, int size2 ) //read the file and creates the array
{
    FILE* file = (fopen(fileName, "r"));
    char line[size2]; // how many characters per line
    char options[size][size2]; //array to put all the numbers from the file
    int static numbers[SIZE2]; //file to be returned
    for (int i=0; i < size; i++)
    {
        fscanf(file, "%s", options[i]);
        numbers[i] = atoi(options[i]);
    }
    fclose(file);
    return numbers;

}
//linear search
int linearSearch(int array[],int guess,int size )
{
    for(int i=0; i < size; i++)
    {
        if (array[i]== guess)
        {
            return i;
        }
    }
    return -1;
}
//binary search
int binarySearch(int array[], int guess, int size)
 {

    int max_num = 5000;
    int min_num = 0;
    while ((max_num + min_num)/2 > 0)
    {
    int mid = (max_num + min_num)/2;
    if (guess == array[mid])
    {
        return mid;
    }
    else if (guess > array[mid]) // x is on the right side
        mid+=1;
    else                       // x is on the left side
        mid-=1;

    }
    return -1;
 }


// Selection sort
int *selectionSort(int array[], int size)
{
    int idx = 0;
    for(int i = 0; i < size; i++) //to sort the whole array
    {
        int min2 = size+1;
        for(int j = i; j < size; j++) // to find the new minimum
        {
            if(array[j] < min2)
            {
                min2 = array[j];
                idx = j;
        }

    }
    //swapping numbers
    char save_num = array[i]; // saving the number in the index i
    array[i] = array[idx]; // array[i] is the new minimum
    array[idx] = save_num; //array idx is now the saved num
    }
    return array;
 }
 void printArray(int array[], int size)
{
    for (int i=0; i< size; i++)
    {
        printf("%i \n", array[i]);
    }
}


//Bubble sort
int *bubbleSort(int array[], int size)
{
    bool stop;
    do
    {
        stop = true;
        for(int j = 0; j < size; j++ )
        {
            if (array[j] > array [j+1])
            {
                stop = false;
                int tempArr = array[j]; // saving the number in the index i
                array[j] = array[j+1]; // array[i] is the new minimum
                array[j+1] = tempArr; //array idx is now the saved num
            }
        }
    }while(!stop);
    return array;
}
void Menu()
{
    //make a menu
    printf("=============================================================\n");
    printf("#                            MENU                           #\n");
    printf("#          1) Linear Search                                 #\n");
    printf("#          2) Binary Search                                 #\n");
    printf("#          3) Sort                                          #\n");
    printf("#          4) Display Result                                #\n");
    printf("#          5) EXIT                                          #\n");
    printf("=============================================================\n");
}
void writeArray(int array[], int size) //can be copied and used for changing the file name
{
    string name = get_string("How do you want to call your file?\n");
    char filename[6];
    sprintf(filename, "%s.txt", name);
    FILE *file = fopen(filename, "w");
    for (int i=0; i < size; i++)
    {
        fprintf(file, "%d/n", array[i]);
    }
}
