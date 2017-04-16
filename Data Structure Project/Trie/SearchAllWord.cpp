#include "TrieHeader.h"

int Count = 0;

void setCountZero()
{
    Count = 0;
}

void allWords(Trie *trie)
{
    vector<char> stack_word;
    TrieNode *node = trie->root;
    setCountZero();

    for (int i = 0; i < SIZE; i++) {
        if (node->children[i]) {
            stack_word.push_back(char(i));
            allWordsHelper(node->children[i], stack_word, 1);
        }
        stack_word.clear();
    }

    cout << endl;
    stack_word.clear();
}

void allWordsHelper(TrieNode *node, vector<char> stack_word, int level)
{
    if (LeafNode(node) && FreeNode(node)) {
        ++Count;
        cout << "   " << Count << ": ";
        vectorPrint(stack_word);
        stack_word.clear();
    }

    else {
        if (LeafNode(node) && !FreeNode(node)) {
            ++Count;
            cout << "   " << Count << ": ";
            vectorPrint(stack_word);

        }
        for (int i = 0; i < SIZE; i++) {
            if (node->children[i]) {
                stack_word.push_back(char(i));
                allWordsHelper(node->children[i], stack_word, level + 1);
                for (int j = 0; j < SIZE; ++j) {
                    if (level == j) {
                        stack_word.erase(stack_word.begin() + j);
                    }
                }
            }
        }
    }
    stack_word.clear();
}
