#include<iostream>
using namespace std;
int** create_2d_array(int rows,int cols)
{
    //declare a double pointer to hold the array 
    int **arr = new int*[rows]; 

    if(arr == nullptr)
        return nullptr;
    //Allocate space for columns in each row 
    for(int i=0;i<rows;i++)
    {
        //allocate space for col number of elements in each row 
        arr[i] = new int[cols]; 

        if(arr[i]==nullptr)
            return nullptr;

        //Initialize and fill the array elements 
        int k = 0; 
        for(int j=0;j<cols;j++)
        {
            arr[i][j] = k++;
        }
    }
    return arr;
}

void print_dynamic_2d_array(int **arr,int rows,int cols)
{
    if(arr == nullptr)
    {
        cout<<"Array is empty"<<endl;
        return ;
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void free_2d_array(int **arr,int rows)
{
    if(arr == nullptr) return ; 
    for(int i=0;i<rows;i++)
    {
        if(arr[i])
            delete[] arr[i];
    }
    delete arr;
    cout<<"Memory successfully deleted from 2d array "<<endl;
}

int main()
{
    int **matrix = create_2d_array(3,3); 
    if(matrix)
    {
        print_dynamic_2d_array(matrix,3,3);
        free_2d_array(matrix,3);
    }
    return 0;
}