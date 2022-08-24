#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int a[N];

void marge(int l, int r, int mid)
{
    int l_sz = mid-l+ 1;
    int r_sz = r - mid;

    int l_a[l_sz+1];
    int r_a[r_sz+1];

    for(int i=0; i<l_sz; ++i)
    {
        l_a[i] = a[i+l];
    }
    for(int i=0; i<r_sz; ++i)
    {
        r_a[i] = a[i+mid+1];
    }

    l_a[l_sz] = r_a[r_sz] = INT_MAX;

    int l_i = 0;
    int r_i = 0;

    for(int i=l; i<=r; ++i)
    {
        if(l_a[l_i] <= r_a[r_i])
        {
            a[i] = l_a[l_i];
            l_i++;
        }
        else
        {
            a[i] = r_a[r_i];
            r_i++;
        }
    }

}

void margeSort(int l, int r)
{
    if(l == r) return;
    int mid  = (l+r)/2;
    margeSort(l, mid);
    margeSort(mid+1, r);
    marge(l, r, mid);
}



int main()
{
    int n;
    cin >> n;

    for(int i=0; i<n; ++i)
    {
        cin >> a[i];
    }

    margeSort(0, n-1);

    for(int i=0; i<n; ++i){
        cout << a[i] << " ";
    }

}
