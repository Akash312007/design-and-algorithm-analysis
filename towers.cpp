#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

void moveDisk(stack<int>& source, stack<int>& destination,
              char s, char d)
{
    int disk1, disk2;

    if (source.empty())
    {
        disk2 = destination.top();
        destination.pop();
        source.push(disk2);

        cout << "Move disk " << disk2 << " from " << d
             << " to " << s << endl;
    }
    else if (destination.empty())
    {
        disk1 = source.top();
        source.pop();
        destination.push(disk1);

        cout << "Move disk " << disk1 << " from " << s
             << " to " << d << endl;
    }
    else
    {
        disk1 = source.top();
        disk2 = destination.top();

        if (disk1 < disk2)
        {
            source.pop();
            destination.push(disk1);

            cout << "Move disk " << disk1 << " from " << s
                 << " to " << d << endl;
        }
        else
        {
            destination.pop();
            source.push(disk2);

            cout << "Move disk " << disk2 << " from " << d
                 << " to " << s << endl;
        }
    }
}

int main()
{
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    stack<int> source, auxiliary, destination;
    for (int i = n; i >= 1; i--)
        source.push(i);

    char S = 'A', A = 'B', D = 'C';

    int totalMoves = pow(2, n) - 1;
    if (n % 2 == 0)
    {
        char temp = D;
        D = A;
        A = temp;
    }

    for (int i = 1; i <= totalMoves; i++)
    {
        if (i % 3 == 1)
            moveDisk(source, destination, S, D);

        else if (i % 3 == 2)
            moveDisk(source, auxiliary, S, A);

        else
            moveDisk(auxiliary, destination, A, D);
    }

    return 0;
}