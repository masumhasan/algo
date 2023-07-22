#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int weight;
    int value;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void knapsack(int numItems, int capacity, struct Item items[])
{
    int dp[numItems + 1][capacity + 1];

    for (int i = 0; i <= numItems; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (items[i - 1].weight <= w)
                dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    int maxValue = dp[numItems][capacity];

    int selectedItems[numItems];
    int i = numItems, w = capacity;
    int numSelectedItems = 0;
    while (i > 0 && w > 0)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            selectedItems[numSelectedItems++] = i;
            w -= items[i - 1].weight;
        }
        i--;
    }

    printf("Maximum item value : %d\n", maxValue);
    printf("Items We selected : ");
    for (int j = numSelectedItems - 1; j >= 0; j--)
    {
        printf("Item %d", selectedItems[j]);
        if (j != 0)
            printf(", ");
    }
    printf("\n");
}

int main()
{
    int numItems = 5;
    int capacity = 5;
    struct Item items[] = {
        {2, 12},
        {1, 10},
        {3, 20},
        {2, 15},
        {1, 5}};

    knapsack(numItems, capacity, items);

    return 0;
}
