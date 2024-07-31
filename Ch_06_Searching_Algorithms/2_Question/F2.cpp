//Question: On Binary Search (BS)

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


//Ques#08: Find pivot element's index in sorted rotated array
int findPivotElementIndex(vector<int>& nums)
{
    //Edge case: When array isn't rotated at all
    if(nums[0] < nums[nums.size()-1])
        return nums.size()-1;

    //Regular cases
    int s=0;
    int e=nums.size()-1;
    int m=s+(e-s)/2;

    while(s < e)
    {
        //Special pivot elements k liye check
        if(nums[m] > nums[m+1] && m+1 < nums.size())
            return m;
        else if(nums[m] < nums[m-1] && m-1 >= 0)
            return m-1;

        if(nums[s] < nums[m]) //Go right
            s = m+1;
        else                 //Go left
            e = m-1;

        m = s+(e-s)/2;
    }

    return s; //When only single element in array    
}


//Ques#09: Find key in sorted rotated array
int binarySearchHelper(vector<int>& nums, int s, int e, int key)
{
    int mid = s + (e-s)/2;

    while(s <= e)
    {
        if(nums[mid] == key)
            return mid;              //Note: yaha return hi karwana, yu na krna ki ans=mid; kra re ho while loop mein 
        else if(key < nums[mid])     //                              aur loop k baad last mein return ans; kra re ho
            e = mid-1;
        else if(key > nums[mid])
            s = mid+1;

        mid = s+(e-s)/2;
    }

    return -1;
}

int findKeyInSortedRotated(vector<int>& nums, int key)
{
    int pivotIndex = findPivotElementIndex(nums);
    int ans = -1;
    //Part A
    if(nums[0]<=key && key<=nums[pivotIndex])
    {
        ans = binarySearchHelper(nums, 0, pivotIndex, key);
    }   

    //seedha else mat likho warna "not found" wala case bhi uss hi mein aa jayega

    //Part B
    if(nums[pivotIndex+1]<=key && key<=nums[nums.size()-1] && pivotIndex+1<nums.size())
    {
        ans = binarySearchHelper(nums, pivotIndex+1, nums.size()-1, key);
    } 
    
    return ans;
}


//Ques#10: Find sqrt. of 'n' using BS   [HAAL KHARAB QUESTION]
//Logic: Search space -> [0, n]  => BS on Search space
float findSqrtByBinSearch(int n, int precision)
{
    int s = 0;
    int e = n;
    int m = s+(e-s)/2;

    int integerPart;


    //Integer part 
    while(s <= e)
    {
        if(m*m == n)
            return m;

        else if(m*m < n)
        {
            s = m+1;
            integerPart = m;
        }

        else if(m*m > n)    
            e = m-1;

        m = s+(e-s)/2;
    }

    //Decimal part
    double floatPart = integerPart;
    double step = 0.1;
    for(int i=0; i<precision; i++)
    {
        for(double j=floatPart; j*j <= n; j+=step)
            floatPart = j;

        step /= 10;
    }


    return floatPart;
}


//Ques#11: Find key (by BS) in SORTED matrix
pair<int,int> binarySearchOnMatrix(vector<vector<int>>& matrix, int key)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    //Search space conversion (2D to 1D)
    int s = 0;
    int e = rows*cols - 1;
    int mid = s+(e-s)/2;

    while(s <= e)
    {
        int i = mid/cols;
        int j = mid%cols;

        if(matrix[i][j] == key)
            return {i,j};

        if(key < matrix[i][j])
            e = mid-1;
        else
            s = mid+1;

        mid = s+(e-s)/2;
    } 

    return {-1,-1};
}


//Ques#12: Find key in nearly sorted array
int findKeyInNearlySortedArray(vector<int>& nums, int key)
{
    int s=0;
    int e=nums.size()-1;
    int m=s+(e-s)/2;

    while(s <= e)
    {
        if(m-1 >= s && nums[m-1] == key)
            return m-1;
        else if(nums[m] == key)
            return m;
        else if(m+1 <= e && nums[m+1] == key)
            return m+1;


        if(key < nums[m])
            e = m-2;
        else    
            s = m+2;


        m=s+(e-s)/2;
    }

    return -1;
}


//Ques#13: Divide two numbers using BS [HAAL KHARAB QUESTION]
double findDivisionByBinSearch(int dividend, int divisor, int precision)
{
    int s = 0;
    int e = abs(dividend);
    int m = s+(e-s)/2;

    //Integer part of Quotient
    int integerQuotient;

    while(s <= e)
    {
        //Perfect division
        if(abs(divisor*m) == abs(dividend)) 
            return m;

        //Not perfect division
        if(abs(divisor*m) < abs(dividend))
        {
            integerQuotient = m;
            s = m+1;
        }
        else    
            e = m-1;

        
        m = s+(e-s)/2;
    }

    //Float part of Quotient
    double step = 0.1;
    double floatQuotient = integerQuotient;

    for(int i=0; i<precision; i++)
    {
        for(double j=floatQuotient; j*abs(divisor) <= abs(dividend); j+=step)
            floatQuotient=j;

        step /= 10;
    }


    if( (divisor>0 && dividend>0) || (divisor<0 && dividend<0) )
        return floatQuotient;
    else   
        return -floatQuotient;

}


//Ques#14: Find odd occuring element in pairArray
int findOddOccuringInPairArray(vector<int>& nums)
{
    int s=0;
    int e=nums.size()-1;
    int m=s+(e-s)/2;

    while(s <= e)
    {
        //Single lement reh gya ab loop chala chala k     //#  
        if(s == e)                                        //#  SNAKE ALERT 
            return nums[s];                               //#    

        //Two cases:
        //If mid is even
        if(!(m&1))
        {
            if( (m+1 <= e) && (nums[m] == nums[m+1]) ) //Go right
            {
                s = m+2;
            }
            else                                      //Go left
            {
                e = m;
            }
        }
        //If mid is odd
        else
        {
            if( (m-1 >= s) && (nums[m-1]==nums[m]) )  //Go right
            {
                s = m+1;
            }
            else                                     //Go left
            {
                e = m-1;
            }

        }

        m = s+(e-s)/2;
    }

    return -1;
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

    //Ques#08: Find pivot element's index in sorted rotated array
    vector<int> nums5 = {3,4,5,6,7,1,2};
    cout<<"Pivot element index is: "<<findPivotElementIndex(nums5)<<endl;
    cout<<"Pivot element is: "<<nums5[findPivotElementIndex(nums5)]<<endl<<endl;

    //Ques#09: Find key in sorted rotated array
    vector<int> nums6 = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 2};
    cout<<"Key 2 is found at index: "<<findKeyInSortedRotated(nums6, 2)<<endl<<endl;

    //Ques#10: Find sqrt. of 'n' using BS
    cout<<"Sqrt of 39: "<<findSqrtByBinSearch(10, 4)<<endl<<endl;

    //Ques#11: Find key (by BS) in SORTED matrix
    vector<vector<int>> nums7 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    pair<int,int> indices = binarySearchOnMatrix(nums7, 19);
    cout<<"19 is found at: "<<indices.first<<","<<indices.second<<endl<<endl;

    //Ques#12: Find key in nearly sorted array
    vector<int> nums8 = {10,3,40,20,50,80,70};
    cout<<"80 is found at: "<<findKeyInNearlySortedArray(nums8, 80)<<endl<<endl;

    //Ques#13: Divide two numbers using BS 
    cout<<"22/7 is : "<<findDivisionByBinSearch(22, 7, 5)<<endl<<endl;

    //Ques#14: Find odd occuring element in pairArray
    vector<int> nums9 = {1,1,  2,2,  3,3,  4,4,  3,  600,600,  4, 4};
    cout<<"Odd occuring element is: "<<findOddOccuringInPairArray(nums9)<<endl<<endl;



    return 0;
}
