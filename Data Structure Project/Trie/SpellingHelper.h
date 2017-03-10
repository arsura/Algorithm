#ifndef SPELLINGHELPER_H_INCLUDED
#define SPELLINGHELPER_H_INCLUDED

#include "BasicProperties.h"
#include "SearchAllWord.h"

void spellingHelper(TrieNode *node, vector<char> temp, char *key, int level, int index)
{
    if (!node) return;

    if (index == strlen(key)) {
        allWordsHelper(node, temp, level);
    }
    else {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            if (node->children[i] && key[index] == char(i)) {
                temp.push_back(char(i));
                spellingHelper(node->children[i], temp, key, level + 1, index + 1);
            }
        }
    }
}


void spelling(Trie *trie, char *key)
{
    if (!trie) return;

    TrieNode *node = trie->root;
    int keyIndex = 0;
    vector<char> temp;
    setCountZero();

    cout << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (node->children[i] && key[keyIndex] == char(i)) {
            temp.push_back(char(i));
            spellingHelper(node->children[i], temp, key, 1, keyIndex + 1);
        }
    }

}

#endif // SPELLINGHELPER_H_INCLUDED
