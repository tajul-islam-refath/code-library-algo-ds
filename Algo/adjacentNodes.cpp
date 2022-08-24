#include<bits/stdc++.h>
using namespace std;

int adj[100][100];

int main()
{

    int node, edge, n1, n2;
    printf("Enter Total Node : ");
    scanf("%d", &node);
    printf("Enter Total Edge : ");
    scanf("%d", &edge);

    printf("Enter Connection Between Nodes : ");
    for(int i=0; i<edge; i++)
    {
        scanf("%d %d", &n1, &n2);
        adj[n1][n2]=1;
        adj[n2][n1]=1;
    }

    printf("Adjacent Nodes : ");
    for(int i=0; i<node; i++)
    {
        for(int j=0; j<node; j++)
        {
            if(adj[i][j]==1)
                cout << i << " -> " << j <<endl;
        }
    }

}

// Node 5
// Edges 6
// Adj Nodes
//0 1
//2 0
//2 1
//1 3
//3 4
//1 4
