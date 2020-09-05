#include <stdio.h> // printf
#include <stdlib.h> // malloc, free
#include <string.h> // strlen
#include <ctype.h> // tolower
#include <stdbool.h> // bool
#define NUM_ALPHABETS 26
#define ALPHA_OFFSET 'a'

/*
 * Implementation of a case-insensitive, roman alphabet trie in C
 */

struct TrieNode {
    int num_alphabets;
    char character;
    struct TrieNode* children[];
};

struct TrieNode* trie_new(int num_alphabets){
    struct TrieNode* ptr = malloc(sizeof(struct TrieNode*));
    if(ptr == NULL)
        exit(1);

    ptr->num_alphabets = num_alphabets;

    // Initialize children to null pointers
    for(int i=0; i<num_alphabets; i++){
        ptr->children[i] = malloc(sizeof(struct TrieNode*));
        if(!ptr->children[i])
            exit(1);
        else
            ptr->children[i] = NULL;
    }

    return ptr;
}

void trie_delete(struct TrieNode* node){
    // Do nothing if null ptr
    if(!node)
        return;

    // Free all children
    for(int i=0; i<node->num_alphabets; i++){
       trie_delete(node->children[i]);
    }

    // Free memory
    free(node);
}

void trie_insert(char* word, struct TrieNode* trie){
    // Switch to recursion so that we can pass in the parent constantly.
    struct TrieNode* curr_child = trie;
    for(size_t i=0; i<strlen(word); i++){
        char current_char = *(word+i);
        int char_index = tolower(current_char) - ALPHA_OFFSET;
        curr_child = curr_child->children[char_index];
        if(curr_child)
            continue;
        else {
            curr_child = trie_new(trie->num_alphabets);
            curr_child->character = current_char;
        }
    }
}

void trie_remove(char* word, struct TrieNode* trie){

}

bool trie_search(char* current_word, struct TrieNode* trie){
    // If we reach end of word, we're done
    if(*current_word == '\0'){
        return true;
    }
    else {
        char current_char = *current_word;
        int char_index = tolower(current_char) - ALPHA_OFFSET;
        struct TrieNode* char_child = trie->children[char_index];

        // If word you're looking for doesn't exist
        if(char_child == NULL)
            return false;
        // Else recurse to the next character to check if that's in the trie
        else
            return trie_search(++current_word, char_child);
    }
}

int main(int argc, char** argv){
	char* words[] = {"apple", "banana", "bandana", "application", "aplomb", "badger", "band"};
	size_t num_words = sizeof(words) / sizeof(char*);

	struct TrieNode* trie_example = trie_new(NUM_ALPHABETS);

	for(size_t i=0; i<num_words; i++)
	    trie_insert(*(words+i), trie_example);

	char* apple = trie_search("apple", trie_example) ? "found" : "not found";
	char* bonanza = trie_search("bonanza", trie_example) ? "found" : "not found";

	printf("Apple is %s\n",apple);
	printf("Bonanza is %s\n", bonanza);

	trie_delete(trie_example);

	printf("%s\n", "Success!");

	return 0;	
}
