#include<stdio.h>
#include<stdlib.h>

#define ROWS 3 
#define COLS 4 

//Function to allocate and initialize the 2D Array in heap 
int** create_2d_array(int rows,int cols)
{
    //declare a double pointer ot hold the array 
    int **arr; 

    //Allocate space for array of raw pointers 
    arr = (int**)malloc(rows *sizeof(int*)); 

    if(arr == NULL)
        return NULL; 
    //Allocate space for the column data in each row 
    for(int i=0;i<rows;i++)
    {
        //allocate space for the cols number of integers in the current row
        arr[i] = (int *) malloc(cols*sizeof(int)); 

        if(arr[i]== NULL)
            return NULL;    

        int k=0;
        //Initialize and fill the array element 
        for(int j=0;j<cols;j++)
        {
            arr[i][j] = k++;
        }
    }
    return arr;
}

void print_2d_array(int **arr,int rows,int cols)
{
    printf("Printing Dynamic 2D Array (%d x %d)\n",rows,cols); 
    if(arr == NULL)
    {
        printf("Array is NULL"); 
        return;
    }

    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%3d ",arr[i][j]);
        }
        printf("\n");
    }
}

//Function to free the memory 
void free_2d_array(int **arr,int rows)
{
    if(arr == NULL) return ; 

    //Free memory allocated for each row 
    for(int i=0;i<rows;i++)
    {
        if(arr[i]!= NULL)
            free(arr[i]);
    }

    //free memory allocated for array of row pointers 
    free(arr);
    printf("Memory succesfully deleted from 2D array \n"); 
}
int main() {
    // Call the function to create and allocate the 2D array on the heap.
    int **matrix = create_2d_array(ROWS, COLS);

    if (matrix != NULL) {
        // Use the array
        print_2d_array(matrix, ROWS, COLS);
        
        // Clean up the memory
        free_2d_array(matrix, ROWS);
    }

    return 0;
}