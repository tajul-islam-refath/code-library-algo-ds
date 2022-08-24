#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void insertHead(int num)
{

    Node *newNode = new Node();
    newNode->data = num;
    newNode->next = newNode;

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }


}

void insertTail(int num)
{
    Node *newNode = new Node();
    newNode->data = num;
    newNode->next = newNode;

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {

        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
}

void insetMiddle(int val, int num)
{
    Node *current = head;
    int flag = 0;
    while(current != NULL)
    {
        if(current->data == val)
        {
            flag = 1;
            break;
        }
        current = current->next;
    }

    if(flag == 0)
    {
        cout << "No value found" << endl;
    }
    else
    {
        Node *newNode = new Node();
        newNode->data = num;
        newNode->next = current->next;
        current->next = newNode;
    }

}

void deleteHead()
{
    if(head == NULL)return;

    Node *temp = head;
    tail->next = head->next;
    head = head->next;

    delete(temp);

}

void deleteTail()
{
    if(head == NULL) return ;

    Node *temp = head;
    Node *prev = head;

    while(temp->next != head){

        prev = temp;
        temp = temp->next;
    }


    prev->next = head;
    tail = prev;
    delete(temp);
}

void print()
{
    if(head == NULL) return;
    Node *current = head;

    do
    {
        cout << head->data << " ";
        head = head->next;
    }
    while(head != current);
    cout << endl;
}

int main()
{


    insertHead(3);
    insertHead(2);
    insertHead(1);
    insertTail(5);
    insertTail(6);
    insetMiddle(3,4);
    insetMiddle(5,8);
    print();
    deleteHead();
    print();
    deleteTail();
    print();


}
