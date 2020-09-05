#include <iostream>
#include "bst.h"

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
