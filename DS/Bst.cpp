#include<bits/stdc++.h>
using namespace std;

typedef struct tree
{

    int val;
    struct tree *leftChild;
    struct tree *rightChild;


} node;

node *root = NULL;

void insertNode(int val)
{

    node *newNode;
    node *currentNode =NULL;
    node *parentNode =NULL;

    newNode = (node*) malloc((sizeof(node)));
    newNode->val = val;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    if(root == NULL)
    {
        root = newNode;
    }
    else
    {
        currentNode = root;
        parentNode = NULL;
        while(1)
        {
            parentNode = currentNode;
            if(val <= parentNode->val)
            {

                currentNode = parentNode->leftChild;
                if(currentNode == NULL)
                {
                    parentNode->leftChild = newNode;
                    break;
                }
            }
            else
            {
                currentNode = currentNode->rightChild;
                if(currentNode == NULL)
                {
                    parentNode->rightChild = newNode;
                    break;
                }
            }
        }
    }

}

void searchNode(int val)
{
    node *currentNode = root;
    int flag = 0;
    while(currentNode != NULL)
    {
        if(val == currentNode->val){
            flag = 1;
            break;
        }else if(val <= currentNode->val){
            currentNode = currentNode->leftChild;
        }else{
            currentNode = currentNode->rightChild;
        }
    }

    if(flag) cout << "Value Found " << currentNode->val << endl;
    else cout << "value Not Found" << endl;
}


int main()
{
    insertNode(10);
    insertNode(8);
    insertNode(7);

    searchNode(7);
    searchNode(6);
}
