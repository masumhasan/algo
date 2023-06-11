#include <stdio.h>

int main() {
   int arr[90];
   int n = 90;
   int i, j, position, swap;
   
   // Open the input file
   FILE *file = fopen("input.txt", "r");
   if (file == NULL) {
      printf("Failed to open the input file.\n");
      return 1;
   }
   
   // Read the array elements from the file
   for (i = 0; i < n; i++) {
      if (fscanf(file, "%d", &arr[i]) != 1) {
         printf("Error reading array element from the file.\n");
         fclose(file);
         return 1;
      }
   }
   
   fclose(file); // Close the input file
   
   // Perform selection sort
   for (i = 0; i < (n - 1); i++) {
      position = i;
      for (j = i + 1; j < n; j++) {
         if (arr[position] > arr[j])
            position = j;
      }
      if (position != i) {
         swap = arr[i];
         arr[i] = arr[position];
         arr[position] = swap;
      }
   }
   
   // Print the sorted array
   for (i = 0; i < n; i++)
      printf("%d\t", arr[i]);
   
   return 0;
}
