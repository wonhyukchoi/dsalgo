#include <iostream>
#include <queue>
#include "graph.h"

template <typename TKey, typename TWeight>
void breadthFirst(Graph<TKey, TWeight>* graph){
    std::cout << "Hello World" << std::endl;
}

int main(int argc, char** argv){
    breadthFirst(&exampleGraph);

    return 0;
}