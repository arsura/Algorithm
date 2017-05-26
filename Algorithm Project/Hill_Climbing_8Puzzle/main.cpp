#include "Eight_Puzzle.h"

int main()
{
    clock_t start;
    double duration;
    srand(time(NULL));
    Node *state = new Node;
    vector<int> begin_state, goal_state;
    ReadFile(begin_state, goal_state);
    createRoot(state, begin_state, goal_state);

//    start = clock();
    state = hillClimbing(state, goal_state);
//    duration = clock() - start;

//    cout << duration / (double) CLOCKS_PER_SEC << endl;

    return 0;
}
