#include <bits/stdc++.h>
using namespace std;

// LEETCODE: 867. Transpose Matrix
vector<vector<int>> transpose(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    // NOTE: if original matrix is mxn,
    //       then transpose matris is nxm
    vector<vector<int>> newMatrix(n, vector<int>(m, 0));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            newMatrix[j][i] = matrix[i][j];

    return newMatrix;
}

// LEETCODE: 75. Sort colors
void sortColors(vector<int> &nums)
{
    // One pass solution
    int low = 0;                // Will place 0's
    int mid = 0;                // Will place 1's
    int high = nums.size() - 1; // Will place 2's

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else if (nums[mid] == 2)
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

// LEETCODE: 2. Add two numbers
vector<int> addTwoNumbersByArray(vector<int> &nums1, vector<int> &nums2)
{
    int i = nums1.size() - 1; // Pointer to the rightmost cell of array1
    int j = nums2.size() - 1; // Pointer to the rightmost cell of array2
    int carry = 0;
    vector<int> result;

    // The loop for addition
    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
            sum += nums1[i--];
        if (j >= 0)
            sum += nums2[j--];

        result.push_back(sum % 10);
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    vector<int> nums1;
    vector<int> nums2;

    // Convert the first linked list to an array
    ListNode *p = l1;
    while (p != NULL)
    {
        nums1.push_back(p->val);
        p = p->next;
    }

    // Convert the second linked list to an array
    ListNode *q = l2;
    while (q != NULL)
    {
        nums2.push_back(q->val);
        q = q->next;
    }

    // Use the addTwoNumbersByArray function to add the two arrays
    reverse(nums1.begin(), nums1.end());
    reverse(nums2.begin(), nums2.end());
    vector<int> sum = addTwoNumbersByArray(nums1, nums2);
    reverse(sum.begin(), sum.end());

    // Convert the sum array back to a linked list
    ListNode *ans = new ListNode(sum[0]);
    ListNode *ptr = ans;
    for (int i = 1; i < sum.size(); i++)
    {
        ListNode *temp = new ListNode(sum[i]);
        ptr->next = temp;
        ptr = ptr->next;
    }

    return ans;
}


// GFG: Factorials of large numbers
vector<int> factorial(int N)
{
    int n = N;
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;

    for (int i = 2; i <= n; i++)
    {
        // Loop for vector (ans)
        for (int j = 0; j < ans.size(); j++)
        {
            int currAns = ans[j] * i + carry;

            // Push the digit in vector
            ans[j] = currAns % 10;
            // Carry forward
            carry = currAns / 10;
        }

        // Carry can be multi digits, so one more loop
        while (carry)
        {
            int currAns = carry % 10;

            // Push the digit in vector
            ans.push_back(currAns);
            // Decrease carry
            carry /= 10;
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
