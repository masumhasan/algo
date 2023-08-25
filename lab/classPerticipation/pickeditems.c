#include <stdio.h>
#include <stdlib.h>

int Max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int knapsack(int m, int n, int p[], int wt[], int selected[])
{
    int k[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= m; w++)
        {
            if (i == 0 || w == 0)
                k[i][w] = 0;
            else if (wt[i] <= w)
            {
                k[i][w] = Max(k[i - 1][w], p[i] + k[i - 1][w - wt[i]]);
                if (p[i] + k[i - 1][w - wt[i]] > k[i - 1][w])
                    selected[i] = 1;
            }
            else
                k[i][w] = k[i - 1][w];
        }
    }
    return k[n][m];
}

int main()
{
    int profit[] = {0, 4, 3, 6, 5};
    int weight[] = {0, 3, 2, 5, 4};
    int n = 4;
    int capacity = 5;
    int maxP;

    int selected[n + 1];
    for (int i = 0; i <= n; i++)
    {
        selected[i] = 0;
    }

    maxP = knapsack(capacity, n, profit, weight, selected);
    printf("Max Profit: %d\n", maxP);

    printf("Selected Items:\n");
    for (int i = 1; i <= n; i++)
    {
        if (selected[i])
        {
            printf("Item %d \n", i);
        }
    }

    return 0;
}
