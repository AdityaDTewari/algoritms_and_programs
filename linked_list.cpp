#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

class List
{
    private:
    node *head, *tail;
    public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    void createNode (int val)
    {
        node *temp = new node;
        temp->data = val;
        temp->next = NULL;
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }

    void display()
    {
        node *temp = new node;
        temp = head;
        while(temp!=NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void insert_start(int val)
    {
        node *temp = new node;
        temp->data = val;
        temp->next = head;
        head = temp;
    }

    void insertAtPos(int pos, int val)
    {
        node *pre = new node;
        node *cur = new node;
        node * temp = new node;
        cur = head;
        for (int i = 1; i < pos; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        temp->data = val;
        pre->next = temp;
        temp->next = cur;
    }

    void del_first()
    {
        node *temp = new node;
        temp = head;
        head = head-> next;
        delete temp;
    }

    void delete_last()
    {
        node * cur = new node;
        node *prev = new node;
        cur = head;
        while(cur->next != NULL)
        {
            prev = cur;
            cur = cur->next;
        }
        tail = prev;
        prev->next = NULL;
        delete cur;
    }

    void delete_pos(int pos)
    {
        node *cur = new node;
        node *prev = new node;
        cur = head;
        for(int i = 1; i < pos; i++)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
    }
};

int main()
{
    List a;
    a.createNode(1);
    a.createNode(2);
    a.createNode(3);
    a.createNode(4);
    a.createNode(5);
    a.display();
    a.del_first();
    a.delete_last();
    a.delete_pos(5);
    a.insertAtPos(3, 6);
    a.display();
}