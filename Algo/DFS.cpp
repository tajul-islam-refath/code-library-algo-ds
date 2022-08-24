
#include<bits/stdc++.h>
using namespace std;


int adj[100][100];
int color[100];
int parent[100];
int dis[100];
int node, edges;
queue<int> q;

void dfsVisit(int src)
{

    for(int i=0; i<node; i++)
    {
        if(adj[src][i]==1)
        {
            if(color[i]==0)
            {
                color[i] = 1;
                parent[i] = src;
                dis[i] = dis[src]+1;
                dfsVisit(i);
            }
        }

        color[src] = 2;
    }




}

int main()
{

    cout << "Enter Total Node : " << "\n";
    cin >> node;

    cout<< "Enter Total Edges : " << "\n";
    cin >> edges;

    //input connected nodes
    int n1,n2;
    for(int i=0; i<edges; i++)
    {
        cin >> n1 >> n2;
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }

    int src;
    cin >> src;
    parent[src] = -1;
    color[src] = 1;
    dfsVisit(src);

    for(int i=0; i<node; i++)
    {
        if(color[i] == 0)
        {
            parent[i] = -1;
            color[i] = 1;
            dfsVisit(i);
        }
    }

    for(int i=0; i<node; i++)
        cout << "Node " << i << " Parent " << parent[i] << endl;


}

/*
 node = 7
 edges = 7
 source = 0
 0 -> 1 , 2
 1 -> 2 , 3, 4
 3 -> 4
 5 -> 6
*/
