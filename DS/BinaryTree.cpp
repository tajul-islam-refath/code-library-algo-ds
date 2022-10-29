#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
};

Node* root = NULL;

Node* createNode(int data)
{

    Node* newNode = new Node();
    if(!newNode)
    {
        cout << "Memory lack" << endl;
        return NULL;
    }

    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insertNode(int data)
{

    if(root == NULL)
    {
        root = createNode(data);
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp->left != NULL)
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = createNode(data);
            return;
        }

        if(temp->right != NULL)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = createNode(data);
            return;
        }
    }
}

void inOrder(Node* root)
{
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{

    int n;

    cin >> n;
    while(n--)
    {
        int data;
        cin >> data;
        insertNode(data);
    }

    inOrder(root);

}
