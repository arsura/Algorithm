#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string> ResetState();

int main()
{
    vector<string> word;

    vector<string> playerWord;
    int playerCountChar[26] = {0};
    int playerChoose;

    vector<string> computerWord;
    int computerChoose;
    int computerCountChar[26] = {0};
    int computerHeuristic[9] = {0};
    bool haveTwo = false;
    bool computerHaveTwo = false;

    string status;
    int draw = 0;
    int won = 0;
    int lose = 0;

    word = ResetState();
    srand(time(0));

    cout << "Choose word form index (please input number for index 0 - 8)" << endl;
    for (int i = 0; i < word.size(); ++i) cout << word[i] << "  ";
    cout << endl << endl;

    do {
        // ================================== // Status // ================================== //
        cout << "-------------- Won: " << won << " Lose: " << lose << " Draw: " << draw << " --------------" << endl;
        cout << endl;
        cout << "The Remaining: ";
        for (int i = 0; i < word.size(); ++i) cout << word[i] << "  ";
        cout << endl;
        // ================================== // Status // ================================== //


        // ================================== // Player // ================================== //
        cout << "Player Round (index): ";
        cin >> playerChoose;
        if (playerChoose == 99) break;

        while ((playerChoose < 0 || playerChoose >= word.size()) && playerChoose != 9) {
            cout << "Player Round (index): ";
            cin >> playerChoose;
        }

        playerWord.push_back(word[playerChoose]);

        string temp = word[playerChoose];
        for (int i = 0; i < temp.length(); ++i) {
            ++playerCountChar[temp[i] - 65];
            if (playerCountChar[temp[i] - 65] >= 3) {
                word.clear();
                status = "won";
            }
        }
        if (word.size() > 0) {
            word.erase(word.begin() + playerChoose);

            cout << "Player word: ";
            for (int i = 0; i < playerWord.size(); ++i) cout << playerWord[i] << "  ";
            cout << endl;
//            for (int i = 0; i < 26; ++i) cout << playerCountChar[i] << " ";
//            cout << endl;
//            cout << "The Remaining: ";
//            for (int i = 0; i < word.size(); ++i) cout << word[i] << " ";
//            cout << endl;
        }
        // ================================== // Player // ================================== //

        cout << endl;

        // ================================== // Computer // ================================== //
        if (word.size() > 0) {

            for (int i = 0; i < 26; i++) {
                if (playerCountChar[i] == 2) {
                    //haveTwo = true;
                    for (int j = 0; j < word.size(); ++j) {
                        string temp3 = word[j];
                        for (int k = 0; k < temp3.length(); ++k) {
                            if (i + 65 == (int)temp3[k]) {
                                //++computerHeuristic[j];
                                computerChoose = j;
                                haveTwo = true;
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < 26; ++i) {
                if (computerCountChar[i] == 2) {
                    for (int j = 0; j < word.size(); ++j) {
                        string temp4 = word[j];
                        for (int k = 0; k < temp4.length(); ++k) {
                            if (i + 65 == (int)temp4[k]) {
                                computerChoose = j;
                                computerHaveTwo = true;
                            }
                        }
                    }
                }
            }

//            cout << endl;
//            for (int i = 0; i < 9; ++i) cout << computerHeuristic[i] << " ";
//            cout << endl;

            if (computerHaveTwo == true) {
                computerHaveTwo = false;
            }
            else if (haveTwo == true) {
//                int Max = 0;
//                for (int i = 0; i < 9; i++) {
//                    if (Max < computerHeuristic[i]) Max = i;
//                }
//                computerChoose = Max;
//                for (int i = 0; i < 9; i++) computerHeuristic[i] = 0;
                haveTwo = false;

            }
            else {
                computerChoose = rand() % 9;
                while (computerChoose >= word.size()) {
                    computerChoose = rand() % 9;
                }
            }

            cout << "Computer Round (index): " << computerChoose << endl;

            computerWord.push_back(word[computerChoose]);

            string temp2 = word[computerChoose];
            for (int i = 0; i < temp2.length(); ++i) {
                ++computerCountChar[temp2[i] - 65];
                if (computerCountChar[temp2[i] - 65] >= 3) {
                word.clear();
                status = "lose";
                }
            }

            if (word.size() > 0) {
                word.erase(word.begin() + computerChoose);

                cout << "Computer word: ";
                for (int i = 0; i < computerWord.size(); ++i) cout << computerWord[i] << "  ";
                cout << endl;
//                for (int i = 0; i < 26; ++i) cout << computerCountChar[i] << " ";
//                cout << endl;
//                cout << "The Remaining: ";
//                for (int i = 0; i < word.size(); ++i) cout << word[i] << " ";
//                cout << endl;

                cout << "\n----------------------------------------------------" << endl << endl;
            }
        }
        // ================================== // Computer // ================================== //

        // ================================== // Reset // ================================== //
        if (word.size() == 0) {

            if (status == "won") {
                cout << endl;
                cout << "Player Win: ";
                for (int i = 0; i < playerWord.size(); ++i) cout << playerWord[i] << " ";
                cout << endl;
                ++won;
                status = "";
            }
            else if (status == "lose") {
                cout << endl;
                cout << "Computer Win: ";
                for (int i = 0; i < computerWord.size(); ++i) cout << computerWord[i] << " ";
                cout << endl;
                ++lose;
                status = "";
            }
            else {
                ++draw;
                status = "";
            }

            word = ResetState();
            playerWord.clear();
            computerWord.clear();


            for (int i = 0; i < 26; i++) {
                computerCountChar[i] = 0;
                playerCountChar[i] = 0;
                computerHeuristic[i] = 0;
            }

            cout << endl;
            cout << "Choose word form index (please input number for index 0 - 8)" << endl;
            cout << " ";
            for (int i = 0; i < word.size(); ++i) cout << word[i] << " ";
            cout << endl << endl;
        }
        // ================================== // Reset // ================================== //

    } while (0 != 1);

}

vector<string> ResetState()
{
    return {"AS", "FAT", "FOP", "IF", "IN", "NOT", "PAN", "SO", "SPIT"};
}
