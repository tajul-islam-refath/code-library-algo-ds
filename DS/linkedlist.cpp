
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};


void append( int new_data, Node** head_ref)
{

    Node* new_node = new Node();
    Node *last = *head_ref;


    new_node->data = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    return;
}

void push(int value, Node** head)
{

    Node *node = new Node();
    node->data = value;
    node->next = *head;

    *head = node;
}

void insertAfter(int key, int value, Node* head)
{


    Node *cnode = head;
    int flag = 0;
    while(cnode != NULL)
    {
        if(cnode->data == key)
        {
            Node *new_node = new Node();
            new_node->data = value;
            new_node->next = cnode->next;

            cnode->next = new_node;

            flag = 1;
            break;
        }
        else
        {
            cnode = cnode->next;
        }
    }

    if(flag == 0) cout << "Key not found" << endl;

}

void deleteNode(int key, Node *head)
{
    Node *cn = head;
    Node *prevNode = NULL;
    int flag = 0;

    while(cn != NULL)
    {

        if(cn->data == key)
        {

            if(prevNode == NULL)
            {
                head = cn->next;
            }
            else
            {
                prevNode->next = cn->next;
            }

            cout << cn->data << " Deleted" << endl;
            delete(cn);
            flag = 1;
            break;

        }
        else
        {
            prevNode = cn;
            cn = cn->next;
        }
    }

    if(flag == 0) cout << "Key Not Found" << endl;
}


void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }

    cout << endl;
}


int main()
{
    Node* head = NULL;
    append(1, &head);
    append(2, &head);
    append(3, &head);
    append(5, &head);

    // insert item at first position
    push(0, &head);

    // insert after item
    insertAfter(3,6,head);
    insertAfter(1,10,head);
    printList(head);

    // delete node
    deleteNode(3, head);

    printList(head);

    return 0;
}
