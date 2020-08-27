#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NUM_ALPHABETS 26
#define ALPHA_OFFSET 'a'

/*
 * Implementation of a case-insensitive,
 * roman alphabet trie in C
 */

struct TrieNode {
    int num_alphabets;
    char character;
    struct TrieNode* children[];
};

struct Trie {
    int num_alphabets;
    struct TrieNode* children[];
};

struct Trie* trie_new(int num_alphabets){
    struct Trie* ptr = malloc(sizeof(struct Trie*));
    if(ptr == NULL)
        exit(1);

    ptr->num_alphabets = num_alphabets;

    struct TrieNode* children = malloc(num_alphabets * sizeof(struct TreeNode*));
    if(children == NULL)
        exit(1);

    // Initialize children to null pointers
    for(int i=0; i<num_alphabets; i++)
        ptr->children[i] = NULL;

    return ptr;
}

void trie_node_delete(struct TrieNode* node){
    // Do nothing if null ptr
    if(!node)
        return;

    // Free all children
    for(int i=0; i<node->num_alphabets; i++)
        trie_node_delete(node->children[i]);

    // Free memory
    free(node);
}

void trie_delete(struct Trie* trie){
    // Do nothing if null ptr
    if(!trie)
        return;

    // Delete all children
    for(int i=0; i<trie->num_alphabets; i++)
        trie_node_delete(trie->children[i]);

    // Free memory
    free(trie);
}

void trie_insert(char* word, struct Trie* trie){
    // TODO
    for(size_t i=0; i<strlen(word); i++){
        char curr = *(word+i);
        int ascii_lowercase = tolower(curr) - ALPHA_OFFSET;
    }
}

void trie_remove(char* word, struct Trie* trie){

}

void trie_search(char* word, struct Trie* trie){
    // TODO
    for(size_t i=0; i<strlen(word); i++){
        char curr = *(word+i);
        int ascii_lowercase = tolower(curr) - ALPHA_OFFSET;

    }
}

int main(int argc, char** argv){
	char** words = {"apple", "banana", "bandana", "application", "aplomb", "badger", "band"};

	struct Trie* trie_example = trie_new(NUM_ALPHABETS);
	trie_delete(trie_example);

	printf("%s\n", "Success!");

	return 0;	
}
