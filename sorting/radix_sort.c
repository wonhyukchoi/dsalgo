#include <stdio.h>
#include <stdlib.h>
#define arr_len(x) sizeof(x)/sizeof(x[0])

void print_array(const int* array, const int arr_size){
    for(int i=0; i<arr_size; i++)
        printf("%d ", *(array+i));
    printf("%c", '\n');
}

int get_min(const int* array, const int arr_size){
    if(arr_size <= 0)
        exit(1);

    int min = *array;
    if(arr_size == 1)
        return min;

    for(int i=1; i<arr_size; i++){
        int value = *(array+i);
        if(value < min)
            min = value;
    }
    return min;
}
int get_max(const int* array, const int arr_size){
    if(arr_size <= 0)
        exit(1);

    int max = *array;
    if(arr_size == 1)
        return max;

    for(int i=1; i<arr_size; i++){
        int value = *(array+i);
        if(value > max)
            max = value;
    }
    return max;
}

void counting_sort(int* array, const int arr_size){

    int max = get_max(array, arr_size);
    int min = get_min(array, arr_size);
    int num_buckets = max - min + 1;

    // Array of frequencies, and array of sorted result
    int* counts = calloc(num_buckets, sizeof(int)); // Initialize to 0
    int* sorted = malloc(arr_size * sizeof(int));

    // Find frequency of each number
    for(int i=0; i<arr_size; i++){
        int value = *(array+i);
        ++(*(counts + value - min));
    }

    // Store the to-be indices of each number
    for(int i=1; i<num_buckets; i++)
        *(counts + i) += *(counts + i - 1);

    // Sort elements
    for(int i=0; i<arr_size; i++){
        int value = *(array+i);
        // -1 due to zero-indexing
        int position = --(*(counts + value - min));
        *(sorted + position) = value;
    }

    // Copy result into original array
    for(int i=0; i<arr_size;i++)
        *(array + i) = *(sorted + i);
}

void radix_sort(int* array, const int arr_size){
    counting_sort(array, arr_size);
}

int main(int argc, char** argv){

    int example[] = {1,54,47,56,23,23,523,1,57,47,235,341,1242,14,21,223,21,2};

    radix_sort(example, arr_len(example));
    print_array(example, arr_len(example));

	return 0;
}