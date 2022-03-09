#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
    int startTime;
    int endTime;
    Node(int a, int b)
    {
        startTime = a;
        endTime = b;
    }
};

bool comp(Node a, Node b)
{
    return a.endTime < b.endTime;
}

int main()
{
    vector<Node> times;
    int n, a, b;
    cout << "Enter The Size : ";
    cin >> n;
    cout << "Enter Values : "<< endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        times.push_back(Node(a, b));
    }

    sort(times.begin(), times.end(), comp);

    int i = 0;
    cout << "( " << times[i].startTime << "," << times[i].endTime << ")" << endl;
    for (int j = 1; j < n; j++)
    {
        if (times[j].startTime >= times[i].endTime)
        {
            i = j;
            cout << "( " << times[i].startTime << "," << times[i].endTime << ")" << endl;
        }
    }
}