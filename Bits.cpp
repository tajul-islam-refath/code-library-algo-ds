#include<bits/stdc++.h>
using namespace std;


void printBit(int num)
{

    for(int i=10; i>=0; i--)
        cout << ((num >> i) & 1);

    cout << endl;

}


int main()
{

    int a = 9;
    int i = 2;
    printBit(a);

    // check ith bit set or not
    printBit((1<<i));
    if( (a&(1<<i)) != 0)
        cout << "Set Bit" << endl;

    else
        cout << "Not Set Bit" << endl;

    // set ith bet

    cout << "Set i th Bit" << endl;
    printBit((a | (1<<i)));

    // Invert bit
    cout << "Invert Bit" << endl;
    printBit((~a));

    // Unset bit
    cout << "Unset i th Bit" << endl;
    printBit((a&~(1<<i)));

    // Togol bit
    cout << "Togol Bit" << endl;
    printBit((a^(1<<i)));

    cout << __builtin_popcount(a) << endl;




}
