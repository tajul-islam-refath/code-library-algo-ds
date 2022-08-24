#include<bits/stdc++.h>
using namespace std;
int top_index = -1;
const int n = 1e5;
int arr[n];

void push(int value)
{
    arr[++top_index] = value;
}

int pop()
{
    int pop_element = arr[top_index];
    top_index--;
    return pop_element;
}

int top()
{

    return arr[top_index];
}

bool isEmpty()
{
    return top_index == -1;
}

int main()
{
    bool flag = true;

    while(flag)
    {
        int num;
        cout << "1 for push " << "2 for pop " << "3 for top "<< endl;
        cin >> num;
        switch(num)
        {
        case 1:
            int a;
            cin >> a;
            push(a);
            break;
        case 2:
            cout << pop() << endl;
            break;
        case 3:
            cout << top() << endl;
            break;
        default:
            flag = false;

        }
    }

}
