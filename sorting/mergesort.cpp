#include <iostream>
#include <vector>
#include <algorithm>

/*
 * Merges the array passed in by reference
 * Uses a O(N) memory overhead
 */
template <class T>
void merge(std::vector<T> &array, int start, int midPoint, int end){
    if(end > start) {
        std::vector<T> left (array.begin() + start, array.begin() + midPoint + 1);
        std::vector<T> right (array.begin() + midPoint + 1, array.begin() + end + 1);

        int leftIterator = 0;
        int rightIterator = 0;
        int arrayIterator = start;

        while(leftIterator != left.size() && rightIterator != right.size()){
            if(left[leftIterator] <= right[rightIterator])
                array[arrayIterator++] = left[leftIterator++];
            else
                array[arrayIterator++] = right[rightIterator++];
        }

        typedef typename std::vector<T>::iterator it;
        it remainingIterator = array.begin() + arrayIterator;
        it remainingBegin;
        it remainingEnd;

        if(rightIterator == right.size()){
           remainingBegin = left.begin() + leftIterator;
           remainingEnd = left.end();
        }
        else { // leftIterator == left.size()
            remainingBegin = right.begin() + rightIterator;
            remainingEnd = right.end();
        }

        std::copy(remainingBegin, remainingEnd, remainingIterator);
    }
}

template <class T>
void mergeSort(std::vector<T> &array, int start, int end){
    if(end > start) {
        int midPoint = (int) ((end+start)/2);
        mergeSort(array, start, midPoint);
        mergeSort(array, midPoint+1, end);
        merge(array, start, midPoint, end);
    }
}

/*
* Overloaded function to provide better API
*/
template <class T>
void mergeSort(std::vector<T> &array){
    mergeSort(array, 0, array.size()-1);
}

int main(int argc, char** argv) {
    std::vector<int> test = {5,1,21,5,2,124,8,2,125,13215,3421,2,1,3,47};
    mergeSort(test);
    std::cout << "finished!\n";
    for(auto it:test) std::cout << it << " ";
    std::cout << "\n";
}
