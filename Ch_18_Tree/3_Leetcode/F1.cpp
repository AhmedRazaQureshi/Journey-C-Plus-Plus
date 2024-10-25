// LEETCODE: 104. Maximum depth of binary tree
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + max(left, right);
}

// LEETCODE: 543. Diameter of binary tree
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode *root)
{
    // BC
    if (root == NULL)
        return 0;

    // Excluding myself, taking left-part only
    int op1 = diameterOfBinaryTree(root->left);
    // Excluding myself, taking right-part only
    int op2 = diameterOfBinaryTree(root->right);
    // Including myself
    int op3 = maxDepth(root->left) + maxDepth(root->right);

    return max(op1, max(op2, op3));
}

// LEETCODE: 100. Same Tree
bool isSameTree(TreeNode *t1, TreeNode *t2)
{
    if (t1 == NULL && t2 == NULL)
        return true;

    if ((t1 && !t2) || (!t1 && t2))
        return false;

    if (t1->val != t2->val)
        return false;

    return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
}

// LEETCODE: 110. Balanced binary tree
int findHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int left = findHeight(root->left);
    int right = findHeight(root->right);

    return 1 + max(left, right);
}

bool isBalanced(TreeNode *root)
{
    if (root == NULL)
        return true;

    // 1. Am I balanced
    int lh = findHeight(root->left);
    int rh = findHeight(root->right);

    bool myAns = (abs(lh - rh) <= 1);

    // 2. Is left-subtree balanced
    bool leftAns = isBalanced(root->left);
    // 3. Is right-subtree balanced
    bool rightAns = isBalanced(root->right);

    return myAns && leftAns && rightAns;
}

// GFG: Sum tree
int findSum(Node *root)
{
    if (root == NULL)
        return 0;

    int leftSum = findSum(root->left);
    int rightSum = findSum(root->right);

    return root->data + leftSum + rightSum;
}

bool isSumTree(Node *root)
{
    if (root == NULL || !root->left && !root->right)
        return true;

    int leftSubtreeSum = findSum(root->left);
    int rightSubtreeSum = findSum(root->right);

    if ((leftSubtreeSum + rightSubtreeSum) == root->data)
        return isSumTree(root->left) && isSumTree(root->right);
    else
        return false;
}

// GFG: Transform to sum tree
int solve(Node *root)
{
    if (root == NULL)
        return 0;

    int oldData = root->data;

    int leftSum = solve(root->left);
    int rightSum = solve(root->right);

    root->data = leftSum + rightSum;

    return oldData + root->data;
}

void toSumTree(Node *node)
{
    solve(node);
}

// LEETCODE: 236. Lowest Common Ancestor of a Binary Tree
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;

    // Case: This node is 'p' (or) this node is 'q'
    if (root->val == p->val || root->val == q->val)
        return root;

    // Case: This node is not 'p' and not 'q'
    // so, search p & q in left & right subtrees
    TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);

    // Jiss branch se null nahi aa rha, uss branch ko lelo
    if (leftAns && !rightAns)
        return leftAns;
    else if (!leftAns && rightAns)
        return rightAns;
    else if (!leftAns && !rightAns)
        return NULL;
    else
        return root; // mtlb yahi voh common ancestor hai
}

// GFG: Kth Ancestor in a Tree
// M-1:
bool solve(Node *root, int &k, int p, int &ans)
{
    if (root == NULL)
        return false;

    // Case: p is found
    if (root->data == p)
        return true;

    // Case: p is not found => search in left & right
    bool leftAns = solve(root->left, k, p, ans);
    bool rightAns = solve(root->right, k, p, ans);

    // Backtrack kr rhe honge abb
    if (leftAns || rightAns)
        k--;

    if (k == 0)
    {
        ans = root->data; // Yahi vo k'th ancestor hai
        k = -1;
    }

    return leftAns || rightAns;
}

int kthAncestor(Node *root, int k, int node)
{
    int ans = -1; // That k'th ancestor's data

    solve(root, k, node, ans);

    return ans;
}

// M-2:
int kthAncestor(Node *root, int k, int node)
{
    if (root == NULL)
        return -1;

    static vector<int> ancestors;
    static int ans = -1;

    // Case: Found the node
    if (root->data == node)
    {
        if (ancestors.size() >= k)
            ans = ancestors[ancestors.size() - k];
        else
            ans = -1; // not enough ancestors
        return ans;
    }

    // Case: Traverse the tree
    ancestors.push_back(root->data);

    kthAncestor(root->left, k, node);
    kthAncestor(root->right, k, node);

    ancestors.pop_back();

    return ans;
}

// LEETCODE: 113. Path Sum II
void solve(TreeNode *root, int targetSum, int &currSum, vector<int> &currPath, vector<vector<int>> &ans)
{
    if (root == NULL)
        return;

    // Include current path
    currSum += root->val;
    currPath.push_back(root->val);

    // Check if arrived to leaf
    if (!root->left && !root->right && targetSum == currSum)
        ans.push_back(currPath);

    solve(root->left, targetSum, currSum, currPath, ans);
    solve(root->right, targetSum, currSum, currPath, ans);

    currSum -= root->val;
    currPath.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<int> currPath;
    vector<vector<int>> ans;
    int currSum = 0;
    solve(root, targetSum, currSum, currPath, ans);

    return ans;
}

// GFG: Construct Tree from Inorder & Preorder
Node *solve(Node *root, int in[], int pre[], int n, int &preIndex, int inStart, int inEnd)
{
    // BC
    if (preIndex >= n || inStart > inEnd)
        return NULL;

    // 1. Create node
    root = new Node(pre[preIndex]);
    preIndex++;

    // 2. Find position of this created node in In-Order
    int pos = -1;
    for (int i = inStart; i <= inEnd; i++)
        if (in[i] == root->data)
        {
            pos = i;
            break;
        }

    // 3. Build left & right subtrees
    root->left = solve(root->left, in, pre, n, preIndex, inStart, pos - 1);
    root->right = solve(root->right, in, pre, n, preIndex, pos + 1, inEnd);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    int preIndex = 0;
    Node *root = solve(NULL, in, pre, n, preIndex, 0, n - 1);

    return root;
}

// GFG: Binary Tree from Inorder and Postorder
Node *solve(Node *root, int in[], int post[], int n, int &postIndex, int inStart, int inEnd)
{
    // BC
    if (postIndex < 0 || inStart > inEnd)
        return NULL;

    // 1. Create node
    root = new Node(post[postIndex--]);

    // 2. Find position of this new node in In-Order
    int pos = -1;
    for (int i = inStart; i <= inEnd; i++)
        if (in[i] == root->data)
        {
            pos = i;
            break;
        }

    // 3. Build left and right subtree
    root->right = solve(root->right, in, post, n, postIndex, pos + 1, inEnd);
    root->left = solve(root->left, in, post, n, postIndex, inStart, pos - 1);

    return root;
}

Node *buildTree(int n, int in[], int post[])
{
    int postIndex = n - 1;
    Node *root = solve(NULL, in, post, n, postIndex, 0, n - 1);

    return root;
}

// LEETCODE: 889. Construct Binary Tree from Preorder and Postorder Traversal
TreeNode *solve(TreeNode *root, vector<int> &preorder, vector<int> &postorder, int &preIndex, int postStart, int postEnd)
{
    // Base Case
    if (preIndex >= preorder.size() || postStart > postEnd)
        return NULL;

    // 1. Create node
    root = new TreeNode(preorder[preIndex++]);

    // If there's only one node in the current subtree, return the node
    if (postStart == postEnd)
        return root;

    // 2. Find the next element of preorder (which is the left child) in postorder
    int pos = -1;
    for (int i = postStart; i <= postEnd; i++)
    {
        if (postorder[i] == preorder[preIndex])
        {
            pos = i;
            break;
        }
    }

    // 3. Build left and right subtrees
    if (pos != -1)
    {
        root->left = solve(root->left, preorder, postorder, preIndex, postStart, pos);
        root->right = solve(root->right, preorder, postorder, preIndex, pos + 1, postEnd - 1);
    }

    return root;
}

TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    int preIndex = 0;
    return solve(NULL, preorder, postorder, preIndex, 0, postorder.size() - 1);
}

// GFG: Top view of binary tree
vector<int> topView(Node *root)
{
    if (root == NULL)
        return {};

    map<int, int> mp;           // Node->data  ----- Hd
    queue<pair<Node *, int>> q; //{Node ---- Hd}

    q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *currNode = temp.first;
        int currHd = temp.second;

        if (mp.find(currHd) == mp.end())
            mp[currHd] = currNode->data;

        if (currNode->left)
            q.push({currNode->left, currHd - 1});
        if (currNode->right)
            q.push({currNode->right, currHd + 1});
    }

    vector<int> ans;

    for (auto i : mp)
        ans.push_back(i.second);

    return ans;
}

// GFG: Bottom view of binary tree
vector<int> bottomView(Node *root)
{
    if (root == NULL)
        return {};

    map<int, int> mp;           // hd --- data
    queue<pair<Node *, int>> q; // Node --- hd
    q.push({root, 0});

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *currNode = temp.first;
        int currHd = temp.second;

        mp[currHd] = currNode->data;

        if (currNode->left)
            q.push({currNode->left, currHd - 1});
        if (currNode->right)
            q.push({currNode->right, currHd + 1});
    }

    vector<int> ans;

    for (auto i : mp)
        ans.push_back(i.second);

    return ans;
}

// GFG: Left view of binary tree
// M-1: By Level-order-traversal
vector<int> leftView(Node *root)
{
    if (root == NULL)
        return {};

    map<int, int> mp;           // vd(vertical distance or level #) --- data
    queue<pair<Node *, int>> q; // Node --- vd
    q.push({root, 0});

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *currNode = temp.first;
        int currVd = temp.second;

        if (mp.find(currVd) == mp.end())
            mp[currVd] = currNode->data;

        if (currNode->left)
            q.push({currNode->left, currVd + 1});
        if (currNode->right)
            q.push({currNode->right, currVd + 1});
    }

    vector<int> ans;
    for (auto i : mp)
        ans.push_back(i.second);

    return ans;
}
// M-2: Recursion
void solve(Node *root, int currLevel, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (ans.size() == currLevel)
        ans.push_back(root->data);

    solve(root->left, currLevel + 1, ans);
    solve(root->right, currLevel + 1, ans);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    solve(root, 0, ans);
    return ans;
}

// LEETCODE: 199. Binary Tree Right Side View
void solve(TreeNode *root, int currLevel, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (ans.size() == (currLevel))
        ans.push_back(root->val);

    solve(root->right, currLevel + 1, ans);
    solve(root->left, currLevel + 1, ans);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    solve(root, 0, ans);
    return ans;
}

// GFG: Tree Boundary Traversal
void leftBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL || (!root->left && !root->right))
        return;

    ans.push_back(root->data);
    if (root->left)
        leftBoundary(root->left, ans);
    else if (root->right)
        leftBoundary(root->right, ans);
}

void rightBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL || (!root->left && !root->right))
        return;

    if (root->right)
        rightBoundary(root->right, ans);
    else if (root->left)
        rightBoundary(root->left, ans);

    ans.push_back(root->data);
}

void leafBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (!root->left && !root->right)
    {
        ans.push_back(root->data);
        return;
    }

    leafBoundary(root->left, ans);
    leafBoundary(root->right, ans);
}

vector<int> boundary(Node *root)
{
    if (root == NULL)
        return {};

    if (!root->left && !root->right)
        return {root->data};

    vector<int> ans;
    ans.push_back(root->data);

    leftBoundary(root->left, ans);
    leafBoundary(root, ans);
    rightBoundary(root->right, ans);

    return ans;
}

