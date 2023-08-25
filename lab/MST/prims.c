#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_INT 10000

int minKey(int key[], bool mstSet[], int V)
{
    int min = MAX_INT, min_index;

    for (int v = 0; v < V; v++)
    {
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int V)
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int V)
{
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];

    for (int i = 0; i < V; i++)
    {
        key[i] = MAX_INT;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet, V);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

int main()
{
    FILE *fp;
    int V;

    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening the input file.\n");
        return 1;
    }

    fscanf(fp, "%d", &V);

    int graph[MAX_VERTICES][MAX_VERTICES];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            fscanf(fp, "%d", &graph[i][j]);
        }
    }

    fclose(fp);

    primMST(graph, V);

    return 0;
}
