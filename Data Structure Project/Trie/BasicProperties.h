#ifndef BASICPROPERTIES_H_INCLUDED
#define BASICPROPERTIES_H_INCLUDED

#define ARRAY_SIZE 128

using namespace std;

struct TrieNode
{
    TrieNode *children[ARRAY_SIZE];
    int value;
};

struct Trie
{
    TrieNode *root;
    int Count;
};

// O(1)
TrieNode *createNode()
{
    TrieNode *node = new TrieNode();

    if (node) {
        node->value = 0;
        for (int i = 0; i < ARRAY_SIZE; i++) {
            node->children[i] = NULL;
        }
    }
    return node;
}

void Initialize(Trie *trie)
{
    trie->root = createNode();
    trie->Count = 0;
}

// O(length)
void Insert(Trie *trie, char *key)
{
    int index;
    int length = strlen(key);
    TrieNode *currentNode;

    trie->Count++;
    currentNode = trie->root;

    for (int i = 0; i < length; i++) {
        index = (int)key[i];
        if (currentNode->children[index]) {
            currentNode = currentNode->children[index];
        }
        else {
            currentNode->children[index] = createNode();
            currentNode = currentNode->children[index];
        }
    }
    currentNode->value = trie->Count;
}

// O(1)
int FreeNode(TrieNode *node)
{
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (node->children[i]) {
            return 0;
        }
    }
    return 1;
}

// O(1)
int LeafNode(TrieNode *node)
{
    return (node->value != 0);
}

// O(length)
bool DeleteHelper(TrieNode *node, char *key, int level, int length)
{
    if (node) {
        if (level == length) {
            if (node->value) {
                node->value = 0;
                if (FreeNode(node)) {
                    return true;
                }
                return false;
            }
        }

        else {
            int index = (int)key[level];

            if (DeleteHelper(node->children[index], key, level + 1, length)) {
                free(node->children[index]);
                node->children[index] = NULL;
                return (!LeafNode(node) && FreeNode(node));
            }
        }
    }

    return false;
}

void Delete(Trie *trie, char *key)
{
    if (strlen(key) > 0) {
        DeleteHelper(trie->root, key, 0, strlen(key));
    }
}

// O(1) + O(length x number_of_word)
bool DestroyedHelper(TrieNode *node)
{
    if (node) {
        if (LeafNode(node) && FreeNode(node) == 1) {
            return true;
        }

        else {
            for (int i = 0; i < ARRAY_SIZE; ++i) {
                if (DestroyedHelper(node->children[i])) {
                    free(node->children[i]);
                    node->children[i] = NULL;

                    if (FreeNode(node) == 0) {
                        continue;
                    }
                    else {
                        return (!LeafNode(node) && FreeNode(node));
                    }
                }
            }
        }
    }
    return false;

}

// O(1)
void Destroyed(Trie *trie)
{
    TrieNode *currentNode = trie->root;

//    clock_t start = clock();
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (currentNode->children[i]) {
            DestroyedHelper(currentNode->children[i]);
            free(currentNode->children[i]);
            currentNode->children[i] = NULL;
        }
    }
//    double duration = (clock() - start) / (double) CLOCKS_PER_SEC;
//    cout << "           " << duration << " s" << endl;
}


bool haveWord(Trie *node, char *key)
{
    int index;
    int length = strlen(key);
    TrieNode *currentNode = node->root;

    for (int i = 0; i < length; i++) {
        index = (int)key[i];

        if (currentNode->children[index])
        {
            currentNode = currentNode->children[index];
        }
        else {
            return false;
            break;
        }

        if (i == length - 1 && currentNode->value == 0) {
            return false;
        }
    }
    return true;
}

void ReplaceWord(char *oldWord, char *newWord, Trie *node)
{
    if (!node) return;
    if (haveWord(node, oldWord)) {
        Delete(node, oldWord);
        Insert(node, newWord);
    }
    else {
        cout << endl;
        cout << "   old word not found !" << endl;
        cout << endl;
    }
}

void Display(Trie *node, char *key)
{
    if (!node) return;

    int index;
    int length = strlen(key);
    TrieNode *currentNode;

    cout << endl;
    if (haveWord(node, key)) {
        cout << "   word has found :)" << endl;
        currentNode = node->root;

        for (int i = 0; i < length; i++) {
            index = (int)key[i];

            cout << endl;
            cout << "   ";
            for (int j = 0; j < ARRAY_SIZE; j++) cout << currentNode->children[j] << " ";
            cout << endl;

            if (currentNode->children[index])
            {
                currentNode = currentNode->children[index];
                cout << "   " << key[i] << " " << currentNode->value;
            }
        }
        cout << endl;
    }
    else {
        cout << "   word not found :(" << endl;
    }
}

void readFile(Trie *trie)
{
    ifstream inFile("data.txt", ios::in);

    if (!inFile) cerr << "file not found" << endl;

    char temp[1][100] = {""};
    int countWord = 0;

//    clock_t start = clock();

    while(inFile >> temp[0]) {
        Insert(trie, temp[0]);
        ++countWord;
    }
    inFile.close();

//    double duration = (clock() - start) / (double) CLOCKS_PER_SEC;
//    cout << "           " << duration << " s" << endl;

}

#endif // BASICPROPERTIES_H_INCLUDED
