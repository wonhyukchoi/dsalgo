// Sample graph taken from random website found on internet
// http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/11-Graph/weighted.html

#include <memory>
#include <unordered_map>
#include <forward_list>
#include <utility>

template <typename TKey, typename TWeight>
class Graph{

    struct Adjacent {
        TKey key;
        TWeight weight;
        Adjacent(const TKey key, const TWeight weight): key(key), weight(weight) {};
    };

    struct Vertex {
        TKey value;
        std::unique_ptr<std::forward_list<Adjacent>> adjVertexList;
        explicit Vertex(const TKey value){
            this->value = value;
            adjVertexList = std::make_unique<std::forward_list<Adjacent>>();
        }
    };

private:
    // Since keys can be non-numeric,
    // use a hashmap to index into individual adj lists
    std::unordered_map<TKey, std::unique_ptr<Vertex>> vertices;

public:

    void addVertex(TKey value);

    // Everything other than addDirectedEdge is just for a nicer API
    void addDirectedEdge(TKey src, TKey dst, TWeight weight);
    void addUndirectedEdge(TKey src, TKey dst, TWeight weight);
    void addDirectedEdge(TKey src, TKey dst);
    void addUndirectedEdge(TKey src, TKey dst);

};

Graph<int, int> makeExample();

