//Sorting Algorithms codes:
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//#1: Selection sort
void selectionSort(vector<int>& nums)
{
    int n = nums.size();
    //n-1 passes
    for(int i=0; i<n; i++)
    {
        int minIndex;
        int minElement = INT_MAX;
        for(int j=i; j<nums.size(); j++)
            if(nums[j] < minElement)
                {
                    minElement = nums[j];
                    minIndex = j;
                }

        swap(nums[i], nums[minIndex]);
    }
}


//#2: Bubble sort
void bubbleSort(vector<int>& nums)
{
    int n = nums.size();
    int swapCount;

    for(int i=0; i<n; i++)
    {
        swapCount = 0;

        for(int j=0; j<n-1-i; j++)
        {
            if(nums[j] > nums[j+1])
            {
                swap(nums[j],nums[j+1]);
                swapCount++;
            }
        }

        if(swapCount == 0)
            break;
    }   

}


//#3: Insertion sort     [HAAL KHARAB]
void insertionSort(vector<int>& nums)
{
    //n-1 passes

    for(int i=0; i<nums.size()-1; i++)   //'i' points to newly inserted element in left part
    {
        for(int j=i+1; j>=0; j--)      //'j' starts from i+1 and keep on going to the left, 
        {                              //asking it's previous element, "Are you greater than me?"
            if(nums[j] < nums[j-1])
                swap(nums[j],nums[j-1]);
            else
                break;
        }
        
    }
}


//#4: Merge sort [HAAL KHARAB]
//M-4.1: Outplace
void mergeAlgoOutplace(vector<int>& nums, int s, int e)
{
    //Step-1: Create two arrays
    int m = s+(e-s)/2;
    int len1 = m-s+1;
    int len2 = e-m;

    vector<int> left(len1);
    vector<int> right(len2);

    //Step-2: Populate left & right arrays with 'nums'
    int k=s; //for nums traversal
    for(int i=0; i<len1; i++)
        left[i] = nums[k++];

    k=m+1;
    for(int i=0; i<len2; i++)
        right[i] = nums[k++];

    //Step-3: Merge left & right into 'nums', but make sure correct ranges of 'nums'
    int i=0; //For left<vector> traversal
    int j=0; //For right<vector> traversal
    k = s; //For nums<vector> traversal

    while(i<len1 && j<len2)
    {
        if(left[i] < right[j])
            nums[k++] = left[i++];
        else
            nums[k++] = right[j++];
    }

    while(i<len1)
        nums[k++] = left[i++];

    while(j<len2)
        nums[k++] = right[j++];
}

void mergeSortOutplace(vector<int>& nums, int s, int e)
{
    //BC
    if(s >= e)
        return;  //1 element => do nothing


    //Divide
    int m = s+(e-s)/2;
    mergeSortOutplace(nums, s, m);
    mergeSortOutplace(nums, m+1, e);

    //Conquer & Combine
    mergeAlgoOutplace(nums, s, e);
}

//M-4.2.1: Inplace (USING MERGE-ALGO)
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

//M-4.2.2: Inplace (USING GAP-METHOD)
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

//#5: Quick sort
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



//Just a helper to print array
void printArray(vector<int>& nums)
{
    cout<<"After sorting: ";
    for(int i=0; i<nums.size(); i++)
        cout<<nums[i]<<",";
    
    cout<<endl<<endl;
}



int main()
{
    //#1: Selection sort
    vector<int> nums1 = {5,4,3,2,1};
    selectionSort(nums1);
    printArray(nums1);

    //#2: Bubble sort
    vector<int> nums2 = {10,9,8,7,6};
    bubbleSort(nums2);
    printArray(nums2);

    //#3: Insertion sort
    vector<int> nums3 = {15,14,13,12,11};
    insertionSort(nums3);
    printArray(nums3);

    //#4.1: Merge sort (outplace)
    vector<int> nums4 = {100, 87, 200, 65, 34, 90};
    mergeSortOutplace(nums4, 0, nums4.size()-1);
    printArray(nums4);

    //#4.2.1: Inplace (USING MERGE-ALGO)
    vector<int> nums5 = {12, 65, 1, 3, 2, 8, 50};
    mergeSortInplaceByMergeAlgo(nums5, 0, nums5.size()-1);
    printArray(nums5);

    //#4.2.2: Inplace (USING GAP-METHOD)
    vector<int> nums6 = {34, 56, 23, 1, 45, 100, 55};
    mergeSortByGapMethod(nums6, 0, nums6.size()-1);
    printArray(nums6);

    //#5: Quick-sort
    vector<int> nums7 = {1,6,3,9,7,0,2,5,4,8};
    quickSort(nums7, 0, nums7.size()-1);
    printArray(nums7);

    return 0;
}









