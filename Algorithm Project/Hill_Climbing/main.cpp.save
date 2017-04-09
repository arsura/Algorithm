#include "Eight_Puzzle.h"

int main()
{
    srand(time(NULL));
    Node *state = new Node;
    vector<int> begin_state, goal_state;
    ReadFile(begin_state, goal_state);

    vectorDisplay(begin_state);
    vectorDisplay(goal_state);

    createRoot(state, begin_state, goal_state);
    hillClimbing(state, goal_state);

    return 0;
}
