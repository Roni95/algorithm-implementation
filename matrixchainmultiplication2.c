#include <stdio.h>
#include <limits.h>

void printParenthesis(int i, int j, int n, int *bracket, char &name)
{
    if (i == j)
    {
        cout << name++;
        return;
    }

    cout << "(";
    printParenthesis(i, *((bracket + i * n) + j), n,
                     bracket, name);
    printParenthesis(*((bracket + i * n) + j) + 1, j, n,
                     bracket, name);
    cout << ")";
}

int MultiplicationChain(int p[], int i , int j){
    if (i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;
    int bracket[j][j];
    
    for (k = i; k < j; k++)
    {

        count = MultiplicationChain(p, i, k) + MultiplicationChain(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if(count < min){
            min = count;
        }
    }

    int L, x, z;
    char name = 'A';
    for (L = 2; L < j; L++)
    {
        for (int x = 1; x < j - L + 1; x++)
        {
            int z = x + L - 1;
            m[x][z] = INT_MAX;
            for (int k = x; k <= z - 1; k++)
            {
                if (q < p[x][z])
                {

                    bracket[x][z] = k;
                }
            }
        }
    }
    printParenthesis(1, z - 1, z, (int *) bracket, name);
    return min;
}

int main(){
    int size, i;
    printf("Enter the no of matrix : ");
    scanf("%d", &size);

    int arr[size + 1];
    printf("Enter those matrix order : ");
    for (i = 0; i <= size; i++)
        scanf("%d", &arr[i]);

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The minimum matrix chain multiplication is : %d\n", MutliplicationChain(arr, 1, n - 1));

    return 0; 
}