#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CITIES 100
#define MAX_CONNECTIONS 100

struct City
{
    char name[20];
};

void addEdge(int adjacencyMatrix[MAX_CITIES][MAX_CITIES], int from, int to)
{
    adjacencyMatrix[from][to] = 1;
    adjacencyMatrix[to][from] = 1;
}

void BFS(int adjacencyMatrix[MAX_CITIES][MAX_CITIES], int numCities, int startCity, int endCity, struct City cities[MAX_CITIES])
{
    bool visited[MAX_CITIES] = {false};
    int queue[MAX_CITIES];
    int front = -1, rear = -1;

    visited[startCity] = true;
    queue[++rear] = startCity;

    int parent[MAX_CITIES];
    memset(parent, -1, sizeof(parent));

    while (front < rear)
    {
        int currentCity = queue[++front];

        if (currentCity == endCity)
        {
            int path[MAX_CITIES];
            int pathLength = 0;
            int temp = endCity;
            while (temp != -1)
            {
                path[pathLength++] = temp;
                temp = parent[temp];
            }

            printf("Shortest path from %s to %s:\n", cities[startCity].name, cities[endCity].name);
            for (int i = pathLength - 1; i >= 0; i--)
            {
                printf("%s", cities[path[i]].name);
                if (i > 0)
                {
                    printf(" -> ");
                }
            }
            printf("\n");
            return;
        }

        for (int i = 0; i < numCities; i++)
        {
            if (adjacencyMatrix[currentCity][i] && !visited[i])
            {
                visited[i] = true;
                queue[++rear] = i;
                parent[i] = currentCity;
            }
        }
    }

    printf("No path found from %s to %s.\n", cities[startCity].name, cities[endCity].name);
}

int main()
{
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    struct City cities[MAX_CITIES];
    int adjacencyMatrix[MAX_CITIES][MAX_CITIES] = {0};
    int numCities = 0;

    char fromCity[20], toCity[20];
    while (fscanf(file, "%s %s", fromCity, toCity) == 2)
    {
        int fromIndex = -1, toIndex = -1;

        for (int i = 0; i < numCities; i++)
        {
            if (strcmp(cities[i].name, fromCity) == 0)
            {
                fromIndex = i;
            }
            if (strcmp(cities[i].name, toCity) == 0)
            {
                toIndex = i;
            }
        }

        if (fromIndex == -1)
        {
            strcpy(cities[numCities].name, fromCity);
            fromIndex = numCities++;
        }
        if (toIndex == -1)
        {
            strcpy(cities[numCities].name, toCity);
            toIndex = numCities++;
        }

        addEdge(adjacencyMatrix, fromIndex, toIndex);
    }

    fclose(file);

    int startCity = 0; // Rangpur
    int endCity = 3;   // Dhaka
    BFS(adjacencyMatrix, numCities, startCity, endCity, cities);

    return 0;
}
