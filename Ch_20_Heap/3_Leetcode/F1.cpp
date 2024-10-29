// GFG: Kth Smallest
int kthSmallest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto i : arr)
        pq.push(i);

    int temp;
    while (k)
    {
        temp = pq.top();
        pq.pop();
        k--;
    }

    return temp;
}

// GFG: Merge two binary Max heaps
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    priority_queue<int> pq;
    for (auto i : a)
        pq.push(i);
    for (auto i : b)
        pq.push(i);
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

// GFG: Is Binary Tree Heap
bool checkFor_ACBT_CBT(struct Node *root) // Level-Order-Traversal
{
    if (root == NULL)
        return true;

    queue<struct Node *> q;
    q.push(root);
    bool nullSeen = false;

    while (!q.empty())
    {
        struct Node *currNode = q.front();
        q.pop();

        if (currNode == NULL)
            nullSeen = true; // Mark that a NULL node was encountered
        else
        {
            if (nullSeen)
                return false; // If a non-null node is found after a null, it's not CBT

            // Push children regardless of being NULL, which allows us to detect missing nodes
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }

    return true;
}

pair<bool, int> solve(struct Node *root)
{
    if (root == NULL)
        return {true, INT_MIN};

    if (!root->left && !root->right)
        return {true, root->data};

    pair<bool, int> leftAns = solve(root->left);
    pair<bool, int> rightAns = solve(root->right);

    pair<bool, int> currAns;
    if (leftAns.first && rightAns.first && (root->data > leftAns.second && root->data > rightAns.second))
    {
        currAns.first = true;
        currAns.second = root->data;
    }
    else
    {
        currAns.first = false;
        currAns.second = max(leftAns.second, rightAns.second);
    }

    return currAns;
}

bool isHeap(struct Node *tree)
{
    // 1. Check if tree is ACBT or CBT
    bool isACBT_or_CBT = checkFor_ACBT_CBT(tree);
    if (!isACBT_or_CBT)
        return false;
    // 2. Check Max-Heap Property
    pair<bool, int> ans = solve(tree);
    return ans.first;
}

// GFG: BST to max heap
void populateIot(Node *root, vector<int> &iot)
{
    if (root == NULL)
        return;

    populateIot(root->left, iot);
    iot.push_back(root->data);
    populateIot(root->right, iot);
}

void convert(Node *root, vector<int> &iot, int &i)
{
    if (root == NULL)
        return;

    convert(root->left, iot, i);
    convert(root->right, iot, i);
    root->data = iot[i];
    i++;
}

void convertToMaxHeapUtil(Node *root)
{
    vector<int> iot;
    populateIot(root, iot);
    int i = 0;
    convert(root, iot, i);
}

// LEETCODE: 958. Check Completeness of a Binary Tree
bool solve(TreeNode *root)
{
    if (root == NULL)
        return true;

    queue<TreeNode *> q;
    q.push(root);
    bool nullSeen = false;

    while (!q.empty())
    {
        TreeNode *currNode = q.front();
        q.pop();

        if (currNode == NULL)
            nullSeen = true;
        else
        {
            if (nullSeen)
                return false;
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }

    return true;
}

bool isCompleteTree(TreeNode *root)
{
    bool ans = solve(root);
    return ans;
}

// GFG: Merge k Sorted Arrays
class info
{
public:
    int value;
    int row;
    int col;

    info(int v, int r, int c)
    {
        value = v;
        row = r;
        col = c;
    }
};

class cmp
{
public:
    bool operator()(info *a, info *b)
    {
        return a->value > b->value;
    }
};

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        int m = k;
        int n = arr[0].size();

        // 1. Push 1st element of each array in heap
        priority_queue<info *, vector<info *>, cmp> minHeap;

        for (int i = 0; i < k; i++)
        {
            info *temp = new info(arr[i][0], i, 0);
            minHeap.push(temp);
        }

        // 2. Pop from minHeap, push it in result vector, push it's next element from arr into minHeap
        vector<int> ans;
        while (!minHeap.empty())
        {
            info *currElement = minHeap.top();
            minHeap.pop();

            ans.push_back(currElement->value);

            // Isse next element ko push krana hai, agar hai tohi
            if (currElement->col < n - 1)
            {
                info *newElement = new info(arr[currElement->row][currElement->col + 1], currElement->row, currElement->col + 1);
                minHeap.push(newElement);
            }
        }

        return ans;
    }
};

// LEETCODE: 23. Merge k Sorted Lists
class cmp
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();
        if (k == 0)
            return NULL;

        // 1. Push 1st element of all LLs into minHeap
        priority_queue<ListNode *, vector<ListNode *>, cmp> minHeap;

        for (int i = 0; i < k; i++)
        {
            if (lists[i] != NULL) // Kuch khalli LLs bhi hain kyuki
                minHeap.push(lists[i]);
        }

        // 2. Pop from minHeap & add it to ans, also push it's next element from LL to minHeap
        ListNode *head = NULL; // ans Head
        ListNode *tail = NULL; // ans Tail

        while (!minHeap.empty())
        {
            ListNode *currNode = minHeap.top();
            minHeap.pop();

            // Insertion as first node
            if (tail == NULL)
            {
                head = currNode;
                tail = currNode;
            }
            // Regular insertion
            else
            {
                tail->next = currNode;
                tail = currNode;
            }

            if (currNode->next)
                minHeap.push(currNode->next);
        }

        return head;
    }
};

// LEETCODE: 632. Smallest Range Covering Elements from K Lists
class info
{
public:
    int data;
    int row;
    int col;

    info(int d, int r, int c)
    {
        data = d;
        row = r;
        col = c;
    }
};

class cmp
{
public:
    bool operator()(info *a, info *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int k = nums.size();
        int mini = INT_MAX; // Arrow -> ko aage badhane mein madad karega, (range nikaalne k liye)
        int maxi = INT_MIN; // i.e., it stores current step par minimum element kaun hai, aur maximum element kaun hai

        // 1. Insert 1st element of LLs into minHeap
        priority_queue<info *, vector<info *>, cmp> minHeap;

        for (int i = 0; i < k; i++)
        {
            info *newElement = new info(nums[i][0], i, 0);
            minHeap.push(newElement);

            mini = min(mini, newElement->data);
            maxi = max(maxi, newElement->data);
        }

        // 2. Pop from minHeap & push it's next element from nums (if exists)
        int ansMini = mini; // Taaki purani range ko nayi range se compare kara pau
        int ansMaxi = maxi;

        while (!minHeap.empty())
        {
            // Pop from minHeap
            info *temp = minHeap.top();
            minHeap.pop();

            //(a)Mini update
            mini = temp->data; // temp minHeap ka min.m element hai, isliye min.m hi hai

            if ((maxi - mini) < (ansMaxi - ansMini))
            {
                ansMaxi = maxi;
                ansMini = mini;
            }

            // Push it's next element(if there)
            if (temp->col < nums[temp->row].size() - 1)
            {
                info *newElement = new info(nums[temp->row][temp->col + 1], temp->row, temp->col + 1);
                minHeap.push(newElement);

                //(b)Maxi update
                maxi = max(maxi, newElement->data);
            }
            else
                break; // aage list hi nhi bachi
        }

        // 3. Return range
        return {ansMini, ansMaxi};
    }
};

// LEETCODE: 1962. Remove Stones to Minimize the Total
int minStoneSum(vector<int> &piles, int k)
{
    priority_queue<int> maxHeap;

    for (auto i : piles)
        maxHeap.push(i);

    while (k--)
    {
        int temp = maxHeap.top();
        maxHeap.pop();

        temp = temp - temp / 2;

        maxHeap.push(temp);
    }

    int ans = 0;
    while (!maxHeap.empty())
    {
        ans += maxHeap.top();
        maxHeap.pop();
    }
    return ans;
}

// LEETCODE: 767. Reorganize String
class info
{
public:
    char data;
    int freq;

    info(char d, int f)
    {
        data = d;
        freq = f;
    }
};

class cmp
{
public:
    bool operator()(info *a, info *b)
    {
        return a->freq < b->freq;
    }
};

class Solution
{
public:
    string reorganizeString(string s)
    {
        // 1. Create MaxHeap of <char,freq>
        int frq[26] = {0};
        for (int i = 0; i < s.length(); i++)
            frq[s[i] - 'a']++;

        priority_queue<info *, vector<info *>, cmp> maxHeap;
        for (int i = 0; i < 26; i++)
        {
            if (frq[i] != 0)
            {
                info *newElement = new info('a' + i, frq[i]);
                maxHeap.push(newElement);
            }
        }

        // 2. Remove top two elements and consume them
        string ans = "";
        while (maxHeap.size() >= 2)
        {
            info *e_1 = maxHeap.top();
            maxHeap.pop();
            info *e_2 = maxHeap.top();
            maxHeap.pop();

            ans += e_1->data;
            ans += e_2->data;

            e_1->freq--;
            e_2->freq--;

            if (e_1->freq > 0)
                maxHeap.push(e_1);
            if (e_2->freq > 0)
                maxHeap.push(e_2);
        }

        // 3. Check if MaxHeap mein 1 last element bacha reh gya kya
        if (maxHeap.size() == 1)
        {
            info *temp = maxHeap.top();
            maxHeap.pop();

            if (temp->freq == 1)
                ans += temp->data;
            else
                return "";
        }

        return ans;
    }
};

// LEETCODE: 1405. Longest Happy String
class info
{
public:
    char data;
    int count;

    info(char d, int c)
    {
        data = d;
        count = c;
    }
};

class cmp
{
public:
    bool operator()(info *a, info *b)
    {
        return a->count < b->count;
    }
};

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        // 1. MaxHeap creation
        priority_queue<info *, vector<info *>, cmp> maxHeap;

        if (a > 0)
            maxHeap.push(new info('a', a));
        if (b > 0)
            maxHeap.push(new info('b', b));
        if (c > 0)
            maxHeap.push(new info('c', c));

        // 2. Pop top-2 elements & consume
        string ans = "";
        while (maxHeap.size() >= 2)
        {
            info *e_1 = maxHeap.top();
            maxHeap.pop();
            info *e_2 = maxHeap.top();
            maxHeap.pop();

            // Consuming 1st element
            if (e_1->count >= 2)
            {
                ans += e_1->data;
                ans += e_1->data;

                e_1->count -= 2;
            }
            else
            {
                ans += e_1->data;

                e_1->count--;
            }

            // Consuming 2nd element
            if (e_2->count >= 2 && e_2->count > e_1->count)
            {
                ans += e_2->data;
                ans += e_2->data;

                e_2->count -= 2;
            }
            else
            {
                ans += e_2->data;

                e_2->count--;
            }

            if (e_1->count > 0)
                maxHeap.push(e_1);
            if (e_2->count > 0)
                maxHeap.push(e_2);
        }

        // 3. Check if maxHeap mein 1 element pada gya kya
        if (maxHeap.size() == 1)
        {
            info *e = maxHeap.top();
            maxHeap.pop();

            if (e->count >= 2)
            {
                ans += e->data;
                ans += e->data;
            }
            else
                ans += e->data;
        }

        return ans;
    }
};

// LEETCODE: 295. Find Median from Data Stream
class MedianFinder 
{
    public:
    double median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() 
    {
         
    }

    int signum(int m1, int m2)
    {
        if(m1 == m2)  return 0;
        if(m1 > m2)   return 1;
        if(m1 < m2)   return -1;

        return -2;
    }

    void addNum(int currElement) 
    {
        //1. There can be 3 states of MaxHeap--Median--MinHeap
        int m1 = maxHeap.size();
        int m2 = minHeap.size();
        int currCase = signum(m1, m2);
        
        //2. Based on case, you need to do i) Accomodate currElement into one of the Heaps, ii) Update median
        switch(currCase)
        {
            case 0: //MaxHeap == MinHeap  => median was avg(MaxHeap.top(),MinHeap.top()); [left+right se nikla tha]
                    if(currElement > median) // => Push in right (minHeap)
                    {
                        minHeap.push(currElement);
                        median = minHeap.top();
                    }
                    else // => Push in left (maxHeap)
                    {
                        maxHeap.push(currElement);
                        median = maxHeap.top();
                    }
                    break;

            case 1: //MaxHeap > MinHeap  => median was MaxHeap.top() [left mein pda tha]
                    if(currElement > median) // => Push in right (minHeap)
                    {
                        minHeap.push(currElement);
                        median = (maxHeap.top()+minHeap.top()) / 2.0;
                    }
                    else // => Push in left (maxHeap)
                    {
                        int temp = maxHeap.top();
                        maxHeap.pop();
                        maxHeap.push(currElement);

                        minHeap.push(temp);

                        median = (maxHeap.top()+minHeap.top()) / 2.0;
                    }
                    break;

            case -1: //MaxHeap < MinHeap => median was MinHeap.top() [right mein pda tha]
                    if(currElement > median) // => push in right (minHeap)
                    {
                        int temp = minHeap.top();
                        minHeap.pop();
                        minHeap.push(currElement);

                        maxHeap.push(temp);

                        median = (maxHeap.top()+minHeap.top()) / 2.0;
                    }
                    else // => push in left (maxHeap)
                    {
                        maxHeap.push(currElement);
                        median = (maxHeap.top()+minHeap.top()) / 2.0;
                    }
                    break;
        }
    }

    double findMedian() 
    {
        return median;
    }
};