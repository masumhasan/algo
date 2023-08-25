#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void printLCS(char *X, char *Y, int m, int n, int L[][n + 1])
{
    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    printf("Longest Common Subsequence: %s\n", lcs);
}

int LCS(char *X, char *Y, int m, int n)
{
    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    printLCS(X, Y, m, n, L);

    return L[m][n];
}

int main()
{
    char X[100];
    char Y[100];

    FILE *file = fopen("file.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open the input file.\n");
        return 1;
    }

    fscanf(file, "%s", X);
    fscanf(file, "%s", Y);

    fclose(file);

    int m = strlen(X);
    int n = strlen(Y);

    int lcsLength = LCS(X, Y, m, n);

    printf("Length of Longest Common Subsequence: %d\n", lcsLength);

    return 0;
}
