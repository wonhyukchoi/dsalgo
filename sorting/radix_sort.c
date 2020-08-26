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

void counting_sort(int* array, const int arr_size,
                   const int exp, const int exp_base){

    // Since we can have negative numbers as well
    int num_buckets = exp_base * 2;
    int min = -exp_base + 1;

    // Array of frequencies, and array of sorted result
    int* counts = calloc(num_buckets, sizeof(int)); // Initialize to 0
    int* sorted = malloc(arr_size * sizeof(int));

    // Find frequency of each "digit"
    for(int i=0; i<arr_size; i++){
        int value = *(array+i)/(exp) % exp_base;
        ++(*(counts + value - min));
    }

    // Store the to-be indices of each "digit"
    for(int i=1; i<num_buckets; i++)
        *(counts + i) += *(counts + i - 1);

    // Sort elements by "digit"
    for(int i=arr_size-1; i>=0; i--){
        int value = *(array+i)/(exp) % exp_base;
        // -1 due to zero-indexing
        int position = --(*(counts + value - min));
        *(sorted + position) = *(array+i);
    }

    // Copy result into original array
    for(int i=0; i<arr_size;i++)
        *(array + i) = *(sorted + i);
}

void radix_sort_generic(int* array, const int arr_size, const int exp_base){
    int max = abs(get_max(array, arr_size));
    int min = abs(get_min(array, arr_size));

    // Get abs max to find out how many loops we need to do
    max = (max > min) ? max : min;

    // Counting sort for each "digit"
    for(int exp=1; max/exp >0; exp *= exp_base)
        counting_sort(array, arr_size, exp, exp_base);
}

// Base sorting method is in decimal system
void radix_sort(int* array, const int arr_size){
    radix_sort_generic(array, arr_size, 10);
}

int main(int argc, char** argv){

    int example[] = {9,54,47,56,23,23,523,1,-57,47,235,-1,341,1242,-14,21,0,223,21,2};

    printf("%s\n", "ORIGINAL ARRAY: ");
    print_array(example, arr_len(example));

    radix_sort(example, arr_len(example));

    printf("%s\n", "SORTED ARRAY: ");
    print_array(example, arr_len(example));

	return 0;
}