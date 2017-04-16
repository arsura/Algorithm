#ifndef TRIEHEADER_H_INCLUDED
#define TRIEHEADER_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <ctime>

#define SIZE 128

using namespace std;

struct TrieNode
{
    TrieNode *children[SIZE];
    int value;
};

struct Trie
{
    TrieNode *root;
    int Count;
};

TrieNode *createNode();
void Initialize(Trie *trie);
void Insert(Trie *trie, char *key);
void Delete(Trie *trie, char *key);
bool DeleteHelper(TrieNode *node, char *key, int level, int length);
void Destroyed(Trie *trie);
bool DestroyedHelper(TrieNode *node);
bool haveWord(Trie *node, char *key);
void ReplaceWord(char *oldWord, char *newWord, Trie *node);
void Display(Trie *node, char *key);
int FreeNode(TrieNode *node);
int LeafNode(TrieNode *node);
void readFile(Trie *trie, Trie *reverse_trie);
void reverseWord(char *key);
void vectorPrint(vector<char> &word);

// Auto Complete ==================================================================================
void autoComplete(Trie *trie, char *key);
void autoCompleteHelper(TrieNode *node, vector<char> &stack_word, char *key, int level, int index);

// Print All word in Trie =========================================================================
void setCountZero();
void allWords(Trie *trie);
void allWordsHelper(TrieNode *node, vector<char> stack_word, int level);

// String Matching ================================================================================
void StringMatching(Trie *trie, string pattern);
void StringMatchingHelper(TrieNode *node, vector<char> temp, int level, string pattern);
bool checkMatch(string text, string pattern);


#endif // TRIEHEADER_H_INCLUDED
