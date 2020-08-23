#include <iostream>

template <typename T> struct Node {
	T value;
	Node* left;
	Node* right;
	Node(){value = 0; left = nullptr; right = nullptr;}
	Node(T val) {value = val; left = nullptr; right = nullptr;}
};
