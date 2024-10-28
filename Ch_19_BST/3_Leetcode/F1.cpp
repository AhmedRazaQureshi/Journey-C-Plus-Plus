// LEETCODE: 98. Validate BST
bool solve(TreeNode *root, long long int lb, long long int ub)
{
    if (root == NULL)
        return true;

    if (lb < root->val && root->val < ub)
        return solve(root->left, lb, root->val) && solve(root->right, root->val, ub);

    else
        return false;
}

bool isValidBST(TreeNode *root)
{
    long long int lb = -pow(2, 32);
    long long int ub = +pow(2, 32);

    return solve(root, lb, ub);
}

// LEETCODE: 235. Lowest Common Ancestor of a Binary Search Tree
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;

    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    else if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    else
        return root;
}

// LEETCODE: 230. Kth Smallest Element in a BST
int kthSmallest(TreeNode *root, int &k)
{
    if (root == NULL)
        return -1;

    int leftAns = kthSmallest(root->left, k);
    k--;
    if (k == 0)
        return root->val;
    int rightAns = kthSmallest(root->right, k);

    if (leftAns != -1)
        return leftAns;
    else
        return rightAns;
}

// LEETCODE: 1382. Balance a Binary Search Tree
void inorderTraversal(TreeNode *root, vector<int> &iot)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left, iot);
    iot.push_back(root->val);
    inorderTraversal(root->right, iot);
}

TreeNode *buildBST_from_iot(vector<int> &iot, int s, int e)
{
    if (s > e)
        return NULL;

    int m = s + (e - s) / 2;

    TreeNode *newNode = new TreeNode(iot[m]);
    newNode->left = buildBST_from_iot(iot, s, m - 1);
    newNode->right = buildBST_from_iot(iot, m + 1, e);

    return newNode;
}

TreeNode *balanceBST(TreeNode *root)
{
    // 1. Do Inorder-Traversal
    vector<int> iot;
    inorderTraversal(root, iot);

    // 2. Build BST from iot
    TreeNode *newRoot = buildBST_from_iot(iot, 0, iot.size() - 1);

    return newRoot;
}

// LEETCODE: 653. Two Sum IV - Input is a BST
void inorderTraversal(TreeNode *root, vector<int> &iot)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left, iot);
    iot.push_back(root->val);
    inorderTraversal(root->right, iot);
}

bool findTarget(TreeNode *root, int k)
{
    // 1. Store iot
    vector<int> iot;
    inorderTraversal(root, iot);

    // 2. Greedy 2 ptr on iot
    int s = 0;
    int e = iot.size() - 1;
    while (s < e)
    {
        if ((iot[s] + iot[e]) == k)
            return true;

        else if ((iot[s] + iot[e]) > k)
            e--;
        else if ((iot[s] + iot[e]) < k)
            s++;
    }

    return false;
}

// CODING-NINJAS: BST to sorted DLL
void solve(TreeNode<int> *root, TreeNode<int> *&head, TreeNode<int> *&tail)
{
    if (root == NULL)
        return;

    solve(root->left, head, tail);

    if (tail == NULL)
    {
        head = root;
        tail = root;
    }
    else
    {
        tail->right = root;
        root->left = tail;
        tail = root;
    }

    solve(root->right, head, tail);
}

TreeNode<int> *bstToSortedDLL(TreeNode<int> *root)
{
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;
    solve(root, head, tail);

    return head;
}

// GFG: Largest BST
class NodeData
{
public:
    int size;
    int maxVal;
    int minVal;
    bool validBST;

    NodeData(int _size, int _maxVal, int _minVal, bool _validBST)
    {
        size = _size;
        maxVal = _maxVal;
        minVal = _minVal;
        validBST = _validBST;
    }

    NodeData() {}
};

class Solution
{
public:
    NodeData *findLargestBST(Node *root, int &ans)
    {
        if (root == NULL)
        {
            NodeData *temp = new NodeData(0, INT_MIN, INT_MAX, true);
            return temp;
        }

        // LRN
        NodeData *leftAns = findLargestBST(root->left, ans);
        NodeData *rightAns = findLargestBST(root->right, ans);

        NodeData *currNode = new NodeData();

        currNode->size = leftAns->size + rightAns->size + 1;
        currNode->maxVal = max(root->data, rightAns->maxVal);
        currNode->minVal = min(root->data, leftAns->minVal);

        if (leftAns->validBST && rightAns->validBST && leftAns->maxVal < root->data && root->data < rightAns->minVal)
        {
            currNode->validBST = true;
            ans = max(ans, currNode->size);
        }
        else
            currNode->validBST = false;

        return currNode;
    }

    int largestBst(Node *root)
    {
        int ans = 0;
        findLargestBST(root, ans);
        return ans;
    }
