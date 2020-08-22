/*
* Iterative implementation of quicksort in C
* Implemented using Hoare & Lomuto partitions
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void print_array(int* array, size_t array_size){
   for(int i=0; i<array_size - 1; i++){
       printf("%d, ", *array);
       array = array + 1;
   }
   printf("%d\n", *array);
}

void swap(int array[], int i, int j){
    int temp_swap = array[i];
    array[i] = array[j];
    array[j] = temp_swap;
}

// Better to let pivot = array[high] but
// I just wanted to implement it by pretending it's a linked list.
int partition_lomuto(int array[], int low, int high){
    int pivot = array[low];
    int lesser_idx = low + 1;

    for(int i=lesser_idx; i<high; i++){
       if(array[i] < pivot){
           swap(array, i, lesser_idx);
           ++lesser_idx;
       }
    }
    --lesser_idx; // Unnecessary if we had let pivot = array[high]
    swap(array, lesser_idx, low);
    return lesser_idx;
}

void quicksort_lomuto(int array[], int left, int right){
    if(right <= left) return;
    int pivot;

    pivot = partition_lomuto(array, left, right);
    quicksort_lomuto(array, left, pivot);
    quicksort_lomuto(array, pivot + 1, right);
}

// Be careful of off-by-one errors here!
int partition_hoare(int array[], int low, int high){
   int pivot = array[(low+high)/2];

   int left = low - 1;
   int right = high + 1;

   while(1){
       do ++left;  while(array[left] < pivot);
       do --right; while(array[right] > pivot);

       if(left >= right) return right;

       swap(array, left, right);
   }

}

void quicksort_hoare(int array[], int left, int right){
    if(right <= left) return;
    int pivot;

    pivot = partition_hoare(array, left, right);
    quicksort_hoare(array, left, pivot);
    quicksort_hoare(array, pivot + 1, right);
}


int main(int argc, char** argv){
    int example[] = {1,52,23,1,34,2,3,5,12,34,123,2,0};
    size_t example_size = sizeof(example) / sizeof(int);

    // Save example to use later...
    int* example2 = malloc(sizeof(example));
    assert(memcpy(example2, example, sizeof(example)) != NULL);

    printf("%s\n", "INPUT: ");
    print_array(example, example_size);

    quicksort_lomuto(example, 0, example_size);

    printf("%s\n", "LOMUTO: ");
    print_array(example, example_size);

    printf("\n%s\n\n", "---------------");

    printf("%s\n", "INPUT: ");
    print_array(example2, example_size);

    quicksort_hoare(example, 0, example_size);

    printf("%s\n", "HOARE: ");
    print_array(example, example_size);

    return 0;
}
