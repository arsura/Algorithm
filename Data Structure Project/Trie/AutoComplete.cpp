#include "TrieHeader.h"

void autoComplete(Trie *trie, char *key)
{
    TrieNode *node = trie->root;
    int keyIndex = 0;
    vector<char> stack_word;
    setCountZero();

    for (int i = 0; i < SIZE; i++) {
        if (node->children[i] && key[keyIndex] == char(i)) {
            stack_word.push_back(char(i));
            autoCompleteHelper(node->children[i], stack_word, key, 1, keyIndex + 1);
        }
    }
}

void autoCompleteHelper(TrieNode *node, vector<char> &stack_word, char *key, int level, int index)
{
    if (index == strlen(key)) {
        allWordsHelper(node, stack_word, level);
    }
    else {
        for (int i = 0; i < SIZE; i++) {
            if (node->children[i] && key[index] == char(i)) {
                stack_word.push_back(char(i));
                autoCompleteHelper(node->children[i], stack_word, key, level + 1, index + 1);
            }
        }
    }
}
