#include <stdio.h>
#include <stdlib.h>

/**
 * Is the array sorted
 */
int isSorted(int array[], int size) {
  for (int i = 0; i < size; i++) {
    if (array[i] > array[i + 1]) {
      return 0;
    } else {
      return 1;
    }
  }
  return 1;
}

/**
 * Prints the full array
 */
void printArray(int array[], int size, char *expression) {
  printf("\n%s: [", expression);
  for (int i = 0; i < size; i++) {
    printf("%d", array[i]);

    // Print a comma after each element
    if (i != size - 1) {
      printf(", ");
    }
  }
  printf("]");
}

/*
 * Sort the array
 */
void insertionSort(int array[], int size) {
  // Size of partition to sort increases each iteration
  for (int i = 1; i < size; i++) {
    // Sort the iteration
    printArray(array, size, "The partitioned array is");
    int count = i;
    while (array[count] < array[count - 1] && count > 0) {
      int tmp = array[count];
      array[count] = array[count - 1];
      array[count - 1] = tmp;
      if(count > 0) {
        count = count - 1;
      }
    }

    printArray(array, size, "The sorted partitioned array is");
  }
}

/**
 * Make an array of size x
 */
void makeArray(int array[], int size) {
  // What are the elements in the array
  for (int i = 0; i < size; i++) {
    // Put random numbers in each element
    int random = rand() % 50;
    array[i] = random;
  }
}

int main() {
  // How big is the array
  printf("How big is your array? ");
  int size;
  scanf("%d", &size);
  int array[size];
  printf("\n");

  // Call the functions
  makeArray(array, size);
  printArray(array, size, "The initial array is");
  insertionSort(array, size);
  printArray(array, size, "The final array is");

  // Tells if the array is sorted or not
  if(isSorted(array, size)) {
    printf("\n\nThis array is sorted!");
  }
}
