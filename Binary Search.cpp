#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    int to_find;
    cin >> to_find;

    int lo = 0;
    int hi = n-1;
    int mid;

    while(hi-lo > 1){
        mid  = (hi+lo) / 2;
        if(a[mid] < to_find){
            lo = mid+1;
        }else{
            hi = mid;
        }

    }

    if(a[lo] == to_find){
        cout << "Value Found in index " << lo << endl;
    }else if(a[hi] == to_find){
        cout << "Value Found in index " << hi << endl;
    }else{
        cout << "No Value Found" << endl;
    }


}
