#include <bits/stdc++.h>
using namespace std;

//For Ques#01
class TreeNode
{
    public: 

    TreeNode* left;
    TreeNode* right;
    int data;

    TreeNode(int _data)
    {
        left = NULL;
        right = NULL;
        data = _data;
    }
};

//For Ques#02
class ListNode
{
    public:
    ListNode* prev;
    ListNode* next;
    int data;

    ListNode(int _data)
    {
        prev = NULL;
        next = NULL;
        data = _data;
    }
};


// Ques#01: Construct BST from Inorder traversal
TreeNode* buildBST_from_iot(vector<int>& iot, int s, int e)
{
    if(s>e)
        return NULL;

    int m = s+(e-s)/2;

    TreeNode* newNode = new TreeNode(iot[m]);
    newNode->left = buildBST_from_iot(iot, s, m-1);
    newNode->right = buildBST_from_iot(iot, m+1, e);

    return newNode;
}

void level_order_trav(TreeNode* root)
{
    if(root == NULL)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode* currNode = q.front();
        q.pop();

        if(currNode)
            cout<<currNode->data<<",";

        if(currNode->left)
            q.push(currNode->left);
        if(currNode->right)
            q.push(currNode->right);
    }

}

//Ques#02: Convert sorted DLL to BST


int main()
{
    // Ques#01: Construct BST from Inorder traversal
    vector<int> iot = {1,2,3,4,5,6,7,8,9};
    TreeNode* root = buildBST_from_iot(iot, 0, iot.size()-1);
    level_order_trav(root);

    // Ques#02: Convert sorted DLL to BST
    




    return 0;
}