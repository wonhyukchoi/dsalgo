#include <iostream>
#include <vector>
#include "bst.h"

template <typename T>
void preorderTraversal(BinarySearchTree<T> &bst){
    Node<T>* root = bst.root.get();
    preorderTraversal(root);
    std::cout << '\n';
}

template <typename T>
void preorderTraversal(Node<T>* root){
    if(root == nullptr)
        return;
    std::cout << root->value << ' ';
    preorderTraversal(root->left.get());
    preorderTraversal(root->right.get());
}


template <typename T>
void inorderTraversal(BinarySearchTree<T> &bst){
    Node<T>* root = bst.root.get();
    inorderTraversal(root);
    std::cout << '\n';
}

template <typename T>
void inorderTraversal(Node<T>* root){
    if(root == nullptr)
        return;
    inorderTraversal(root->left.get());
    std::cout << root->value << ' ';
    inorderTraversal(root->right.get());
}

template <typename T>
void postorderTraversal(BinarySearchTree<T> &bst){
    Node<T>* root = bst.root.get();
    postorderTraversal(root);
    std::cout << '\n';
}

template <typename T>
void postorderTraversal(Node<T>* root){
    if(root == nullptr)
        return;
    postorderTraversal(root->left.get());
    postorderTraversal(root->right.get());
    std::cout << root->value << ' ';
}

int main(int argc, char** argv){
    std::vector<int> example {23,2,11,2,5,-5,6,34,8,9,42,0};
    BinarySearchTree<int> bst (example);

    std::cout << "Preorder:" << std::endl;
    preorderTraversal(bst);

    std::cout << "Inorder:" << std::endl;
    inorderTraversal(bst);

    std::cout << "Postorder:" << std::endl;
    postorderTraversal(bst);
}
