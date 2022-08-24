#include <bits/stdc++.h>
using namespace std;

#define maxSize 100
int my_queue[maxSize];
int front = 0, back = -1, dataCount = 0;

void enqueue(int value)
{
    if(back == maxSize)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        my_queue[++back] = value;
        dataCount++;
    }
}

void dequeue()
{
    if(dataCount == 0)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Remove Value " << my_queue[front++] << endl;
        dataCount--;
    }

}

void my_front()
{
    cout << "Font value " << my_queue[front] << endl;
}


int main()
{

    int choice, data;

    while(true)
    {
        cout << "1 For Enqueue" << endl;
        cout << "2 For Dequeue" << endl;
        cout << "3 For Front" << endl;
        cin >> choice;

        switch(choice)
        {
        case 1:
            cin >> data;
            enqueue(data);
            break;
        case 2:
            dequeue();
             break;
        case 3:
            my_front();
             break;
        default:
            cout << "Try Again" << endl;
             break;

        }
    }

}
