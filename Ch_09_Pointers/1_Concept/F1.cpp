//Concept: Basics of pointers
#include <iostream>
using namespace std;

//2. Passing array to a function using pointer
void printArray(int* a, int n) //(or) int a[]
{
    for(int i=0; i<n; i++)
        cout<<a[i]<<", ";
    cout<<endl;
}

//3. Pointer to a function
void findSum(int a, int b)
{
    cout<<"Sum: "<<a+b<<endl;
}


//4. An array of function pointers
void findProduct(int a, int b)
{
    cout<<"Product: "<<a*b<<endl;
}
int findDifference(int a, int b)
{
    return a-b;
}


//7. Return by reference
int& fun(int& x)
{
    cout<<"x value: "<<x<<" --- "<<"x address: "<<&x<<endl;

    return x;
}


int main()
{   
    //0. A good practice
    int *p1; //Bad practice (Wild pointer)
    int *p2=0; //(or) nullptr; Good practice
    int something = 123;
    p1 = &something;
    p2 = &something;
    

    //1. An array of pointers
    int* ptr[3];   //An array named 'ptr' having 3 elements of int pointers
    int (*qtr)[3]; //A nameless array of 3 elements of type int data, pointed by 'qtr'

    int val1=10, val2=20, val3=30;
    
    ptr[0] = &val1;
    ptr[1] = &val2;
    ptr[2] = &val3;

    *qtr[0] = 10;
    *qtr[1] = 20;
    *qtr[2] = 30;



    //2. Passing array to a function by using pointer
    int a1[5] = {1,2,3,4,5};
    int n1 = 5;
    printArray(a1, n1);
    cout<<endl;



    //3. Pointer to a function
    int a = 1, b = 2;
    void (*p3) (int,int); //p3 is pointer to a function whose return type is 'void' and takes 2 parameters 'int' & 'int'
    p3 = findSum;
    p3(a, b); //calling fx.n
    cout<<endl;



    //4. An array of function pointers
    int x=4, y=2;
    void (*p4[3]) (int,int); //p4 is an array of function pointers
    p4[0] = findSum;
    p4[1] = findProduct;
    int (*diffSignature)(int,int) = findDifference; //Alag signature ka function

    p4[2] = (void (*)(int,int)) diffSignature; //Casting to match the array type

    p4[0](x,y);
    p4[1](x,y);
    int res = ((int (*)(int, int))p4[2])(x, y);
    cout<<"Difference: "<<res<<endl;
    cout<<endl;




    //4. Void pointer (or) Generic pointer
    void *p5;
    int n2 = 50;
    p5 = &n2;
    int* q = static_cast<int*>(p5); //(or) (int*)p5   but not advised
    cout << "Value of n2: " << *q <<endl;   
    cout<<endl;
    //NOTE: direct print karaoge p5 ko to segmentation fault ayega {i.e. cout << *( static_cast<int*>(p5) ); =>Error }



    //5. Double pointer
    int *p6 = 0;
    int **p7 = 0;
    


    //6. Reference variable : same memory location referred by different labels
    int x_org = 789;
    int& x_1 = x_org;
    int& x_2 = x_org;
    cout<<"x: "<<x_org<<" "<<x_1<<" "<<x_2<<endl;



    //7. Return by reference
    int number = 420;
    int& r1 = fun(number);
    cout<<"number value: "<<number<<" --- "<<"number address: "<<&number<<endl;
    cout<<"r1 value: "<<r1<<" --- "<<"r1 address: "<<&r1<<endl;
    cout<<"-------------------------------------------------"<<endl;
    fun(number) = 320;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"number value: "<<number<<" --- "<<"number address: "<<&number<<endl;
    cout<<"r1 value: "<<r1<<" --- "<<"r1 address: "<<&r1<<endl;







    return 0;
}