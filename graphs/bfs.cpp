#include <iostream>
#include <queue>
#include <unordered_set>
#include "graph.h"

template <typename TKey, typename TWeight>
void breadthFirst(Graph<TKey, TWeight> &graph){
    std::unordered_set<TKey> visited;
    std::queue<TKey> toVisit;

    for(auto &it: graph.vertices){
        TKey vertexKey = it.second.value;
        toVisit.push(vertexKey);
        bool alreadyVisited;

        while(!toVisit.empty()){
            vertexKey = toVisit.front();
            toVisit.pop();

            alreadyVisited = visited.find(vertexKey) == visited.end();
            if(!alreadyVisited)
                continue;

            visited.insert(vertexKey);
            std::cout << "Visting vertex " << vertexKey << std::endl;

            auto adjList = graph.vertices.find(vertexKey)->second.adjVertexList;
            for(auto &adjacent: adjList)
                toVisit.push(adjacent.key);
        }
    }
}

int main(int argc, char** argv){
    Graph<int,int> exampleGraph = makeExample();
    breadthFirst(exampleGraph);

    return 0;
}