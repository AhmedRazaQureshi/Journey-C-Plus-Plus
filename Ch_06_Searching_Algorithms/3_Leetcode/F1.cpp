#include <bits/stdc++.h>
using namespace std;

// LEETCODE: 136. Single number
int singleNumber(vector<int> &nums)
{
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++)
        ans = ans ^ nums[i];

    return ans;
}

// LEETCODE: 349. Intersection of two arrays
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> a = nums1;
    vector<int> b = nums2;

    vector<int> intersection;

    // n*LS
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            if (a[i] == b[j])
            {
                intersection.push_back(a[i]);
                b[j] = INT_MIN; // Marker taaki baar baar intersection mein
                                // count na ho
            }

    // Now, I need to remove duplicates, as asked in question

    // Step 1: Sort the vector
    sort(intersection.begin(), intersection.end());

    // Step 2: Use unique to remove duplicates
    auto last = unique(intersection.begin(), intersection.end());

    // Step 3: Erase the 'removed' elements
    intersection.erase(last, intersection.end());

    return intersection;
}

// GFG: Union of two arrays
int doUnion(vector<int> arr1, vector<int> arr2)
{

    vector<int> a = arr1;
    vector<int> b = arr2;

    // Need to erase duplicates from vector, as asked in question
    //  Step 1: Sort the vector
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Step 2: Use unique to remove duplicates
    auto lastA = unique(a.begin(), a.end());
    auto lastB = unique(b.begin(), b.end());

    // Step 3: Erase the 'removed' elements
    a.erase(lastA, a.end());
    b.erase(lastB, b.end());

    vector<int> arrayUnion;

    // n*LS chala k common element ki jagah par INT_MIN daal do 'b' array mein
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            if (a[i] == b[j])
                b[j] = INT_MIN; // Marker taaki baar baar intersection mein count na ho

    // Dono arrays ko scan kr k elements store kra lo, common element ki jagah par INT_MIN pada hoga 'b' array mein
    for (int i = 0; i < a.size(); i++)
        arrayUnion.push_back(a[i]);

    for (int i = 0; i < b.size(); i++)
        if (b[i] != INT_MIN)
            arrayUnion.push_back(b[i]);

    return arrayUnion.size();
}

// LEETCODE: 1. Two sum
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<pair<int, int>> numbers;
    for (int i = 0; i < nums.size(); i++)
    {
        numbers.push_back({nums[i], i});
    }

    sort(numbers.begin(), numbers.end());
    int i = 0;
    int j = numbers.size() - 1;

    while (i < j)
    {
        if (numbers[i].first + numbers[j].first == target)
            return {numbers[i].second, numbers[j].second};
        else if (numbers[i].first + numbers[j].first < target)
            i++;
        else
            j--;
    }

    return {-1, -1};
}

// LEETCODE: 15. 3Sum
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> triplets;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k)
        {
            if (nums[i] + nums[j] + nums[k] == 0)
            {
                triplets.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
            }
            else if (nums[i] + nums[j] + nums[k] < 0)
                j++;
            else
                k--;
        }
    }

    // Removing duplicates as asked in question
    //  Step 1: Sort the vector
    sort(triplets.begin(), triplets.end());

    // Step 2: Use unique to remove duplicates
    auto last = unique(triplets.begin(), triplets.end());

    // Step 3: Erase the 'removed' elements
    triplets.erase(last, triplets.end());

    return triplets;
}

// LEETCODE: 905. Sort array by parity
vector<int> sortArrayByParity(vector<int> &nums)
{
    // Approach: put all Even's in front of array
    int i = 0;
    // if nums[i]%2 is 0 then put it in start
    // if nums[i]%2 is 1 then put it in end
    int start = 0;             // Points to a position jisse peeche saare 0's hain
    int end = nums.size() - 1; // Points to a position jisse aagey saare Odd's hain
    // 0 0 0 0 0 1 0 1 1 1 0 1 1 1 1 1
    //         s i           e

    while (i < end)
    {
        if (nums[i] % 2 == 0)
        {
            swap(nums[i], nums[start]);

            i++;
            start++;
        }
        if (nums[i] % 2 == 1)
        {
            swap(nums[i], nums[end]);

            end--;
            // Not doing i++ bec. maybe an Odd comes in front after swap
        }
    }
    return nums;
}

// LEETCODE: 704. Binary search
int search(vector<int> &nums, int k)
{
    int s = 0;
    int e = nums.size() - 1;
    int m = s + (e - s) / 2; // Integer overflow na ho taki

    while (s <= e)
    {
        if (nums[m] == k)
            return m;

        if (k < nums[m]) //-> Go Left
            e = m - 1;
        else //-> Go Right
            s = m + 1;

        m = s + (e - s) / 2;
    }

    return -1;
}

// LEETCODE: 34. Find first and last position of element in sorted array
int findFirstOccurence(vector<int> &nums, int k)
{
    int index = -1;

    int s = 0;
    int e = nums.size() - 1;
    int m = s + (e - s) / 2;

    while (s <= e)
    {
        if (nums[m] == k)
        {
            index = m;
            // Try finding in even more left
            e = m - 1;
        }
        else if (k < nums[m]) // -> Go Left
            e = m - 1;
        else // -> Go Right
            s = m + 1;

        m = s + (e - s) / 2;
    }

    return index;
}

int findLastOccurence(vector<int> &nums, int k)
{
    int index = -1;

    int s = 0;
    int e = nums.size() - 1;
    int m = s + (e - s) / 2;

    while (s <= e)
    {
        if (nums[m] == k)
        {
            index = m;
            // Try finding in even more right
            s = m + 1;
        }
        else if (k < nums[m]) // -> Go Left
            e = m - 1;
        else // -> Go Right
            s = m + 1;

        m = s + (e - s) / 2;
    }

    return index;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int first = findFirstOccurence(nums, target);
    int last = findLastOccurence(nums, target);

    return {first, last};
}

// GFG: Number of occurrence
int findFirstOccurence(vector<int> &nums, int k)
{
    int index = -1;

    int s = 0;
    int e = nums.size() - 1;
    int m = s + (e - s) / 2;

    while (s <= e)
    {
        if (nums[m] == k)
        {
            index = m;
            // Try finding in even more left
            e = m - 1;
        }
        else if (k < nums[m]) // -> Go Left
            e = m - 1;
        else // -> Go Right
            s = m + 1;

        m = s + (e - s) / 2;
    }

    return index;
}

int findLastOccurence(vector<int> &nums, int k)
{
    int index = -1;

    int s = 0;
    int e = nums.size() - 1;
    int m = s + (e - s) / 2;

    while (s <= e)
    {
        if (nums[m] == k)
        {
            index = m;
            // Try finding in even more right
            s = m + 1;
        }
        else if (k < nums[m]) // -> Go Left
            e = m - 1;
        else // -> Go Right
            s = m + 1;

        m = s + (e - s) / 2;
    }

    return index;
}

int findTotalOccurence(vector<int> &nums, int k)
{
    int firstOccurence = findFirstOccurence(nums, k);
    int lastOccurence = findLastOccurence(nums, k);

    return (lastOccurence - firstOccurence + 1);
}

int count(int arr[], int n, int x)
{
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        nums.push_back(arr[i]);

    int ans = findTotalOccurence(nums, x);

    // Edge case
    if (findFirstOccurence(nums, x) == -1)
        return 0;

    return ans;
}

// LEETCODE: 268. Missing number
int findMissingElement(vector<int> &nums)
{
    int s = 0;
    int e = nums.size() - 1;
    int m = s + (e - s) / 2;

    int missingElement = nums.size() + 1;

    while (s <= e)
    {
        if (nums[m] == (m + 1)) // Go right
            s = m + 1;

        else if (nums[m] != (m + 1)) // Go left
        {
            missingElement = nums[m] - 1; // or missingELement = m+1;
            e = m - 1;
        }

        m = s + (e - s) / 2;
    }

    return missingElement;
}

int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
        nums[i]++;

    int ans = findMissingElement(nums) - 1;

    return ans;
}

// LEETCODE: 852. Peak index in a mountain array
int findPeakElement(vector<int> &nums)
{
    int s = 0;
    int e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    int n = nums.size();

    while (s <= e)
    {
        if ((nums[mid - 1] < nums[mid]) && (nums[mid] > nums[mid + 1])) // Found
            return mid;
        else if ((nums[mid - 1] < nums[mid]) && (nums[mid] < nums[mid + 1])) // Go right
            s = mid;
        else if ((nums[mid - 1] > nums[mid]) && (nums[mid] > nums[mid + 1])) // Go left
            e = mid;

        mid = s + (e - s) / 2;
    }

    return -1;
}

int peakIndexInMountainArray(vector<int> &nums)
{
    int ans = findPeakElement(nums);
    return ans;
}

// LEETCODE: 33. Search in rotated sorted array
int findPivotElementIndex(vector<int> &nums)
{
    // Edge case: When array isn't rotated at all
    if (nums[0] < nums[nums.size() - 1])
        return nums.size() - 1;

    // Regular cases
    int s = 0;
    int e = nums.size() - 1;
    int m = s + (e - s) / 2;

    while (s < e)
    {
        // Special pivot elements k liye check
        if (nums[m] > nums[m + 1] && m + 1 < nums.size())
            return m;
        else if (nums[m] < nums[m - 1] && m - 1 >= 0)
            return m - 1;

        if (nums[s] < nums[m]) // Go right
            s = m + 1;
        else // Go left
            e = m - 1;

        m = s + (e - s) / 2;
    }

    return s; // When only single element in array
}

int binarySearchHelper(vector<int> &nums, int s, int e, int key)
{
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (nums[mid] == key)
            return mid;           // Note: yaha return hi karwana, yu na krna ki ans=mid; kra re ho while loop mein
        else if (key < nums[mid]) //                              aur loop k baad last mein return ans; kra re ho
            e = mid - 1;
        else if (key > nums[mid])
            s = mid + 1;

        mid = s + (e - s) / 2;
    }

    return -1;
}

int search(vector<int> &nums, int key)
{
    int pivotIndex = findPivotElementIndex(nums);
    int ans = -1;
    // Part A
    if (nums[0] <= key && key <= nums[pivotIndex])
    {
        ans = binarySearchHelper(nums, 0, pivotIndex, key);
    }

    // seedha else mat likho warna "not found" wala case bhi uss hi mein aa jayega

    // Part B
    if (pivotIndex + 1 < nums.size() && nums[pivotIndex + 1] <= key && key <= nums[nums.size() - 1])
    {
        ans = binarySearchHelper(nums, pivotIndex + 1, nums.size() - 1, key);
    }

    return ans;
}

// LEETCODE: 69. Sqrt(x)
float findSqrtByBinSearch(long long int n, long long int precision)
{
    long long int s = 0;
    long long int e = n;
    long long int m = s + (e - s) / 2;

    long long int integerPart;

    // Integer part
    while (s <= e)
    {
        if (m * m == n)
            return m;

        else if (m * m < n)
        {
            s = m + 1;
            integerPart = m;
        }

        else if (m * m > n)
            e = m - 1;

        m = s + (e - s) / 2;
    }

    // Decimal part
    double floatPart = integerPart;
    double step = 0.1;
    for (int i = 0; i < precision; i++)
    {
        for (double j = floatPart; j * j <= n; j += step)
            floatPart = j;

        step /= 10;
    }

    return floatPart;
}

int mySqrt(int x)
{
    int ans = (int)findSqrtByBinSearch(x, 0);
    return ans;
}

// LEETCODE: 74. Search a 2D matrix
pair<int, int> binarySearchOnMatrix(vector<vector<int>> &matrix, int key)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Search space conversion (2D to 1D)
    int s = 0;
    int e = rows * cols - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        int i = mid / cols;
        int j = mid % cols;

        if (matrix[i][j] == key)
            return {i, j};

        if (key < matrix[i][j])
            e = mid - 1;
        else
            s = mid + 1;

        mid = s + (e - s) / 2;
    }

    return {-1, -1};
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    pair<int, int> ans = binarySearchOnMatrix(matrix, target);
    if (ans.first != -1)
        return true;
    else
        return false;
}

// LEETCODE: 540. Single element in a sorted array
int singleNonDuplicate(vector<int> &nums)
{
    // Edge case
    if (nums.size() == 1)
        return nums[0];

    // Regular cases
    int i = 0;
    int j = nums.size() - 1;

    while (i <= j)
    {
        if (i + 1 < nums.size() && j - 1 >= 0 && nums[i] == nums[i + 1] && nums[j] == nums[j - 1])
        {
            i += 2;
            j -= 2;
        }
        else
        {
            if (i + 1 < nums.size() && nums[i] != nums[i + 1])
                return nums[i];
            else if (j >= 0 && nums[j] != nums[j - 1])
                return nums[j];
        }
    }
    return -1;
}

// LEETCODE: 29. Divide two integers
double findDivisionByBinSearch(long long int dividend, long long int divisor, int precision)
{
    long long int s = 0;
    long long int e = abs(dividend);
    long long int m = s + (e - s) / 2;

    // Integer part of Quotient
    long long int integerQuotient;

    while (s <= e)
    {
        // Perfect division
        if (abs(divisor * m) == abs(dividend))
            return m;

        // Not perfect division
        if (abs(divisor * m) < abs(dividend))
        {
            integerQuotient = m;
            s = m + 1;
        }
        else
            e = m - 1;

        m = s + (e - s) / 2;
    }

    return integerQuotient;
}

int divide(int dividend, int divisor)
{
    // Edge cases
    if (dividend == INT_MIN && divisor == 1)
        return INT_MIN;
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    if (dividend == INT_MAX && divisor == 1)
        return INT_MAX;
    if (dividend == INT_MAX && divisor == -1)
        return -INT_MAX;

    // Regular cases
    int ans = findDivisionByBinSearch(abs(dividend), abs(divisor), 0);

    // Sign k hisaab se answer bhejna hai
    // 1. Signs ko store karo
    pair<char, char> sign;
    if (dividend < 0)
        sign.first = '-';
    else
        sign.first = '+';

    if (divisor < 0)
        sign.second = '-';
    else
        sign.second = '+';

    // 2. Signs k hisaab se answer dedo
    if ((sign.first == '+' && sign.second == '+') || (sign.first == '-' && sign.second == '-'))
        return abs(ans);
    else
        return -(abs(ans));
}


