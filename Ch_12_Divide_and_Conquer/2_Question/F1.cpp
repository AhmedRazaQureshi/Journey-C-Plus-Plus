#include <bits/stdc++.h>
using namespace std;

//Ques#01: Inversions count

long mergeAlgo(vector<int>& nums, int s, int m, int e)
{
    int i = s;
    int j = m+1;
    long c = 0;

    vector<int> temp; //Temporary array to merge nums ->[s to m] & [m+1 to e]

    while(i<=m && j<=e)
    {
        if(nums[i] > nums[j]) 
        {
            //Inversion occurred
            c += (m-i+1);
            temp.push_back(nums[j++]);
        }
        else
            temp.push_back(nums[i++]);
    }

    while(i<=m)
        temp.push_back(nums[i++]);
    while(j<=e)
        temp.push_back(nums[j++]);

    
    //Copy back temp into original
    int k = s;
    for(int i=0; i<temp.size(); i++)
        nums[k++] = temp[i];

    return c;

}

long mergeSort(vector<int>& nums, int s, int e)
{
    //BC
    if(s >= e)
        return 0; //1 element => 0 inversions

    //Rec
    int m = s+(e-s)/2;
    long c = 0;

    c += mergeSort(nums, s, m);
    c += mergeSort(nums, m+1, e);

    c += mergeAlgo(nums, s, m, e);

    return c;

}

long findInversionCount(vector<int>& nums)
{
    long c = 0; //Inversion count
    
    int s=0;
    int e=nums.size()-1;

    c = mergeSort(nums, s, e);
    return c; 
}


int main()
{
    //Ques#01: Inversions count
    vector<int> nums1 = {24, 18, 38, 43, 14, 40, 1, 54};
    long inversionCount = findInversionCount(nums1);
    cout<<"Number of inversions: "<<inversionCount<<endl; 



    return 0;
}