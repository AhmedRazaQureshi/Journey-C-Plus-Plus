// CONCEPT: Build-Tree & Level-Order-Traversal
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int _data)
    {
        data = _data;
        left = NULL;
        right = NULL;
    }
};

// 1. Build-Tree
Node *buildTree() // From Pre-Order-Traversal input
{
    int data;
    cout << "(Node's data) ";
    cin >> data;
    // BC
    if (data == -1)
        return NULL;

    Node *currNode = new Node(data);

    cout << "Left child of " << data;
    currNode->left = buildTree();

    cout << "Right child of " << data;
    currNode->right = buildTree();

    return currNode;
}

// 2. Level-Order-Traversal
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;

    // 1.Insert root & NULL in q
    q.push(root);
    q.push(NULL);

    // 2.Pop q.front() & push it's children
    while (!q.empty())
    {
        Node *currNode = q.front();
        q.pop();

        // Case-1: q.front() is not NULL
        if (currNode != NULL)
        {
            cout << currNode->data << ", ";

            if (currNode->left != NULL)
                q.push(currNode->left);
            if (currNode->right != NULL)
                q.push(currNode->right);
        }
        // Case-2: q.front() is NULL
        else
        {
            cout << endl;

            if (!q.empty())
                q.push(NULL);
        }
    }
}

// 3. Pre-In-Post Order Traversal (Recursive)
void preOrderTraversal(Node *root)
{
    // BC
    if (root == NULL)
        return;

    // NLR
    cout << root->data << ",";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root)
{
    // BC
    if (root == NULL)
        return;

    // LNR
    inOrderTraversal(root->left);
    cout << root->data << ",";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    // BC
    if (root == NULL)
        return;

    // LRN
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << ",";
}

// 4. Pre-In-Post Order Traversal (Iterative)
void preOrderIterative(Node *root) //[N](L)(R)
{
    if (root == NULL)
        return;

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *currNode = st.top();
        st.pop();

        cout << currNode->data << ",";

        if (currNode->right)
            st.push(currNode->right);
        if (currNode->left)
            st.push(currNode->left);
    }
}

void inOrderIterative(Node *root) //(L)[N](R)
{
    if (root == NULL)
        return;

    stack<Node *> st;
    Node *currNode = root;

    while (currNode != NULL || !st.empty())
    {
        while (currNode != NULL)
        {
            st.push(currNode);
            currNode = currNode->left;
        }

        currNode = st.top();
        st.pop();
        cout << currNode->data << ",";
        currNode = currNode->right;
    }
}

void postOrderIterative(Node *root) //(L)(R)[N]
{
    if (root == NULL)
        return;

    stack<Node *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        Node *currNode = st1.top();
        st1.pop();
        st2.push(currNode);

        if (currNode->left)
            st1.push(currNode->left);
        if (currNode->right)
            st1.push(currNode->right);
    }

    while (!st2.empty())
    {
        Node *currNode = st2.top();
        st2.pop();
        cout << currNode->data << ",";
    }
}

// 5. Build-Tree from Level-Order-Traversal
Node *buildTreeFromLOT(vector<int> lot)
{
    if (lot.size() == 0)
        return NULL;

    Node *root = new Node(lot[0]);

    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (i < lot.size())
    {
        Node *currNode = q.front();
        q.pop();

        // Assign the left child
        if (i < lot.size() && lot[i] != -1)
        {
            currNode->left = new Node(lot[i]);
            q.push(currNode->left);
        }
        i++;

        // Assign the right child
        if (i < lot.size() && lot[i] != -1)
        {
            currNode->right = new Node(lot[i]);
            q.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{
    // 1. Build-Tree
    Node *root = NULL;
    root = buildTree();  //20,30,50,-1,60,-1,-1,40,-1,-1,100,-1,-1

    // 2. Level-Order-Traversal
    cout << "Level-Order Traversal: " << endl;
    levelOrderTraversal(root);

    // 3. Pre-In-Post Order Traversal (Recursive)
    cout << "Pre-Order Traversal: ";
    preOrderTraversal(root);
    cout << endl;
    cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    cout << endl;
    cout << "Post-Order Traversal: ";
    postOrderTraversal(root);
    cout << endl;
    cout << "________________________________" << endl;

    // 4. Pre-In-Post Order Traversal (Iterative)
    cout << "Pre-Order Traversal: ";
    preOrderIterative(root);
    cout << endl;
    cout << "In-Order Traversal: ";
    inOrderIterative(root);
    cout << endl;
    cout << "Post-Order Traversal: ";
    postOrderIterative(root);

    // 5. Build-Tree from Level-Order-Traversal
    vector<int> lot = {20, 30, 100, 50, 40, -1, -1, -1, 60, -1, -1, -1, -1};
    Node *root2 = buildTreeFromLOT(lot);
    levelOrderTraversal(root2);

    return 0;
}