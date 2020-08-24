#include <iostream>
#include "graph.h"

template <typename TKey, typename TWeight>
void depthFirst(Graph<TKey, TWeight>* graph){
    std::cout << "Hello World" << std::endl;
}

int main(int argc, char** argv){
    Graph<int,int> exampleGraph = makeExample();
    depthFirst(&exampleGraph);

    return 0;
}