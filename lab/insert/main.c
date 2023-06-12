#include <stdio.h>

void iSort(int arr[], int n) {
   int i, j, key;
   for (i = 1; i < n; i++) {
      key = arr[i];
      j = i - 1;
      while (j >= 0 && arr[j] > key) {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = key;
   }
}

int main() {
   int arr[90];
   int n = 90;
   int i;
   
   FILE *file = fopen("input.txt", "r");
   if (file == NULL) {
      printf("Failed to open the input file.\n");
      return 1;
   }
   for (i = 0; i < n; i++) {
      if (fscanf(file, "%d", &arr[i]) != 1) {
         printf("Error reading array element from the file.\n");
         fclose(file);
         return 1;
      }
   }
   
   fclose(file);
   iSort(arr, n);
   
   for (i = 0; i < n; i++)
      printf("%d\t", arr[i]);
   
   return 0;
}
