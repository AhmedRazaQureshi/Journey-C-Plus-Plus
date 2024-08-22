#include <bits/stdc++.h>
using namespace std;

// LEETCODE: 912. Sort an array
void mergeAlgoGapMethod(vector<int> &nums, int s, int e)
{
    int gap = (e - s + 1) / 2 + (e - s + 1) % 2; // ceil( (e-s+1)/2 )

    while (gap > 0)
    {
        int i = s;
        int j = i + gap;

        while (j <= e)
        {
            if (nums[i] > nums[j])
                swap(nums[i], nums[j]);

            i++;
            j++;
        }

        if (gap == 1)
            gap = 0;

        else
            gap = (gap / 2) + (gap % 2);
    }
}

void mergeSortByGapMethod(vector<int> &nums, int s, int e)
{
    // BC
    if (s >= e)
        return;

    // Recursion

    // Divide
    int m = s + (e - s) / 2;
    mergeSortByGapMethod(nums, s, m);
    mergeSortByGapMethod(nums, m + 1, e);

    // Conquer and Combine
    mergeAlgoGapMethod(nums, s, e);
}

vector<int> sortArray(vector<int> &nums)
{
    mergeSortByGapMethod(nums, 0, nums.size() - 1);
    return nums;
}

// LEETCODE: 88. Merge sorted array
// Method used: Inplace (USING MERGE-ALGO)
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    // int m = s + (e - s) / 2;

    int i = 0; // To traverse left part (arr1)
    int j = 0; // To traverse right part (arr2)

    while (i < m && j < n)
    {
        if (nums1[i] > nums2[j])
        {
            // Step-1: Swap nums[i] & nums[j]
            swap(nums1[i], nums2[j]);
            // Step-2: After the swap, reposition the element nums[j] to its correct position
            int k = j;
            while (k < n - 1 && nums2[k] > nums2[k + 1])
            {
                swap(nums2[k], nums2[k + 1]);
                k++;
            }
        }

        // Step-3: Increment i
        i++;
    }

    // Copy remaining elements of nums2 into nums1
    for (int k = 0; k < n; k++)
        nums1[m + k] = nums2[k];
}