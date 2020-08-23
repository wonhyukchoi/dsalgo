#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>

template <typename T> struct Node {
    T value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    explicit Node(const T &val){value=val; left=nullptr; right=nullptr;}
} ;

template <typename T> class BinarySearchTree{
public:
    BinarySearchTree(){root = nullptr;};
    explicit BinarySearchTree(const T &value){
        root = std::make_unique<Node<T>>(value);
    }
    explicit BinarySearchTree(const std::vector<T> &array){
        for(auto &it: array) insert(it);
    }
    // Do I need a destructor?

    void insert(const T& value){
        _insert(root, value);
    }

    bool search(const T& value){
        auto curr = root.get();
        while(curr != nullptr){
           if(value == curr->value)
               return true;
           else if(value <= curr->value)
               curr = curr->left.get();
           else
               curr = curr->right.get();
        }
        return false;
    }

    void del(const T& value){
        _delete(root, value);
    }

    T min() {
        auto curr = root.get();
        while(curr->left){
            curr = curr->left.get();
        }
        return curr->value;
    }

    T max() {
        auto curr = root.get();
        while(curr->right){
            curr = curr->right.get();
        }
        return curr->value;
    }

private:
    std::unique_ptr<Node<T>> root;

    // Is there anyway to make this iterative?
    void _insert(std::unique_ptr<Node<T>> &curr, int searchVal){
        if(!curr)
            curr = std::make_unique<Node<T>> (searchVal);
        else if(searchVal <= curr->value)
            _insert(curr->left, searchVal);
        else
            _insert(curr->right, searchVal);
    }

    void _delete(std::unique_ptr<Node<T>> &curr, int deleteVal){
        // Throw error if key is not in the tree
        if(!curr){
            std::string errorVal = std::to_string(deleteVal);
            throw std::invalid_argument("Cannot find value: " + errorVal);
        }

        // Replace node if we found the key
        else if(curr->value == deleteVal)
            _deleteNode(curr);

        // Iterate down to correct key otherwise
        else if(deleteVal <= curr->value)
            _delete(curr->left, deleteVal);
        else
            _delete(curr->right, deleteVal);
    }

    void _deleteNode(std::unique_ptr<Node<T>> &toDelete){
        // Simple if it's a leaf or has only one child
        if(!toDelete->left)
            toDelete = std::move(toDelete->right);
        else if(!toDelete->right)
            toDelete = std::move(toDelete->left);
        // Replacement algorithm using inorder successor
        else{
           toDelete->value = _findSuccessor(toDelete->right);
        }
    }

    T _findSuccessor(std::unique_ptr<Node<T>> &curr){
        if(curr->left)
            return _findSuccessor(curr->left);
        else{
            T rv = curr->value;
            curr = std::move(curr->right);
            return rv;
        }
    }

} ;

int main(int argc, char** argv){
    std::vector<int> example {23,2,11,2,5,-5,6,34,8,9,42,0};
    BinarySearchTree<int> bst (example);

    std::cout << "INPUT: ";
    for(auto &it: example) std::cout << it << " ";

    std::string search47 = bst.search(47) ? " found" : " not found";
    std::string search42 = bst.search(42) ? " found" : " not found";

    std::cout << "\nSEARCHING... " << 47 << search47;
    std::cout << "\nSEARCHING... " << 42 << search42;

    std::cout << "\nMIN: " << bst.min();
    std::cout << "\nMAX: " << bst.max() << std::endl;

    std::cout << "\nDeleting minimum";
    bst.del(bst.min());
    std::cout << "\nNEW MIN: " << bst.min();

    std::cout << "\nDeleting maximum";
    bst.del(bst.max());
    std::cout << "\nNEW MAX: " << bst.max();

    return 0;
}