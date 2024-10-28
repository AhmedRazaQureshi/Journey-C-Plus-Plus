// Concept: Structure, Insertion, Level-order-traversal
#include <bits/stdc++.h>
using namespace std;

//1. Structure
class Node
{
    public:
    Node* left;
    Node* right;
    int data;

    Node(int _data)
    {
        data = _data;
        left = NULL;
        right = NULL;
    }
};

//2. Insertion
Node* insertToBST(Node* root, int element)
{
    if(root == NULL)
    {
        root = new Node(element);
        return root;
    }

    if(root->data > element)
    {
        root->left = insertToBST(root->left, element);
    }
    else 
    {
        root->right = insertToBST(root->right, element);
    }

    return root;
}

//3. Level-order-traversal (same as Binary Tree)
vector<int> levelOrderTraversal(Node* root)
{
    if(root == NULL)
        return {};

    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp != NULL)
        {
            ans.push_back(temp->data);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        else
        {
            if(!q.empty())
                q.push(NULL);
        }
    }

    return ans;
}

//4. Pre-Order, In-Order, Post-Order Traversals -> Same as Binary Tree

//5. Searching
Node* searchInBST(Node* root, int target)
{
    //BC
    if(root == NULL)    
        return NULL;
    
    //Case: Found
    if(root->data == target)
        return root;

    //Case: Not Found
    if(root->data > target)
        return searchInBST(root->left, target);
    else    
        return searchInBST(root->right, target);

}

//6. Find minimum (iterative)
Node* findMinInBST(Node* root)
{
    if(root == NULL)
        return NULL;

    while(root->left != NULL)
        root = root->left;
    
    return root;
}

//7. Find maximum (recursive)
Node* findMaxInBST(Node* root)
{
    if(root == NULL)
        return NULL;

    if(root->right == NULL)
        return root;

    else    
        return findMaxInBST(root->right);
}

//8. Inorder predecessor/successor
void storeInorderTraversal(Node* root, vector<Node*>& it)
{
    if(root == NULL)    
        return;

    storeInorderTraversal(root->left, it);
    it.push_back(root);
    storeInorderTraversal(root->right, it);
}

Node* findInorderPred(Node* root, int target)
{
    vector<Node*> it; //Inorder Traversal
    storeInorderTraversal(root, it);

    Node* q = NULL;
    Node* p = NULL;

    for(int i=0; i<it.size(); i++)
    {
        q = p;
        p = it[i];

        if(it[i]->data == target)
            return q;
    }

    return NULL;
}

//9. Deletion
Node* deletionInBST(Node* root, int target)
{
    //BC
    if(root == NULL)
        return NULL;


    //Not found
    if(root->data > target)
        root->left = deletionInBST(root->left, target);
    else if(root->data < target)
        root->right = deletionInBST(root->right, target);
    //Found
    else if(root->data == target)
    {
        //Case-1: Leaf deletion
        if(!root->left && !root->right)
            return NULL;

        //Case-2: Only right branch there
        else if(!root->left && root->right)
            return root->right;

        //Case-3: Only left branch there
        else if(root->left && !root->right)
            return root->left;

        //Case-4: Both branches there
        else
        {
            //Step-1: Find Inorder-Pred of root by finding max.m in left subtree
            Node* inorderPred = findMaxInBST(root->left);
            //Step-2: Replace root's data by Inorder-pred
            root->data =  inorderPred->data;
            //Step-3: Delete Inorder-Pred from left subtree
            root->left = deletionInBST(root->left, inorderPred->data);
            return root;
        }
    }

    return root;
}



int main()
{
    //2. Insertion
    Node* root = NULL;
    root = insertToBST(root,500);
    root = insertToBST(root,150);
    root = insertToBST(root,250);
    root = insertToBST(root,600);
    root = insertToBST(root,650);
    root = insertToBST(root,170);
    root = insertToBST(root,90);
    root = insertToBST(root,220);
    root = insertToBST(root,501);
    root = insertToBST(root,1000);
    root = insertToBST(root,111);
    root = insertToBST(root,999);

    //3. Level-order-traversal (same as Binary Tree)
    vector<int> lot = levelOrderTraversal(root);
    cout<<"Level-Order-Traversal: ";
    for(auto i: lot)
        cout<<i<<",";
    cout<<endl;

    //5. Search
    Node* N1 = searchInBST(root, 600);
    cout<<N1->data<<" found at: "<<N1<<endl;

    //6. Find minimum (iterative)
    Node* N2 = findMinInBST(root);
    cout<<"Minimum is: "<<N2->data<<endl;

    //7. Find maximum (recursive)
    Node* N3 = findMaxInBST(root);
    cout<<"Maximum is: "<<N3->data<<endl;

    //8. Inorder predecessor/successor
    Node* N4 = findInorderPred(root, 250);
    cout<<"Inorder predecessor of 250 is: "<<N4->data<<endl;

    //9. Deletion
    root = deletionInBST(root, 650);
    cout<<"After deletion: ";
    vector<int> v2 = levelOrderTraversal(root);
    for(auto i: v2)
        cout<<i<<",";
    cout<<endl;




    
    return 0;
}