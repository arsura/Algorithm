#include <iostream>
#include <vector>

using namespace std;

// Longest Increasing Subsequence

int main()
{
    vector<int> a{3, 4, -1, 5, 8, 2, 3, 12, 7, 9, 10};
    vector<int> table(a.size());
    vector<int> LIS;
    fill(table.begin(), table.end(), 1);

    // Create Table ------------------------------------------
    for (int i = 1; i < a.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j] && table[j] + 1 > table[i]) {
                table[i] = table[j] + 1;
            }
        }
    }
    // -------------------------------------------------------

    // Length of LIS -----------------------------------------
    int length = table[0];
    for (int k = 0; k < table.size(); ++k) {
        if (table[k] > length) length = table[k];
    }
    // -------------------------------------------------------



    // LIS ---------------------------------------------------
    int current_num = length;
    for (int l = table.size() - 1; l >= 0; --l) {
        if (table[l] == current_num) {
            LIS.push_back(a[l]);
            --current_num;
        }
    }

    for (int i = LIS.size() - 1; i >= 0; --i) cout << LIS[i] << " ";
     // LIS ---------------------------------------------------

}
