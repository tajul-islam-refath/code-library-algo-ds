#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int cunt = 0;
    int sum = 0;
    for(int i=1;  i*i <=n; ++i){
        if(n%i == 0){
            cout << i << " " << n/i << endl;
            cunt++;
            sum += i;

            if(n/i != i){
                cunt++;
                sum += n/i;
            }
        }
    }

    cout << cunt << " " << sum << endl;

}
