#include <bits/stdc++.h>

using namespace std;

#define mx 100001
int arr[mx];
int tree[mx*3];

void init(int node, int l, int r)
{
    if(l == r)
    {
        tree[node] = arr[l];
        return;
    }

    int left = node*2;
    int right = node*2 + 1;
    int mid = (l+r)/2;

    init(left, l, mid);
    init(right, mid+1, r);

    tree[node] = min(tree[left] , tree[right]);
}

int query(int node, int l, int r, int i, int j)
{
    if(i>r || j<l)
    {
        return INT_MAX;
    }

    if(l>=i && r<=j)
    {
        return tree[node];
    }

    int left = node*2;
    int right = node*2 + 1;
    int mid = (l+r)/2;

    int p1 = query(left, l, mid, i, j);
    int p2 = query(right, mid+1, r, i, j);

    return min(p1,p2);
}


int main(){
    int t;
    cin >> t;
    int c = 0;
    while(t--){
        c++;
        int n,q;
        cin >> n >> q;
        for(int i=1; i<=n; i++) cin >> arr[i];
        init(1 ,1 ,n);
        cout << "CASE " << c << endl;
        int i,j;
        for(int k=0; k<q; k++){
          cin >> i >> j;
          cout << query(1 ,1 , n, i , j) << endl;
        }
    }

}
