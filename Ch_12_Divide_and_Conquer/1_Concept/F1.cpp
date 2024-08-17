#include <bits/stdc++.h>
using namespace std;

//Concept: Merge-sort (Outplace)
//M-1: (Fazool)
int* mergeAlgo_M1(int* a1, int* a2, int n1, int n2)
{
    int i=0, j=0, k=0;
    int* merge = new int[n1+n2]; //Merged array

    while(i<n1 && j<n2)
    {
        if(a1[i] < a2[j])
            merge[k++] = a1[i++];
        else
            merge[k++] = a2[j++];
    }
    
    while(i<n1)
        merge[k++] = a1[i++];
    while(j<n2)
        merge[k++] = a2[j++];

    
    return merge;
}

void copyArray(int* src, int* dst, int n)
{
    for(int i=0; i<n; i++)
        dst[i] = src[i];
}

int* mergeSort_M1(int* arr, int s, int e)
{
    //BC
    if(s == e)  return arr+s;

    //Rec
    //Divide
    int m = (s+e)/2;
    int* a1 = mergeSort_M1(arr, s, m);
    int* a2 = mergeSort_M1(arr, m+1, e);

    //Conquer & Combine
    int n1 = m-s+1;
    int n2 = e-(m+1)+1;
    int* ans = mergeAlgo_M1(a1, a2, n1, n2);

    copyArray(ans, arr+s, e-s+1);  //Ans ko copy kro, sahi location par

    delete[] ans;                  //Space free kro

    return arr+s;
}

//M-2: (Behtareen)
void mergeAlgo_M2(int* arr, int s, int e)
{
    //Step-1: Creating two arrays for merging
    int m = s+(e-s)/2;
    int len1 = m-s+1;
    int len2 = e-(m+1)+1;

    int *left = new int[len1];
    int *right = new int[len2];


    //Step-2: Copy left-elements of actual array to *left and copy right-elements of actual array to *right
    int k = s; //for actual/original array
    for(int i=0; i<len1; i++)
        left[i] = arr[k++];
    k = m+1;
    for(int i=0; i<len2; i++)
        right[i] = arr[k++];


    //Step-3: Merge *left & *right into actal/original array
    int i=0;
    int j=0;
    k=s;

    while(i<len1 && j<len2)
    {
        if(left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while(i<len1)
        arr[k++] = left[i++];
    while(j<len2)
        arr[k++] = right[j++];

    //Step-4: Free space
    delete[] left;
    delete[] right;
}

void mergeSort_M2(int* arr, int s, int e)
{
    //BC
    if(s >= e)
        return; //single element => do nothing

    //Divide
    int m = s+(e-s)/2;
    mergeSort_M2(arr, s, m);
    mergeSort_M2(arr, m+1, e);

    //Conquer and Combine
    mergeAlgo_M2(arr, s, e);

}


int main()
{
    //Concept: Merge-sort
    //M-1
    int arr1[] = {2,5,1,19,7,55,0};
    int s1=0;
    int e1=6;
    mergeSort_M1(arr1,s1,e1);
    for(auto i: arr1)   
        cout<<i<<" ";
    cout<<endl;

    //M-2
    int arr2[] = {1,3,2,0,5,7,6,9};
    int s2=0;
    int e2=6;
    mergeSort_M2(arr2,s2,e2);
    for(auto i: arr2)   
        cout<<i<<" ";
    cout<<endl;

    return 0;
}