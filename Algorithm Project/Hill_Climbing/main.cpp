#include "Eight_Puzzle.h"

int main()
{
    Node *state = new Node;
    vector<int> begin_state, goal_state;
    begin_state = ReadFile("begin_state.txt");
    goal_state = ReadFile("goal_state.txt");

    vectorDisplay(begin_state);
    vectorDisplay(goal_state);

    createRoot(state, begin_state, goal_state);
    hillClimbing(state, goal_state);

    return 0;
}
