//##### :QUESTIONS: #####
//Binary Search 

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


//Ques#01: Find key in SORTED array
int binarySearch(vector<int>& nums, int k)
{
    int s = 0;
    int e = nums.size() - 1;
    int m = s + (e-s)/2; //Integer overflow na ho taki
    
    while(s <= e)
    {
        if(nums[m] == k)
            return m;
        
        if(k < nums[m])      //-> Go Left
            e = m - 1;
        else                 //-> Go Right
            s = m + 1;

        m = s + (e-s)/2;
    }

    return -1;
}


//Ques#02: Find key in array using STL BS
bool binarySearchSTL(vector<int>& nums, int k)
{
    return binary_search(nums.begin(), nums.end(), k);
}


//Ques#03: Find first occurence of 'key' in SORTED array
int findFirstOccurence(vector<int>& nums, int k)
{
    int index = -1;

    int s = 0;
    int e = nums.size()-1;
    int m = s + (e-s)/2;

    while(s <= e)
    {
        if(nums[m] == k)
        {
            index = m;
            //Try finding in even more left
            e = m-1;
        }
        else if(k < nums[m])   // -> Go Left
            e = m-1;
        else                   // -> Go Right
            s = m+1;


        m = s + (e-s)/2;
    }

    return index;
}


//Ques#04: Find last occurence of 'key' in SORTED array
int findLastOccurence(vector<int>& nums, int k)
{
    int index = -1;

    int s = 0;
    int e = nums.size()-1;
    int m = s + (e-s)/2;

    while(s <= e)
    {
        if(nums[m] == k)
        {
            index = m;
            //Try finding in even more right
            s = m+1;
        }
        else if(k < nums[m])   // -> Go Left
            e = m-1;
        else                   // -> Go Right
            s = m+1;


        m = s + (e-s)/2;
    }

    return index;
}


//Ques#05: Find total # of occurences of 'k' in SORTED array
int findTotalOccurence(vector<int>& nums, int k)
{
    int firstOccurence = findFirstOccurence(nums, k);
    int lastOccurence = findLastOccurence(nums, k);

    return (lastOccurence - firstOccurence + 1);
}


//Ques#06: Find missing element in SORTED array (Elements: 1 to n-1)
int findMissingElement(vector<int>& nums)
{
    int s = 0;
    int e = nums.size()-1;
    int m = s + (e-s)/2;

    int missingElement = INT_MIN;

    while(s <= e)
    {
        if(nums[m] == (m+1))  //Go right
            s = m+1;

        else if(nums[m] != (m+1))  //Go left
        {
            missingElement = nums[m]-1; //or missingELement = m+1;
            e = m-1;
        }

        m = s + (e-s)/2;
    }

    return missingElement;
}


//Ques#07: Peak element in a mountain array
int findPeakElement(vector<int>& nums)
{
    int s = 0;
    int e = nums.size()-1;
    int mid = s+(e-s)/2;

    while(s <= e)
    {
        if( (nums[mid-1] < nums[mid]) && (nums[mid] > nums[mid+1]) ) //Found
            return nums[mid];
        else if( (nums[mid-1] < nums[mid]) && (nums[mid] < nums[mid+1]) ) //Go right
            s = mid+1;
        else if( (nums[mid-1] > nums[mid]) && (nums[mid] > nums[mid+1]) ) //Go left
            e = mid-1;
    }

    return -1;
}


//Ques#08: Find pivot element in sorted rotated array
int findPivotElement(vector<int>& nums)
{
    
}


int main()
{
    //Ques#01: Find key in SORTED array
    vector<int> nums1 = {2, 3, 5, 8, 9, 23, 54};
    cout<<"Index of 8 is: "<<binarySearch(nums1, 8)<<endl<<endl;

    //Ques#02: Find key in array using STL BS
    cout<<"Is 54 present ? : "<<binarySearchSTL(nums1, 54)<<endl<<endl;

    //Ques#03: Find first occurence of 'key' in SORTED array
    vector<int> nums2 = {1,3,4,4,4,4,4,6,7,9};
    cout<<"First occurence of 4 at: "<<findFirstOccurence(nums2, 4)<<endl<<endl;

    //Ques#04: Find last occurence of 'key' in SORTED array
    cout<<"Last occurence of 4 at: "<<findLastOccurence(nums2, 4)<<endl<<endl;

    //Ques#05: Find total # of occurences of 'k' in SORTED array
    cout<<"Total occurences of 4 are: "<<findTotalOccurence(nums2, 4)<<endl<<endl;

    //Ques#06: Find missing element in SORTED array (Elements: 1 to n-1)
    vector<int> nums3 = {1,2,3,4,6,7,8};
    cout<<"Missing element is: "<<findMissingElement(nums3)<<endl<<endl;

    //Ques#07: Peak element in a mountain array
    vector<int> nums4 = {0, 10, 5, 2};
    cout<<"Peak element is: "<<findPeakElement(nums4)<<endl<<endl;

    //Ques#08: Find pivot element in sorted rotated array
    vector<int> nums5 = {3,4,5,6,7,1,2};
    cout<<"Pivot element is: "<<findPivotElement(nums5)<<endl<<endl;


    return 0;
}
