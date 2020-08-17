#include <iostream>
#include <vector>

/*
 * Merges the array passed in by reference
 * Uses a O(N) memory overhead
 */
template <class T>
void merge(std::vector<T> &array, int start, int midPoint, int end){
    if(end > start) {
        // Is there a better way to copy vectors in C++?
        std::vector<T> left (array.begin() + start, array.begin() + midPoint + 1);
        std::vector<T> right (array.begin() + midPoint + 1, array.begin() + end + 1);

        int leftIterator = 0;
        int rightIterator = 0;
        int arrayIterator = start;

        while(leftIterator != left.size() && rightIterator != right.size()){
            if(left[leftIterator] <= right[rightIterator]){
                array[arrayIterator++] = left[leftIterator++];
            }
            else {
                array[arrayIterator++] = right[rightIterator++];
            }
        }
        // Probably a standard C++ function to do this...
        if(rightIterator == right.size())
            while(arrayIterator <= end) array[arrayIterator++] = left[leftIterator++];
        else if(leftIterator == left.size())
            while(arrayIterator <= end) array[arrayIterator++] = right[rightIterator++];
    }
}

template <class T>
void mergeSortHelper(std::vector<T> &array, int start, int end){
    if(end > start) {
        int midPoint = (int) ((end+start)/2);
        mergeSortHelper(array, start, midPoint);
        mergeSortHelper(array, midPoint+1, end);
        merge(array, start, midPoint, end);
    }
}

template <class T>
void mergeSort(std::vector<T> &array){
    mergeSortHelper(array, 0, array.size()-1);
}

int main(int argc, char** argv) {
    std::vector<int> test = {0,235,124,1412,412,312,312,312,4,124,12};
    mergeSort<int>(test);
    std::cout << "finished!\n";
    for(auto it:test) std::cout << it << " ";
}