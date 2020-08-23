#include <vector>
#include <cstdio>

/*
 * Heap implementation using array
 */

template <typename T> class MinHeap{
public:
   explicit MinHeap(const std::vector<T> &array);
   T extract_min();
   void insert(T value);
private:
    std::vector<T> heap;
    void heapUp();
    void heapDown();
    void swap(int i, int j);
    int getParent(int key) {return (key-1)/2;}
    int getLeft(int key) {return 2*key + 1;}
    int getRight(int key) {return 2*key + 2;}
};

template <typename T>
MinHeap<T>::MinHeap(const std::vector<T> &array){
    typedef typename std::vector<T>::const_iterator iterator;
    for(iterator it=array.begin(); it != array.end(); it++){
        insert(*it);
    }
}

template <typename T>
void MinHeap<T>::swap(int i, int j){
    T temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

template <typename T>
T MinHeap<T>::extract_min() {
    T rv = heap[0];

    heap.front() = heap.back();
    heap.erase(heap.end() - 1);
    heapDown();

    return rv;
}

template <typename T>
void MinHeap<T>::insert(T value) {
    heap.push_back(value);
    heapUp();
}

template <typename T>
void MinHeap<T>::heapUp() {
    int key = heap.size() - 1;

    while(key != 0){
        T value = heap[key];

        int parentKey = getParent(key);
        T parentVal = heap[parentKey];

        if(parentVal <= value) break;
        else{
            swap(key, parentKey);
            key = parentKey;
        }
    }
}

template <typename T>
void MinHeap<T>::heapDown() {
   int key = 0;
   int leftKey, rightKey, minKey;
   T left, right, minVal;

   // Can probably make this loop more elegant...
   do {
     leftKey = getLeft(key); rightKey = getRight(key);

     // Check OOB
     if(leftKey >= heap.size()) break;
     else left = heap[leftKey];

     // If right key is OOB, then we just need to check left key
     if(rightKey >= heap.size()) minKey = leftKey;
     else {
         right = heap[rightKey];
         minKey = left <= right ? leftKey : rightKey;
     }

     minVal = heap[minKey];

     if(minVal < heap[key]){
         swap(key, minKey);
         key = minKey;
     } else break;

   } while(true);

}

int main(int argc, char** argv){
    std::vector<int> unsorted {0,35,23,6,3,1,234,12,32,32,12,2,1};
    MinHeap<int> heap = MinHeap<int>(unsorted);
    for(int i=0; i<unsorted.size(); i++){
        std::cout << heap.extract_min() << " ";
    }

    // printf for no reason
    printf("%c", '\n');
    return 0;
}
