#include <iostream>
#include <cstring>
using namespace std;

int lcs(char *X, char *Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
        return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
}

int main()
{
    char text1[20],text2[20];
    cin >> text1;
    cin >> text2;

    int m = strlen(text1);
    int n = strlen(text2);
    cout << "Length of LCS is " << lcs(text1, text2, m, n) << endl;

    return 0;
}
