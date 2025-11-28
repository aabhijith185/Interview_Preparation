#include<stdio.h>
#include<stddef.h>

struct Student
{
    int id; 
    float mark;
}; 

int main(void)
{
    struct Student s = {5,6.5};

    //(char*)&s ->structure is casted to character pointer for byte by byte memory access
    int *iptr = (int*)((char*)&s +offsetof(struct Student,id));
    float *fptr =(float*)((char*)&s + offsetof(struct Student,mark));

    printf("id: %d\n",*iptr);
    printf("mark: %0.2f\n",*fptr);

    return 0;

}