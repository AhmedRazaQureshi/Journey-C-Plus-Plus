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

//Concept: Merge sort (Inplace)
//Method-1: Using mergeAlgo
void mergeAlgoInplace(vector<int>& nums, int s, int e)
{
    int m = s + (e - s) / 2;

    int i = s;   //To traverse left part (arr1)
    int j = m + 1; //To traverse right part (arr2)

    while (i <= m && j <= e)
    {
        if (nums[i] > nums[j])
        {
            // Step-1: Swap nums[i] & nums[j]
            swap(nums[i], nums[j]);
            // Step-2: After the swap, reposition the element nums[j] to its correct position
            int k = j;
            while (k < e && nums[k] > nums[k + 1])
            {
                swap(nums[k], nums[k + 1]);
                k++;
            }   
        }

        // Step-3: Increment i
        i++;
    }
}

void mergeSortInplaceByMergeAlgo(vector<int>& nums, int s, int e)
{
    //BC
    if(s >= e)
        return;

    //Recursion

    //Divide
    int m = s+(e-s)/2;
    mergeSortInplaceByMergeAlgo(nums, s, m);
    mergeSortInplaceByMergeAlgo(nums, m+1, e);

    //Conquer & Combine
    mergeAlgoInplace(nums, s, e);
}

//Method-2: Using Gap-Mehod
void mergeAlgoGapMethod(vector<int>& nums, int s, int e)
{
    int gap = (e-s+1)/2 + (e-s+1)%2; //ceil( (e-s+1)/2 ) 
    
    while(gap > 0)
    {
        int i = s;
        int j = i + gap;

        while(j <= e)
        {
            if(nums[i] > nums[j])
                swap(nums[i],nums[j]);

            i++;
            j++;
        }

        if(gap == 1) 
            gap = 0;

        else
            gap = (gap/2) + (gap%2);

    }
}

void mergeSortByGapMethod(vector<int>& nums, int s, int e)
{
    //BC
    if(s >= e)
        return;

    //Recursion
    
    //Divide
    int m = s+(e-s)/2;
    mergeSortByGapMethod(nums, s, m);
    mergeSortByGapMethod(nums, m+1, e);

    //Conquer and Combine
    mergeAlgoGapMethod(nums, s, e);
}


//Concept: Quick-sort
int partition(vector<int>& nums, int s, int e)
{
    //Step-1: Chhose pivot
    int pivot = nums[s];
    int p = s;

    //Step-2: Find correct position of pivot
    int count = 0;
    for(int i=s+1; i<=e; i++)
        if(nums[i] <= pivot)
            count++;

    swap(nums[p], nums[s+count]);
    p = s+count;

    //Step-3: Ensure  smaller...<PIVOT>...greater
    int i=s;
    int j=e;
    while(i<p && j>p)
    {
        while(nums[i] <= pivot)
            i++;
        
        while(nums[j] > pivot)
            j--;

        if(i<p && j>p)
            swap(nums[i],nums[j]);
    }

    return p;
}

void quickSort(vector<int>& nums, int s, int e)
{
    //BC
    if(s >= e)
        return;

    //Rec
    int p = partition(nums, s, e);

    quickSort(nums, s, p-1);
    quickSort(nums, p+1, e);
}

int main()
{
    //Concept: Merge-sort (Outplace)
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


    //Concept: Merge-sort (Inplace)
    //M-1: Using mergeAlgo
    vector<int> arr3 = {1,4,2,5,9,0,7,6,3,8};
    mergeSortInplaceByMergeAlgo(arr3, 0, arr3.size()-1);
    for(auto i: arr3)   
        cout<<i<<" ";
    cout<<endl;

    //M-2: Using gap-method
    vector<int> arr4 = {10,23,11,78,12,45,13};
    mergeSortByGapMethod(arr4, 0, arr4.size()-1);
    for(auto i: arr4)   
        cout<<i<<" ";
    cout<<endl;


    //Concept: Quick-sort
    vector<int> arr5 = {2,3,4,1,5,6,8,9,7,0};
    quickSort(arr5, 0, arr5.size()-1);
    for(auto i: arr5)   
        cout<<i<<" ";
    cout<<endl;

    return 0;
}