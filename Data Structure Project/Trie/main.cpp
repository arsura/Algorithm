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

#include "BasicProperties.h"
#include "SearchAllWord.h"
#include "AutoComplete.h"
#include "StringMatching.h"
#include "StarBeforeWord.h"

using namespace std;

int main()
{
    Trie *trie = new Trie;
    Initialize(trie);

    char input;
    char keyboard_temp;

    char tempWord[1][100] = {""};
    char oldWord[1][100] = {""};
    char newWord[1][100] = {""};
    string stringMatching;

    while (input != 'B') {
        cout << "  ====================" << endl;
        cout << "   Trie (Prefix tree) " << endl;
        cout << "  ====================" << endl;
        cout << endl;
        cout << "   1.  Insert" << endl;
        cout << "   2.  Delete" << endl;
        cout << "   3.  Replace" << endl;
        cout << "   4.  Destroy" << endl;
        cout << "   5.  Survey" << endl;
        cout << "   6.  All Words" << endl;
        cout << "   7.  Read from file" << endl;
        cout << "   8.  Auto Complete" << endl;
        cout << "   9.  String Matching" << endl;
        cout << "   A.  *Word" << endl;
        cout << "   B.  Exit" << endl;
        cout << endl;
        cout << "   Choose: ";
        cin >> input;

        if (input == '1') {
            cout << endl;
            cout << "   Insert, please input word: ";
            cin >> tempWord[0];
            Insert(trie, tempWord[0]);
        }

        else if (input == '2') {
            cout << endl;
            cout << "   Delete, please input word: ";
            cin >> tempWord[0];
            Delete(trie, tempWord[0]);
        }

        else if (input == '3') {
            cout << endl;
            cout << "   Replace, please input old word: ";
            cin >> oldWord[0];
            cout << "            please input new word: ";
            cin >> newWord[0];
            ReplaceWord(oldWord[0], newWord[0], trie);
        }

        else if (input == '4') {
            Destroyed(trie);
        }

        else if (input == '5') {
            cout << endl;
            cout << "   Survey, please input word: ";
            cin >> tempWord[0];
            Display(trie, tempWord[0]);
        }

        else if (input == '6') {
            cout << endl;
            allWords(trie);
        }

        else if (input == '7') {
            cout << endl;
            readFile(trie);
        }

        else if (input == '8') {
            cout << endl;
            cout << "   Auto Complete, please input word: ";
            cin >> tempWord[0];
            autoComplete(trie, tempWord[0]);
        }

        else if (input == '9') {
            cout << endl;
            cout << "   String Matching, please input word: ";
            cin >> stringMatching;
            StringMatching(trie, stringMatching);
            stringMatching.clear();
        }
        else if (input == 'A') {
            cout << endl;
            cout << "   *Word, please input word: ";
            cin >> stringMatching;
            StarBeforeWord(trie, stringMatching);
            stringMatching.clear();
        }

        else if (input == 'B') {
            cout << endl;
            input = 'B';
            cout << "   Exit." << endl;
        }

        else {
            cout << endl;
            cout << "   Please choose again!." << endl;
        }

        cout << endl;
    }

    return 0;
}
