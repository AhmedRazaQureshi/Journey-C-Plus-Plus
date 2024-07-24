//Questions on Array/Vectors
#include <iostream>
#include <vector>
using namespace std;

//Ques#01: Sort array of 0's, 1's & 2's [Sort Colors] (inplace)
//Method-1: Count 0's, 1's & 2's
void sortColorsMethod1(vector<int>& nums)
{
    int zero=0; 
    int one=0;
    int two=0;

    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] == 0)
            zero++;
        else if(nums[i] == 1)
            one++;
        else if(nums[i] == 2)
            two++;
    }

    for(int i=0; i<nums.size(); i++)
    {
        if(zero > 0)
        {
            nums[i] = 0;
            zero--;
        }
        else if(one > 0)
        {
            nums[i] = 1;
            one--;
        }   
        else if( two > 0)
        {
            nums[i] = 2;
            two--;
        }
            
    }
}
//Method-2: Three pointer approach (low will place 0's _ mid will place 1's _ high will place 2's)
void sortColorsMethod2(vector<int>& nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size()-1;

    while(mid <= high)
    {
        
    }
}

int main()
{
    //Ques#01: Sort array of 0's, 1's & 2's [Sort Colors] (inplace)

    //Method-1: Count 0's, 1's & 2's
    vector<int> nums1 = {2,0,2,1,1,0};
    sortColorsMethod1(nums1);
    cout<<"After sort nums1: ";
    for(auto i: nums1)
        cout<<i<<", ";
    cout<<endl<<endl;


    //Method-2: Three pointer approach
    nums1 = {2,0,2,1,1,0};
    sortColorsMethod2(nums1);
    cout<<"After sort nums1: ";
    for(auto i: nums1)
        cout<<i<<", ";
    cout<<endl<<endl;

    return 0;
}