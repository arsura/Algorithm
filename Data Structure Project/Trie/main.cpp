#include "TrieHeader.h"

int main()
{
    Trie *trie = new Trie;
    Trie *reverse_trie = new Trie;
    Initialize(trie);
    Initialize(reverse_trie);

    char keyboard_temp;
    char input;

    char inputWord[255];
    char oldWord[255];
    char newWord[255];
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
        cout << "   5.  Search" << endl;
        cout << "   6.  All Words" << endl;
        cout << "   7.  Read from file" << endl;
        cout << "   8.  Auto Complete" << endl;
        cout << "   9.  String Matching" << endl;
        cout << "   B.  Exit" << endl;
        cout << endl;
        cout << "   Choose: ";
        cin >> input;

        if (input == '1') {
            cout << endl;
            cout << "   Insert, please input word: ";
            cin >> inputWord;
            Insert(trie, inputWord);
            reverseWord(inputWord);
            Insert(reverse_trie, inputWord);
        }

        else if (input == '2') {
            cout << endl;
            cout << "   Delete, please input word: ";
            cin >> inputWord;
            Delete(trie, inputWord);
            reverseWord(inputWord);
            Delete(reverse_trie, inputWord);
        }

        else if (input == '3') {
            cout << endl;
            cout << "   Replace, please input old word: ";
            cin >> oldWord;
            cout << "            please input new word: ";
            cin >> newWord;
            ReplaceWord(oldWord, newWord, trie);
            reverseWord(oldWord);
            reverseWord(newWord);
            ReplaceWord(oldWord, newWord, reverse_trie);
        }

        else if (input == '4') {
            Destroyed(trie);
            Destroyed(reverse_trie);
        }

        else if (input == '5') {
            cout << endl;
            cout << "   Search, please input word: ";
            cin >> inputWord;
            cout << endl;
            Display(trie, inputWord);
        }

        else if (input == '6') {
            cout << endl;
            cout << "       1. Trie" << endl;
            cout << "       2. Reverse Trie" << endl;
            cout << "       3. All" << endl;
            cout << "       Choose: ";
            cin >> input;
            cout << endl;
            if (input == '1') allWords(trie);
            if (input == '2') allWords(reverse_trie);
            if (input == '3') {
                allWords(trie);
                allWords(reverse_trie);
            }
        }

        else if (input == '7') {
            cout << endl;
            readFile(trie, reverse_trie);
        }

        else if (input == '8') {
            cout << endl;
            cout << "       1. Trie" << endl;
            cout << "       2. Reverse Trie" << endl;
            cout << "       3. All" << endl;
            cout << "       Choose: ";
            cin >> input;
            cout << endl;
            cout << "   Auto Complete, please input word: ";
            cin >> inputWord;
            cout << endl;
            if (input == '1') {
                autoComplete(trie, inputWord);
            }
            if (input == '2') {
                reverseWord(inputWord);
                autoComplete(reverse_trie, inputWord);
            }
            if (input == '3') {
                autoComplete(trie, inputWord);
                reverseWord(inputWord);
                autoComplete(reverse_trie, inputWord);
            }
        }

        else if (input == '9') {
            cout << endl;
            cout << "   String Matching, please input word: ";
            cin >> stringMatching;
            cout << endl;
            StringMatching(trie, stringMatching);
        }

        else if (input == 'B' || input == 'b') {
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

