#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> primesFactor;
    for(int i=2; i*i<=n; ++i){
        while(n%i == 0){
            primesFactor.push_back(i);
            n /= i;
        }
    }

    if(n > 1){
        primesFactor.push_back(n);
    }

    for(auto value :primesFactor ){
        cout << value << " ";
    }

    // O(sqrt(N))

}
