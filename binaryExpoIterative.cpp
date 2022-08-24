#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

int binaryExpoIterative(int a, int b)
{
    int ans = 1;
    while(b>0)
    {
        if(b&1)
        {
            ans = (ans * a)%M;

        }

        a = (a*a) % M;
        b>>=1;
    }

    return ans;
}

int main()
{

    int a, b;
    cin >> a >> b;
    int ans = binaryExpoIterative(a,b);
    cout << ans << endl;

}
