#include <iostream>
#include <unordered_set>
#include "graph.h"

template <typename TKey, typename TWeight>
void depthFirst(TKey vertexKey, Graph<TKey, TWeight> &graph,
                std::unordered_set<TKey> &visited){
    // If already visited
    if(visited.find(vertexKey) != visited.end())
        return;

    visited.emplace(vertexKey);
    std::cout << "Visting vertex " << vertexKey << std::endl;

    auto adjList = graph.vertices.find(vertexKey)->second.adjVertexList;

    for(auto &adjacent: adjList){
        depthFirst(adjacent.key, graph, visited);
    }
}

template <typename TKey, typename TWeight>
void depthFirst(Graph<TKey, TWeight> &graph, std::unordered_set<TKey> &visited){
    for(auto &it: graph.vertices){
        TKey vertexKey = it.second.value;
        depthFirst(vertexKey, graph, visited);
    }
}

template <typename TKey, typename TWeight>
void depthFirst(Graph<TKey, TWeight> &graph){
    std::unordered_set<TKey> visited = std::unordered_set<TKey> ();
    depthFirst(graph, visited);
}

int main(int argc, char** argv){
    Graph<int,int> exampleGraph = makeExample();
    depthFirst(exampleGraph);

    return 0;
}