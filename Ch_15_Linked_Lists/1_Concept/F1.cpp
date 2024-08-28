//Concept: SLL
//1-Based indexing used
#include <bits/stdc++.h>
using namespace std;

//1. Structure
class Node
{
    public:

    int data;
    Node* next;

    Node()
    {
        this->data = 0;
        this->next = nullptr;
    }

    Node(int _data)
    {
        this->data = _data;
        this->next = nullptr;
    }

    //Destructor for dynamic objects (if needed)
    ~Node()
    {
        cout<<"Node with data: "<<this->data<<" is deleted."<<endl;
    }
};

//2. Printing a LL
void printList(Node* ptr)
{
    while(ptr!= NULL)
    {
        cout << ptr->data<<",";
        ptr = ptr->next;
    }
}

//3. Insertion at beginning
void insertAtHead(Node*& head, int data)
{
    //Case: Insertion as the only node
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }
    //Case: Normal insertion
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return;
}

//4. Insertion at the end
void insertAtTail(Node*& head, int data)
{
    //Case: Insertion as the only node
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }
    //Case: Normal insertion
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }    
    Node* newNode = new Node(data);
    temp->next = newNode;
    return;
}

//5. Find length of LL
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

//6. Insertion at a given position
void insertAtPosition(Node*& head, int data, int position)
{
    //Case: Insertion as the only node
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }

    //Case: When position is <= 1  (or) position >= LL ki length
    if(position <= 1)
    {
        insertAtHead(head, data);
        return;
    }

    if(position >= findLength(head))
    {
        insertAtTail(head, data);
    }

    //Case: Normal insertion
    Node* p = head;
    Node* q = NULL; //tailing pointer to 'p'

    while(position != 1)
    {
        position--;
        q = p;
        p = p->next;
    }

    Node* newNode = new Node(data);
    q->next = newNode;
    newNode->next = p;
}

//7. Deletion
void deleteNode(Node*& head, int position)
{
    //Case: Empty LL
    if(head == NULL)
        return;

    //Case: position <= 1 (or) position >= length of LL
    if(position <= 1) 
    {
        //Deletion as first node
        Node* temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        return;
    } 
    if(position >= findLength(head))
    {
        Node* p = head;
        Node* q = NULL;

        while(p->next != NULL)
        {
            q = p;
            p = p->next;
        }

        q->next = NULL;
        delete p;
        p = nullptr;

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
    p->next = NULL;
    delete p;
    p = nullptr;
}


int main()
{
    //1. & 2. & 3. & 4.
    Node* head = NULL;

    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtHead(head,10);

    insertAtTail(head,40);
    insertAtTail(head,50);

    printList(head);
    cout<<endl;

    //5. & 6.
    cout<<"LL Length: "<<findLength(head)<<endl;
    insertAtPosition(head, 90, 4);
    cout<<"After insertion: ";
    printList(head);
    cout<<endl;

    //7.
    deleteNode(head, 4);
    cout<<"After Deletion: "; 
    printList(head);

    return 0;
}


