#include<bits/stdc++.h>
using namespace std;

int binaryExpoPow(int a, int b)
{
    if(b == 0) return 1;
    int res = binaryExpoPow(a, b/2);
    if(b&1)
    {
        return a * res * res;
    }
    else
    {
        return res*res;
    }

}

int main()
{

    int a, b;
    cin >> a >> b;

    int ans = binaryExpoPow(a, b);
    cout << ans << endl;

}

