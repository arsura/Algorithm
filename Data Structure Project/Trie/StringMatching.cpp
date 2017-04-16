#include "TrieHeader.h"

int StringMatchingCount = 0;

void StringMatching(Trie *trie, string pattern)
{
    StringMatchingCount = 0;
    vector<char> stack_word;
    TrieNode *node = trie->root;
    for (int i = 0; i < SIZE; i++) {
        if (node->children[i]) {
            stack_word.push_back(char(i));
            StringMatchingHelper(node->children[i], stack_word, 1, pattern);
        }
        stack_word.clear();
    }
    stack_word.clear();
}

void StringMatchingHelper(TrieNode *node, vector<char> stack_word, int level, string pattern)
{
    if (LeafNode(node) && FreeNode(node)) {
        string str(stack_word.begin(), stack_word.end());
        if (checkMatch(str, pattern)) { // O(n + m)
            ++StringMatchingCount;
            cout << "   " << StringMatchingCount << ": ";
            vectorPrint(stack_word);
        }
        stack_word.clear();
    }

    else {
        if (LeafNode(node) && !FreeNode(node)) {
            string str(stack_word.begin(), stack_word.end());
            if (checkMatch(str, pattern)) {
                ++StringMatchingCount;
                cout << "   " << StringMatchingCount << ": ";
                for (int i = 0; i < stack_word.size(); ++i) {
                    cout << stack_word[i];
                }
                cout << endl;
            }
        }
        for (int i = 0; i < SIZE; i++) {
            if (node->children[i]) {
                stack_word.push_back(char(i));
                StringMatchingHelper(node->children[i], stack_word, level + 1, pattern);
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

bool checkMatch(string text, string pattern)
{
    bool have = false;
    for (int i = 0; i < text.length(); i++) {
        if (pattern[0] == text[i]) {
            have = true;
            for (int j = 0; j < pattern.length(); j++) {
                if (pattern[j] != text[i + j]) {
                    have = false;
                    j = pattern.length();
                }
                if (j == pattern.length() - 1) {
                    return true;
                }
            }
        }
    }
    return have;
}
