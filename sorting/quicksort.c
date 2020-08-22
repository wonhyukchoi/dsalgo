/*
* Iterative implementation of quicksort in C
* using Hoare Partition
*/
#include <stdio.h>

void print_array(int* array, size_t array_size){
   for(int i=0; i<array_size - 1; i++){
       printf("%d, ", *array);
       array = array + 1;
   }
   printf("%d\n", *array);
}

int partition(int array[], int low, int high){
   int pivot = array[(low+high)/2];

   int left = low - 1;
   int right = high + 1;

   while(1){
       do ++left;  while(array[left] < pivot);
       do --right; while(array[right] > pivot);

       if(left >= right) return right;

       int temp_swap = array[left];
       array[left] = array[right];
       array[right] = temp_swap;
   }

}

void quicksort(int array[], int left, int right){
    if(right <= left) return;
    int pivot;

    pivot = partition(array, left, right);
    quicksort(array, left, pivot);
    quicksort(array, pivot + 1, right);
}

void quicksort_array(int array[], size_t array_size){
    quicksort(array, 0, array_size);
}


int main(int argc, char** argv){
    int example[] = {1,52,23,1,34,2,3,5,12,34,123,2,0};
    size_t example_size = sizeof(example) / sizeof(int);

    printf("%s\n", "INPUT: ");
    print_array(example, example_size);

    quicksort_array(example, example_size);

    printf("%s\n", "OUTPUT: ");
    print_array(example, example_size);

    return 0;
}
