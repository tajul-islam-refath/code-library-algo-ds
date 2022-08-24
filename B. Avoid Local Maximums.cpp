#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n;
vector<int> arr(N);

void chnage(int i)
{
    if(i<n-1)
    {
        arr[i] = max(arr[i-1], arr[i+1]);
    }
    else
    {
        arr[i] = arr[i-1];
    }

}
int main()
{

    int t;
    cin >> t;

    while(t--)
    {
        cin >> n;
        for(int i=0; i<n; ++i)
        {
            cin >> arr[i];
        }

        int ans = 0;
        for(int i=1; i<n-1; ++i)
        {
            if(arr[i-1] < arr[i] && arr[i+1] < arr[i])
            {
               chnage(i+1);
               ans++;
            }
        }

        cout << ans << endl;
        for(int i=0; i<n; i++) cout << arr[i] << " ";
        cout << endl;
    }


}
