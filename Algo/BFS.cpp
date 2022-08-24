#include<bits/stdc++.h>
using namespace std;


int adj[100][100];
int color[100];
int parent[100];
int dis[100];
int node, edges;
queue<int> q;

void bfs()
{
    int src;
    cin >> src;

    color[src] = 1;
    parent[src] = -1;
    q.push(src);

    while(!q.empty())
    {
        int U = q.front();
        q.pop();

        for(int i=0; i<node; i++){
            if(adj[U][i]==1){
                if(color[i]==0){
                    color[i] = 1;
                    parent[i] = U;
                    dis[i] = dis[U]+1;
                    q.push(i);
                }
            }

            color[U] = 2;
        }
    }

    for(int i=0; i<node; i++){
        cout << src << " to -> " << i << " distenc -> " << dis[i] << endl;
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

    bfs();
}

/*
 node = 8
 edges = 7
 source = 0
 0 -> 1 , 2
 1 -> 3
 2 -> 4,5
 3 -> 6 , 7
*/
