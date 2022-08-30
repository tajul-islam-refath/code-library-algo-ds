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


void preOrder(node *pre){
    if(pre == NULL) return;

    cout << pre->val << " ";

    preOrder(pre->leftChild);
    preOrder(pre->rightChild);


}

void inOrder(node *pre){
    if(pre == NULL) return;


    inOrder(pre->leftChild);

    cout << pre->val << " ";

    inOrder(pre->rightChild);

}

void postOrder(node *pre){
    if(pre == NULL) return;


    postOrder(pre->leftChild);
    postOrder(pre->rightChild);
    cout << pre->val << " ";


}

node* maxValue(node* Node){
    if(Node->rightChild == NULL) return Node;
    return maxValue(Node->rightChild);
}

node* minValue(node* Node){
    if(Node->leftChild == NULL) return Node;
    return maxValue(Node->leftChild);
}





int main()
{
    insertNode(45);
    insertNode(40);
    insertNode(50);
    insertNode(52);
    insertNode(41);
    insertNode(43);
    insertNode(48);

    cout << "Preorder N-L-R" << endl;
    preOrder(root);
    cout << endl;

     cout << "inOrder L-N-R" << endl;
    inOrder(root);
    cout << endl;

     cout << "postOrder L-R-N" << endl;
    postOrder(root);
    cout << endl;

    cout << "Max value " << maxValue(root)->val << endl;
     cout << "Min value " << minValue(root)->val << endl;

}


