#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 500010;

vector<int> adj[MAX_N];
int node, edges;
queue<int> q;

void bfs()
{
    int src;
    cin >> src;

    vector<int> dis (node+1 , -1);

    dis[src] = 0;
    q.push(src);
    while(!q.empty())
    {
        int n = q.front();
        q.pop();

        for(int adjNode : adj[n]){
            if(dis[adjNode] != -1) continue;

            dis[adjNode] = dis[n]+1;
            q.push(adjNode);
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
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
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

