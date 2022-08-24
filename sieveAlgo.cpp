#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
vector<bool> isPrime(N, 1);


void sieve()
{

    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<N; i++)
    {
        if(isPrime[i] == true)
        {
            for(int j=2*i; j<N; j = j+i)
            {
                isPrime[j] = false;
            }
        }
    }
}


int main()
{

    sieve();

    int a;
    cin >> a;

    if(isPrime[a] == true)
    {
        cout << a << " Is a prime number" << endl;
    }
    else
    {
        cout << a << " Is not a prime number" << endl;
    }


}
