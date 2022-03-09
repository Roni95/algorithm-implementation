#include <cstring>
#include <iostream>
using namespace std;

#define INF 100

int main()
{
    int V;
    cout << "Enter the size of Vertices : ";
    cin >> V;
    int G[V][V];
    cout << "Enter the Adjancy Matrix of the Graph : " << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> G[i][j];
        }
    }
    int final_edge;
    int selected[V];
    memset(selected, false, sizeof(selected));

    final_edge = 0;
    selected[0] = true;

    int x,y,total_weight=0;
    cout << "Minimum Spanning Tree is : " << endl;
    cout << "Edge   "
         << " : "
         << "Weight";
    cout << endl;
    while (final_edge < V - 1)
    {

        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && G[i][j])
                    {
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << (char)(x+65) << " ---- " << (char)(y+65) << " :  " << G[x][y];
        total_weight = total_weight + G[x][y];
        cout << endl;
        selected[y] = true;
        final_edge++;
    }

    cout << "Total Minimum weight is : " << total_weight << endl;

    return 0;
}