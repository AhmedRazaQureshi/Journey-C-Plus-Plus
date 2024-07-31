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


//#4: 

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

    //#4: 


    return 0;
}









