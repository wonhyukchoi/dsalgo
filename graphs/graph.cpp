// I feel like this is more practice of C++ than algorithms...
// Frankly my implementation is so convoluted I'll probably forget it
// if I ever decide to come back it.

#include <stdexcept>
#include "graph.h"

template <typename TKey, typename TWeight>
void Graph<TKey, TWeight>::addVertex(TKey value) {
    vertices.insert(std::make_pair(value, Vertex(value)));
}

template <typename TKey, typename TWeight>
void Graph<TKey, TWeight>::addDirectedEdge(TKey src, TKey dst, TWeight weight) {

    auto srcPtr = vertices.find(src);

    if(srcPtr == vertices.end())
        throw std::invalid_argument("Cannot find source");
    else if(vertices.find(dst) == vertices.end())
        throw std::invalid_argument("Cannot find destination");

    Vertex *vertex = &srcPtr->second;
    vertex->adjVertexList.push_front(Adjacent(dst, weight));

}

template <typename TKey, typename TWeight>
void Graph<TKey, TWeight>::addUndirectedEdge(TKey src, TKey dst, TWeight weight) {
    addDirectedEdge(src, dst, weight);
    addDirectedEdge(dst, src, weight);
}

template <typename TKey, typename TWeight>
void Graph<TKey, TWeight>::addDirectedEdge(TKey src, TKey dst) {
    addDirectedEdge(src, dst, 0);
}

template <typename TKey, typename TWeight>
void Graph<TKey, TWeight>::addUndirectedEdge(TKey src, TKey dst){
    addUndirectedEdge(src, dst, 0);
}

Graph<int, int> makeExample(){
    Graph<int, int> example;
    for(int i=0; i<9; i++){
        example.addVertex(i);
    }
    example.addUndirectedEdge(8, 0, 4);
    example.addUndirectedEdge(8, 4, 8);
    example.addUndirectedEdge(0, 3, 2);
    example.addUndirectedEdge(0, 1, 3);
    example.addUndirectedEdge(3, 4, 1);
    example.addUndirectedEdge(3, 2, 6);
    example.addUndirectedEdge(1, 7, 4);
    example.addUndirectedEdge(2, 7, 2);
    example.addUndirectedEdge(2, 5, 1);
    example.addUndirectedEdge(5, 6, 8);

    return example;
}
