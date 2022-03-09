
#include <stdio.h>
#include <limits.h>

int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;
    for (k = i; k < j; k++)
    {
        count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];

        if (count < min)
            min = count;
    }
    return min;
}
/*
    20*30
    30*50
    50*10
    10*5
*/

int main()
{
    int size, i;

    printf("Enter the number of matrix : ");
    scanf("%d", &size);

    int arr[size + 1];

    printf("Enter the those matrix : ");
    for (i = 0; i <= size; i++)
        scanf("%d", &arr[i]);

    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum number of multiplications is %d ", MatrixChainOrder(arr, 1, n - 1));
    return 0;
}
