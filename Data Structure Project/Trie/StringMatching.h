#ifndef STARWORDSEARCH_H_INCLUDED
#define STARWORDSEARCH_H_INCLUDED

using namespace std;

int StringMatchingCount = 0;

bool chckMatch(string text, string pattern)
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

void StringMatchingHelper(TrieNode *node, vector<char> temp, int level, string pattern)
{
    if (!node) return;

    if (LeafNode(node) && FreeNode(node)) {
        string str(temp.begin(), temp.end());
        if (chckMatch(str, pattern)) {
            ++StringMatchingCount;
            cout << "   " << StringMatchingCount << ": ";
            for (int i = 0; i < temp.size(); ++i) {
                cout << temp[i];
                outFile << temp[i];
            }
            cout << endl;
            outFile << endl;
        }
        temp.clear();
    }

    else {
        if (LeafNode(node) && !FreeNode(node)) {
            string str(temp.begin(), temp.end());
            if (chckMatch(str, pattern)) {
                ++StringMatchingCount;
                cout << "   " << StringMatchingCount << ": ";
                for (int i = 0; i < temp.size(); ++i) {
                    cout << temp[i];
                    outFile << temp[i];
                }
                cout << endl;
                outFile << endl;
            }
        }
        for (int i = 0; i < ARRAY_SIZE; i++) {
            if (node->children[i]) {
                temp.push_back(char(i));
                StringMatchingHelper(node->children[i], temp, level + 1, pattern);
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


void StringMatching(Trie *trie, string pattern)
{
    if (!trie) return;
    cout << endl;
    StringMatchingCount = 0;
    vector<char> temp;
    TrieNode *node = trie->root;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (node->children[i]) {
            temp.push_back(char(i));
            StringMatchingHelper(node->children[i], temp, 1, pattern);
        }
        temp.clear();
    }

    cout << endl;
    temp.clear();
    outFile.close();
}


#endif // STARWORDSEARCH_H_INCLUDED
