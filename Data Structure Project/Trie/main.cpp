#include <iostream>
#include <cstdlib>

#include "BasicProperties.h"
#include "SearchAllWord.h"
#include "SpellingHelper.h"

using namespace std;

int main()
{
    Trie *trie = new Trie;
    Initialize(trie);

    int input = 0;

    char tempWord[1][100] = {""};
    char oldWord[1][100] = {""};
    char newWord[1][100] = {""};

    while (input != 9) {
        cout << "  ====================" << endl;
        cout << "   Trie (Prefix tree) " << endl;
        cout << "  ====================" << endl;
        cout << endl;
        cout << "   1. Insert" << endl;
        cout << "   2. Delete" << endl;
        cout << "   3. Replace" << endl;
        cout << "   4. Destroy" << endl;
        cout << "   5. Survey" << endl;
        cout << "   6. All Words" << endl;
        cout << "   7. Read from file" << endl;
        cout << "   8. Spelling Helper" << endl;
        cout << "   9. Exit" << endl;
        cout << endl;
        cout << "   Choose: ";
        cin >> input;

        switch (input) {
            case 1:
                cout << endl;
                cout << "   Insert, please input word: ";
                cin >> tempWord[0];
                Insert(trie, tempWord[0]);
                break;

            case 2:
                cout << endl;
                cout << "   Delete, please input word: ";
                cin >> tempWord[0];
                Delete(trie, tempWord[0]);
                break;

            case 3:
                cout << endl;
                cout << "   Replace, please input old word: ";
                cin >> oldWord[0];
                cout << "            please input new word: ";
                cin >> newWord[0];
                ReplaceWord(oldWord[0], newWord[0], trie);
                break;

            case 4:
                Destroyed(trie);
                break;

            case 5:
                cout << endl;
                cout << "   Survey, please input word: ";
                cin >> tempWord[0];
                Display(trie, tempWord[0]);
                break;

            case 6:
                cout << endl;
                allWords(trie);
                break;

            case 7:
                cout << endl;
                readFile(trie);
                break;

            case 8:
                cout << endl;
                cout << "   Spelling Helper, please input word: ";
                cin >> tempWord[0];
                spelling(trie, tempWord[0]);
                break;

            case 9:
                cout << endl;
                cout << "   Exit." << endl;
                break;

            default:
                cout << endl;
                cout << "   Please choose again" << endl;
                break;

        }
        cout << endl;
    }

    return 0;
}
