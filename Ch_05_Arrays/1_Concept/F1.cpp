//Array basics
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //1D Array :---
    //Method-1
    int a1[] = {1, 2, 3, 4, 5};

    //Method-2
    int* a2 = new int[5];
    a2[0] = 1; 
    a2[1] = 2;
    a2[2] = 3;
    a2[3] = 4;
    a2[4] = 5;      //To deallocate: delete[] a2

    //Method-3
    int* a3 = (int*) malloc(5*sizeof(int));
    a3[0] = 1; 
    a3[1] = 2;
    a3[2] = 3;
    a3[3] = 4;
    a3[4] = 5;     //To deallocate: free(a4); a4=NULL;



    //2D Array :---
    //Method-1: Static (5x3)
    int a5[][3] = {{1,2,3},
                   {4,5,6},
                   {7,8,9},
                   {10,11,12},
                   {13,14,15}};

    //Method-2: Dynamic (5x3)
    int** a6 = new int*[5];
    for(int i=0; i<5; i++)
        a6[i] = new int[3];

    int temp=1;
    for(int i=0; i<5; i++)
        for(int j=0; j<3; j++)
            a6[i][j] = temp++; //i.e. a6 = {{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}};
    

    return 0;
}