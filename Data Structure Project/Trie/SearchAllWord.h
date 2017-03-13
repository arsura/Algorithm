#ifndef SEARCHALLWORD_H_INCLUDED
#define SEARCHALLWORD_H_INCLUDED

ofstream outFile("output.txt");

int Count = 0;

void setCountZero()
{
    Count = 0;
}

void allWordsHelper(TrieNode *node, vector<char> temp, int level)
{
    if (!node) return;

    if (LeafNode(node) && FreeNode(node)) {
        ++Count;
        cout << "   " << Count << ": ";
        for (int j = 0; j < temp.size(); j++) {
            cout << temp[j];
            outFile << temp[j];
        }
        cout << endl;
        outFile << endl;
        temp.clear();
    }

    else {
        if (LeafNode(node) && !FreeNode(node)) {
            ++Count;
            cout << "   " << Count << ": ";
            for (int j = 0; j < temp.size(); j++) {
                cout << temp[j];
                outFile << temp[j];
            }
            cout << endl;
            outFile << endl;
        }
        for (int i = 0; i < ARRAY_SIZE; i++) {
            if (node->children[i]) {
                temp.push_back(char(i));
                allWordsHelper(node->children[i], temp, level + 1);
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


void allWords(Trie *trie)
{
    if (!trie) return;

    setCountZero();
    vector<char> temp;
    TrieNode *node = trie->root;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (node->children[i]) {
            temp.push_back(char(i));
            allWordsHelper(node->children[i], temp, 1);
        }
        temp.clear();
    }

    cout << endl;
    temp.clear();
    outFile.close();
}


#endif // SEARCHALLWORD_H_INCLUDED
