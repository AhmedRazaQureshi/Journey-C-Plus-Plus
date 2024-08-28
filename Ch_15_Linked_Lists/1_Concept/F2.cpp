//Concept: DLL 
//1-Based indexing used

#include <bits/stdc++.h>
using namespace std;

//1. Structure
class Node
{
    public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        this->prev = NULL;
        this->data = 0;
        this->next = NULL;
    }

    Node(int _data)
    {
        this->prev = NULL;
        this->data = _data;
        this->next = NULL;
    }

    ~Node()
    {
        cout<<"Node with data "<<this->data<<" is deleted"<<endl;
    }
};

//2. Print DLL
void printList(Node* ptr)
{
    while(ptr != NULL)
    {
        cout<<ptr->data<<",";
        ptr = ptr->next;
    }
    cout<<endl;
}

//3. Find length of DLL
int findLength(Node* ptr)
{
    int count = 0;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

//4. Insertion at beginning
void insertAtHead(Node*& head, int data)
{
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

//5. Insertion at end
void insertAtTail(Node*& head, int data)
{
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }

    Node* ptr = head;

    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    Node* newNode = new Node(data);
    ptr->next = newNode;
    newNode->prev = ptr;
    return;
}

//6. Insertion at position
void insertAtPosition(Node*& head, int data, int position)
{
    //Edge case-1
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }

    //Edge case-2
    if(position <= 1)
    {
        insertAtHead(head, data);
        return;
    }
    //Edge case-3
    if(position >= findLength(head))
    {
        insertAtTail(head, data);
        return;
    }

    //Normal insertion
    Node* p = head;
    Node* q = NULL;
    
    while(position != 1)
    {
        position--;
        q = p;
        p = p->next;
    }

    Node* newNode = new Node(data);
    
    q->next = newNode;
    newNode->prev = q;

    newNode->next = p;
    p->prev = newNode;
}

//7. Deletion
void deleteNode(Node*& head, int position)
{
    //Case: Empty LL
    if(head == NULL)
        return;

    //Case: Deletion as first node
    if(position <= 1)
    {
        Node* temp = head;
        head = head->next;

        //**************** */
    }

}

