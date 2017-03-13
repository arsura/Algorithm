#ifndef STARWORDSEARCH_H_INCLUDED
#define STARWORDSEARCH_H_INCLUDED

#include "BasicProperties.h"
#include "SearchAllWord.h"
#include "SpellingHelper.h"

string text;

bool stringMatching(string text, string pattern)
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

void allWordsHelperForStar(TrieNode *node, vector<char> temp, int level, string pattern)
{
    if (!node) return;

    if (LeafNode(node) && FreeNode(node)) {
        for (int j = 0; j < temp.size(); j++) {
            text += temp[j];
        }
        if (stringMatching(text, pattern)) {
            ++Count;
            cout << "   " << Count << ": ";
            cout << text << endl;
        }
        text.clear();
        temp.clear();
    }

    else {
        if (LeafNode(node) && !FreeNode(node)) {
            for (int j = 0; j < temp.size(); j++) {
                text += temp[j];
            }
            if (stringMatching(text, pattern)) {
                ++Count;
                cout << "   " << Count << ": ";
                cout << text << endl;
            }
        }
        for (int i = 0; i < ARRAY_SIZE; i++) {
            if (node->children[i]) {
                temp.push_back(char(i));
                allWordsHelperForStar(node->children[i], temp, level + 1, pattern);
                for (int j = 0; j < ARRAY_SIZE; ++j) {
                    if (level == j) {
                        temp.erase(temp.begin() + j);
                    }
                }
            }
        }
    }
    temp.clear();
}


void allWordsForStar(Trie *trie, string pattern)
{
    if (!trie) return;

    Count = 0;
    vector<char> temp;
    TrieNode *node = trie->root;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (node->children[i]) {
            temp.push_back(char(i));
            allWordsHelperForStar(node->children[i], temp, 1, pattern);
        }
        temp.clear();
    }

    cout << endl;
    temp.clear();
    outFile.close();
}


void StarWordSearch(Trie *trie, string pattern)
{
    allWordsForStar(trie, pattern);
}


#endif // STARWORDSEARCH_H_INCLUDED
