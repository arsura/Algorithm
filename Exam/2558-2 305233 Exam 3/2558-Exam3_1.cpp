#include <iostream>

// 2558-Exam3_1

using namespace std;

// final state 1 0 1 0 1 0 1 0 1 0
// 0 for empty glass
// 1 for full glass

int main()
{
    int n = 10;
    int state[10] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1};

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && state[i] == 0) {
            for (int j = 0; j < n; j++) {
                if (j % 2 == 1 && state[j] == 1) {
                    swap(state[i], state[j]);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) cout << state[i] << " ";

}
