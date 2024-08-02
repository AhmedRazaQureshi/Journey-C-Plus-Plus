//Question: On Linear Search (LS)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


//Ques#01: Find 'key' in array
int linearSearch(vector<int>& nums, int n, int key)
{
    for(int i=0; i<n; i++)
    {
        if(nums[i] == key)
            return i;
    }

    return -1;
}


//Ques#02: Count 0's & 1's in array
pair<int, int> countZeroOne(vector<int>& nums, int n)
{
    int zeroCount = 0;
    int oneCount = 0;

    for(int i=0; i<n; i++)
    {
        if(nums[i] == 0)
            zeroCount++;
        if(nums[i] == 1)
            oneCount++;
    }

    return {zeroCount, oneCount};
}


//Ques#03: Find min.m & max.m in array
pair<int, int> findMinMax(vector<int>& nums, int n)
{
    int max = INT_MIN;
    int min = INT_MAX;

    for(int i=0; i<n; i++)
    {
        if(nums[i] > max)
            max = nums[i];

        if(nums[i] < min)
            min = nums[i];
    }

    return {min, max};
}


//Ques#04: Print extremes in array
void printExtremes(vector<int>& nums, int n)
{
    int i=0, j=n-1;
    while(i < j)
    {
        cout<<nums[i]<<", "<<nums[j]<<", ";

        i++;
        j--;
    }

    cout<<endl;
}


//Ques#05: Reverse an array
void reverseArray(vector<int>& nums, int n)
{
    int i=0, j=n-1;

    while(i < j)
    {
        swap(nums[i], nums[j]);
        i++; j--;
    }
}


//Ques#06: Find unique element in array, every other element occurs twice
//LEETCODE: 136. Single number
int findUnique(vector<int>& nums)
{
    int ans=0;
    for(int i=0; i<nums.size(); i++)
        ans = ans^nums[i];

    return ans;
}


//Ques#07: Find intersection of two arrays
//LEETCODE: 349. Intersection of two arrays
vector<int> findIntersection(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> a = nums1;
    vector<int> b = nums2;

    vector<int> intersection;
    
    //n*LS
    for(int i=0; i<a.size(); i++)
        for(int j=0; j<b.size(); j++)
            if(a[i] == b[j])
            {
                intersection.push_back(a[i]);
                b[j] = INT_MIN; //Marker taaki baar baar intersection mein count na ho
            }
                
    return intersection;
}


//Ques#08: Find union of two arrays
//GFG: Union of two arrays
vector<int> findUnion(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> a = nums1;
    vector<int> b = nums2;

    vector<int> arrayUnion;

    //n*LS chala k common element ki jagah par INT_MIN daal do 'b' array mein 
    for(int i=0; i<a.size(); i++)
        for(int j=0; j<b.size(); j++)
            if(a[i] == b[j])
                b[j] = INT_MIN; //Marker taaki baar baar intersection mein count na ho
    
    //Dono arrays ko scan kr k elements store kra lo, common element ki jagah par INT_MIN pada hoga 'b' array mein
    for(int i=0; i<a.size(); i++)
        arrayUnion.push_back(a[i]);

    for(int i=0; i<b.size(); i++)
        if(b[i] != INT_MIN)
            arrayUnion.push_back(b[i]);

                
    return arrayUnion;
}


//Ques#09: Find pair that sums to 'k' in array
//LEETCODE: 1. Two sum
pair<int, int> findPairSum(vector<int>& nums, int k)
{
    //n*LS
    for(int i=0; i<nums.size(); i++)
        for(int j=i+1; j<nums.size(); i++)
            if(nums[i]+nums[j] == k)
                return {nums[i], nums[j]};

    return {-1, -1};
}


//Ques#10: Find triplet that sums to 'k' in array
//LEETCODE: 15. 3Sum
vector<int> findTripletSum(vector<int>& nums, int sum)
{
    vector<int> triplets;

    for(int i=0; i<nums.size(); i++)
        for(int j=i+1; j<nums.size(); j++)
            for(int k=j+1; k<nums.size(); k++)
                if(nums[i]+nums[j]+nums[k] == sum)
                {
                    triplets.push_back(nums[i]);
                    triplets.push_back(nums[j]);
                    triplets.push_back(nums[k]);
                    return triplets;
                }

    triplets.push_back(-1);
    return triplets;
}


//Ques#11: Sort an array of 0's & 1's
//LEETCODE: 905. Sort array by parity
void sortZeroOne(vector<int>& nums)
{
    //Approach: put all 0's in front of array
    int i=0; 
    // if nums[i] is 0 then put it in start
    // if nums[i] is 1 then put it in end
    int start=0; //Points to a position jisse peeche saare 0's hain
    int end=nums.size()-1; //Points to a position jisse aagey saare 1's hain
    // 0 0 0 0 0 1 0 1 1 1 0 1 1 1 1 1
    //         s i           e             

    while(i < end)
    {
        if(nums[i] == 0)
        {
            swap(nums[i], nums[start]);

            i++;  start++;
        }
        if(nums[i] == 1)
        {
            swap(nums[i], nums[end]);

            end--;
            //Not doing i++ bec. maybe 1 comes in front after swap
        }
    }
}


//Ques#12: Linear Search on 2D Array
pair<int,int> linearSearch2D(vector<vector<int>>& nums, int k)
{
    pair<int,int> loc;

    for(int i=0; i<nums.size(); i++)
        for(int j=0; j<nums[i].size(); j++)
            if(nums[i][j] == k)
                return {i,j};
            
    return {-1,-1};
}


//Ques#13: Max.m & Min.m in 2D Array
pair<int, int> findMinMax2D(vector<vector<int>>& nums)
{
    pair<int, int> minMax = {INT_MAX, INT_MIN};

    for(int i=0; i<nums.size(); i++)
        for(int j=0; j<nums[i].size(); j++)
            {
                if(nums[i][j] < minMax.first)
                    minMax.first = nums[i][j];
                if(nums[i][j] > minMax.second)
                    minMax.second = nums[i][j];
            }

    return minMax;
}

int main()
{   
    //Ques#01: Find 'key' in array
    vector<int> nums1 = {2, 1, 5, 3, 4, 6, 8, 7};
    cout<<"Index of 5: "<<linearSearch(nums1, 8, 5)<<endl;

    //Ques#02: Count 0's & 1's in array
    vector<int> nums2 = {0, 1, 1, 1, 0, 1, 0, 1};
    pair<int, int> count = countZeroOne(nums2, 8);
    cout<<"Count of 0's & 1's: "<<count.first<<" & "<<count.second<<endl;

    //Ques#03: Find min.m & max.m in array
    vector<int> nums3 = {-3, 12, 6, 34, -10, 5, 2, 3};
    pair<int, int> minMax = findMinMax(nums3, 8);
    cout<<"Min.m & Max.m : "<<minMax.first<<" & "<<minMax.second<<endl;

    //Ques#04: Print extremes in array
    vector<int> nums4 = {1, 2, 3, 4, 5, 6, 7, 8};
    cout<<"Printing extremes: ";
    printExtremes(nums4, 8);
   
    //Ques#05: Reverse an array
    vector<int> nums5 = {1, 2, 3, 4, 5, 6, 7, 8};
    reverseArray(nums5, 8);
    cout<<"Reversed array: ";
    for(int i=0; i<nums5.size(); i++)
        cout<<nums5[i]<<", ";
    cout<<endl;

    //Ques#06: Find unique element in array, every other element occurs twice
    vector<int> nums6 = {3, 2, 5, 2, 8, 3, 5, 6, 8};
    cout<<"Unique element: "<<findUnique(nums6)<<endl;

    //Ques#07: Find intersection of two arrays
    vector<int> nums7 = {1, 2, 3, 3, 4, 6, 8};
    vector<int> nums8 = {3, 3, 4, 10};
    vector<int> intersection = findIntersection(nums7, nums8);
    cout<<"Intersection: ";
    for(int i=0; i<intersection.size(); i++)
        cout<<intersection[i]<<", ";
    cout<<endl;

    //Ques#08: Find union of two arrays
    vector<int> nums9 = {1, 2, 3, 3, 4, 6, 8};
    vector<int> nums10 = {3, 3, 4, 10};
    vector<int> unionOfArrays = findUnion(nums9, nums10);
    cout<<"Union: ";
    for(int i=0; i<unionOfArrays.size(); i++)
        cout<<unionOfArrays[i]<<", ";
    cout<<endl;

    //Ques#09: Find pair that sums to 'k' in array
    vector<int> nums11 = {1, 3, 5, 7, 2, 4, 6};
    int k = 9;
    cout<<"Pair sums to 9 are: ";
    pair<int, int> pairSum = findPairSum(nums11, k);
    cout<<pairSum.first<<", "<<pairSum.second<<endl;

    //Ques#10: Find triplet that sums to 'k' in array
    k = 11;
    cout<<"Triplet sums to 11 are: ";
    vector<int> tripletSum = findTripletSum(nums11, k);
    cout<<tripletSum[0]<<", "<<tripletSum[1]<<", "<<tripletSum[2]<<endl;

    //Ques#11: Sort an array of 0's & 1's
    vector<int> nums12 = {0, 1, 1, 0, 1, 0, 1, 0, 1};
    cout<<"After sort: ";
    sortZeroOne(nums12);
    for(auto i: nums12)
        cout<<i<<" ";
    cout<<endl;

    //Ques#12: Linear Search on 2D Array
    vector<vector<int>> nums13 = {{3,2,1},{6,5,4},{9,8,7},{12,11,10},{15,14,13}};
    k = 11;
    pair<int,int> location = linearSearch2D(nums13, k);
    cout<<"Location of 11: "<<location.first<<", "<<location.second<<endl;

    //Ques#13: Max.m & Min.m in 2D Array
    pair<int, int> minMax2D = findMinMax2D(nums13);
    cout<<"Min.m & Max.m : "<<minMax2D.first<<", "<<minMax2D.second<<endl;


    


    return 0;
}