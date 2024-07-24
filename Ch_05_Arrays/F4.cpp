//Questions on Array/Vectors
#include <iostream>
#include <vector>
#include <algorithm>
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
        if(nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        }
        else if(nums[mid] == 1)
        {
            mid++;
        }
        else if(nums[mid] == 2)
        {
            swap(nums[mid], nums[high]);
            high--;
            //Not doing mid++ bec. agar swap k baad mid pe 2 aa gya to?
        }
    }
}


//Ques#02: Add two numbers represented by two arrays (each digit is in a cell of array)
vector<int> addTwoNumbersByArray(const vector<int>& nums1, const vector<int>& nums2)
{
    int i = nums1.size() - 1; // Pointer to the rightmost cell of array1
    int j = nums2.size() - 1; // Pointer to the rightmost cell of array2
    int carry = 0;
    vector<int> result;

    // The loop for addition
    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0) sum += nums1[i--];
        if (j >= 0) sum += nums2[j--];

        result.push_back(sum % 10);
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}


//Ques#03: Factorial of large no.s (using vector)
vector<int> findFactorialByVector(int n)
{
    vector<int> fact;
    
    






    return fact;
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

    
    //Ques#02: Add two numbers represented by two arrays (each digit is in a cell of array)
    vector<int> nums2 = {9, 5, 4, 9};
    vector<int> nums3 = {2, 1, 4};
    vector<int> sum = addTwoNumbersByArray(nums2, nums3);
    cout<<"Sum of nums2 & nums3: ";
    for(auto i: sum)
        cout<<i;
    cout<<endl<<endl;


    //Ques#03: Factorial of large no.s (using vector)
    int number = 7;
    vector<int> factorial = findFactorialByVector(7);
    cout<<"Factorial of 7: ";
    for(auto i: factorial)
        cout<<i;
    cout<<endl<<endl;


    return 0;
}