#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void display(Node *head)
{
    Node *temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void insertAtEnd(Node *&head, int val)
{
    Node *n = new Node(val);
    n->next = NULL;
    Node *temp = head;

    if(temp == NULL)
    {
        head = n;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
Node *reverse(Node * &head)
{
    Node *prev = NULL;
    Node *cur = head;
    Node *nxtPtr;

    while (cur != NULL)
    {
        nxtPtr = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxtPtr;
    }

    return prev;    
}

void insertAtBegin(Node *&head, int val)
{
    Node *n = new Node(val);
    n->next = head;
    head = n;
}

void mainFunc(Node * &head)
{
    Node *temp = head;
    while(temp->next != NULL)
    {
        if((temp->data) % 2 == 0)
        {
            Node *head2 = NULL;

            while ((temp->data) % 2 == 0 && (temp->next != NULL))
            {
                insertAtBegin(head2, temp->data);
                temp = temp->next;
            }
            if((temp-> data) % 2 == 0)
            {
                insertAtBegin(head2, temp->data);
            }
            display(head2);
        }
        else
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    if((temp->next == NULL) && (temp->data) % 2 != 0)
    {
        cout << temp-> data << " ";
    }
}

int main()
{
    Node *head = NULL;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        insertAtEnd(head, num);
    }

    mainFunc(head);
}