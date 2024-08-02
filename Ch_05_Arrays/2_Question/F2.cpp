//Question: On C Like Arrays
#include <iostream>
using namespace std;

//Ques#01: Find row-wise sum
int* findSumOfRows(int** a, int m, int n)
{
    int* sum = new int[m];

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            sum[i] += a[i][j];

    return sum;
}


//Ques#02: Find col-wise sum
int* findSumOfCols(int** a, int m, int n)
{
    int * sum = new int[n];

    for(int j=0; j<n; j++)
        for(int i=0; i<m; i++)
            sum[j] += a[i][j];

    return sum;
}


//Ques#03: Transpose of sq. matrix (inplace)
void squareMatrixTranspose(int** a, int n)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)
            swap( a[i][j] , a[j][i]  );
}


//Ques#04: Transpose of non-sq. matrix (outplace)
//LEETCODE: 867. Transpose Matrix
int** allMatrixTranspose(int** a, int m, int n)
{
    //Given matrix -> mXn
    //Transpose matrix ->nXm
    int** ans = new int*[n];
    for(int i=0; i<n; i++)
        ans[i] = new int[m];

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            ans[j][i] = a[i][j];

    return ans;
}

int main()
{
    //Ques#01: Find row-wise sum
    int** a1 = new int*[5];
    for(int i=0; i<5; i++)
        a1[i] = new int[3];

    int temp=1;
    for(int i=0; i<5; i++)
        for(int j=0; j<3; j++)
            a1[i][j] = temp++;   //i.e. a1 = {{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}};

    
    int* sumOfRows = findSumOfRows(a1, 5, 3);
    cout<<"Sums of rows: ";
    for(int i=0; i<5; i++)
        cout<<sumOfRows[i]<<", ";
    cout<<endl;


    //Ques#02: Find col-wise sum
    int* sumOfCols = findSumOfCols(a1, 5, 3);
    cout<<"Sums of rows: ";
    for(int i=0; i<3; i++)
        cout<<sumOfCols[i]<<", ";
    cout<<endl;


    //Ques#03: Transpose of sq. matrix (inplace)
    temp=1;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            a1[i][j] = temp++;   //i.e. a1 = {{1,2,3},{4,5,6},{7,8,9}};
    squareMatrixTranspose(a1, 3);
    cout<<"After transpose: "<<endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
            cout<<a1[i][j]<<", ";
        cout<<endl;
    }  
    cout<<endl;


    //Ques#04: Transpose of non-sq. matrix (outplace)
    temp=1;
    for(int i=0; i<5; i++)
        for(int j=0; j<3; j++)
            a1[i][j] = temp++;   //i.e. a1 = {{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}};
    int** ans = allMatrixTranspose(a1, 5, 3);
    cout<<"After transpose: "<<endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<5; j++)
            cout<<ans[i][j]<<", ";
        cout<<endl;
    }

    return 0;
}