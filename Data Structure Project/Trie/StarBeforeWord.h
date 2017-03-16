#ifndef STARBEFOREWORD_H_INCLUDED
#define STARBEFOREWORD_H_INCLUDED

int StarBeforeWordCount = 0;

int chckMatchAndResize(string text, string pattern)
{
    bool have = false;
    int index = 0;
    for (int i = 0; i < text.length(); i++) {
        if (pattern[0] == text[i]) {
            have = true;
            index = i + pattern.length();
            for (int j = 0; j < pattern.length(); j++) {
                if (pattern[j] != text[i + j]) {
                    have = false;
                    j = pattern.length();
                    index = 0;
                }
                if (j == pattern.length() - 1) {
                    have = true;
                }
            }
        }
    }
    if (have) return index;
    else return 0;
}


void StarBeforeWordHelper(TrieNode *node, vector<char> temp, int level, string pattern)
{
    if (!node) return;

    if (LeafNode(node) && FreeNode(node)) {
        string str(temp.begin(), temp.end());
        int rsize = chckMatchAndResize(str, pattern);
        if (rsize > 0) {
            ++StarBeforeWordCount;
            cout << "   " << StarBeforeWordCount << ": ";
            for (int i = 0; i < rsize; ++i) {
                cout << temp[i];
            }
            cout << endl;
        }
        temp.clear();
    }

    else {
        if (LeafNode(node) && !FreeNode(node)) {
            string str(temp.begin(), temp.end());
            int rsize = chckMatchAndResize(str, pattern);
            if (rsize > 0) {
                ++StarBeforeWordCount;
                cout << "   " << StarBeforeWordCount << ": ";
                for (int i = 0; i < rsize; ++i) {
                    cout << temp[i];
                }
                cout << endl;
            }
        }
        for (int i = 0; i < ARRAY_SIZE; i++) {
            if (node->children[i]) {
                temp.push_back(char(i));
                StarBeforeWordHelper(node->children[i], temp, level + 1, pattern);
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


void StarBeforeWord(Trie *trie, string pattern)
{
    if (!trie) return;
    cout << endl;
    StarBeforeWordCount = 0;
    vector<char> temp;
    TrieNode *node = trie->root;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (node->children[i]) {
            temp.push_back(char(i));
            StarBeforeWordHelper(node->children[i], temp, 1, pattern);
        }
        temp.clear();
    }

    cout << endl;
    temp.clear();
}

#endif // STARBEFOREWORD_H_INCLUDED
