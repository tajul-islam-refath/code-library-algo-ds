#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9+7;
ll c = 1e18+7;

int binExpo(ll a, ll b)
{
    ll ans = 1;
    while(b>0)
    {
        // cout <<a << " " <<  ans << endl;
        if(b&1)
        {
            ans = binMulti(ans, a);
        }
        a = binMulti(a , a);
        b >>= 1;


    }

    return ans;
}

int binMulti(ll a, ll b)
{
    ll ans = 0;
    while(b>0)
    {

        if(b&1)
        {
            ans = (ans+a)% M;
        }
        a = (a+a) % M;
        b >>= 1;


    }

    return ans;

}

int main()
{

    ll a,b;

    cin >> a >> b;

    cout << binExpo(a, b) << endl;



}
