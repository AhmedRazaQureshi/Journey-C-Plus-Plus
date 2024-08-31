// Concept: Circular DLL
// 1-Based indexing used
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
        cout<<"Node with data "<<this->data<<" deleted."<<endl;
    }
};

//2. Print list
void printList(Node* head)
{
    //Case: Empty LL
    if(head == NULL)
        return;

    //Case: Only 1 node in LL
    if(head-> next == head)
    {
        cout<<head->data<<","<<endl;
        return;
    }

    //Case: Regular cases
    cout<<head->data<<",";
    
    Node* ptr = head->next;
    while(ptr != head)
    {
        cout<<ptr->data<<",";
        ptr = ptr->next;
    }
    cout<<endl;
}

//3. Find length of LL
int findLength(Node* ptr)
{
    //Case: Empty LL
    if(ptr == NULL)
        return 0;

    //Case: Only 1 node in LL
    if(ptr->next == ptr)
        return 1;

    //Case: Regular cases
    Node* start = ptr;
    int count = 1;
    while(ptr->next != start)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

//4. Insertion at the beginning
void insertAtHead(Node*& head, int data)
{
    //Case: Empty LL
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;

        newNode->next = newNode;
        newNode->prev = newNode;

        return;
    }

    //Case: Regular insertion
    Node* newNode = new Node(data);
    
    newNode->next = head;
    newNode->prev = head->prev;

    head->prev = newNode;
    newNode->prev->next = newNode; //[BE CAREFUL]

    head = newNode;
}

//5. Insertion at the end
void insertAtTail(Node*& head, int data) 
{
    //Case: Empty LL
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        newNode->next = newNode;
        newNode->prev = newNode;

        head = newNode;
        return;
    }

    //Case: Normal cases
    Node* newNode = new Node(data);
    Node* tail = head->prev;

    tail->next = newNode;
    newNode->prev = tail;

    newNode->next = head;
    head->prev = newNode;
}


//6. Insert at position
void insertAtPosition(Node*& head, int position, int data)
{
    //Case: Empty LL
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;

        newNode->next = newNode;
        newNode->prev = newNode;

        return;
    }

    //Case: Insertion at the beginning
    if(position <= 1)
    {
        insertAtHead(head, data);
        return;
    }

    //Case: Insertion at the end
    if(position >= findLength(head))
    {
        insertAtTail(head, data);
        return;
    }

    //Case: Normal insertion
    Node* p = head;
    Node* q = NULL;
    while(position != 1)
    {
        position--;
        q = p;
        p = p->next;
    }

    Node* newNode = new Node(data);
    newNode->prev = q;
    newNode->next = p;

    q->next = newNode;

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
        Node* ptr = head;

        head = head->next;

        ptr->prev->next = head;
        head->prev = ptr->prev;

        ptr->prev = NULL;
        ptr->next = NULL;

        delete ptr;
        return;
    }

    //Case: Deletion as last node
    if(position >= findLength(head))
    {
        Node* p = head;
        Node* q = NULL;

        while(p->next != head)
        {
            q = p;
            p = p->next;
        }

        q->next = head;
        head->prev = q;

        p->next = NULL;
        p->prev = NULL;

        delete p;
        return;
    }

    //Case: Normal deletion
    Node* p = head;
    Node* q = NULL;

    while(position != 1)
    {
        position--;
        q = p;
        p = p->next;
    }

    q->next = p->next;
    p->next->prev = q;

    p->next = NULL;
    p->prev = NULL;

    delete p;
}


int main()
{
    //1, 2, 3, 4, & 5
    Node* head = NULL;
    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtHead(head,10);
    printList(head);

    insertAtTail(head,40);
    insertAtTail(head,50);
    printList(head);


    //6 & 7
    insertAtPosition(head, 4, 90);
    printList(head);
    deleteNode(head,4);
    printList(head);



    return 0;
}