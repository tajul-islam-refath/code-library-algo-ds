#include<bits/stdc++.h>
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

    tree[node] = tree[left] + tree[right];
}

int query(int node, int l, int r, int i, int j)
{
    if(i>r || j<l)
    {
        return 0;
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

    return p1+p2;
}


void update(int node, int l, int r, int i, int value)
{
    if(i>r || i<l) return;
    if(l>=i && i<=r){
        tree[node] = value;
        return;
    }

    int left = node*2;
    int right = node*2 + 1;
    int mid = (l+r)/2;

    update(left, l, mid, i, value);
    update(right, mid+1, r, i, value);

    tree[node] = tree[left] + tree[right];
}


int main()
{

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];

    init(1, 1, n);

    update(1, 1, n, 2, 0);
    cout << query(1, 1, n, 1, 3) << endl;
    update(1, 1, n, 2, 2);
    cout << query(1, 1, n, 2, 2) << endl;
    return 0;
}
