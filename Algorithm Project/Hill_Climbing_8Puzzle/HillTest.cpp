#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Eight_Puzzle.h"
#include "Eight_Puzzle.cpp"

bool IsGoal(Node *node, vector<int> goal_state)
{
    for (int i = 0; i < goal_state.size(); i++) {
        if (node->state_table[i] != goal_state[i]) {
            return false;
        }
    }
    return true;
}

SCENARIO( "1. Hill Climbing Test 1", "[hillClimbing]") {
    Node *state = new Node;
    GIVEN( "Begin_state is 2, 5, 1, 3, 4, 6, 7, 8, 0 and Goal_state is 1, 2, 3, 4, 5, 6, 7, 8, 0") {

        vector<int> begin_state{2, 5, 1,
                                3, 4, 6,
                                7, 8, 0};

        vector<int> goal_state{1, 2, 3,
                               4, 5, 6,
                               7, 8, 0};

        createRoot(state, begin_state, goal_state);
        WHEN("Finding shortest state to result by Hill Climbing") {
            state = hillClimbing(state, goal_state);
            THEN("final state is 1, 2, 3, 4, 5, 6, 7, 8, 0") {
                REQUIRE( IsGoal(state, goal_state) == true );
            }
        }
    }
}

SCENARIO( "2. Hill Climbing Test 2", "[hillClimbing]") {
    Node *state = new Node;
    GIVEN( "Begin_state is 5, 0, 8, 4, 2, 1, 7, 3, 6 and Goal_state is 1, 2, 3, 4, 5, 6, 7, 8, 0") {

        vector<int> begin_state{5, 0, 8,
                                4, 2, 1,
                                7, 3, 6};

        vector<int> goal_state{1, 2, 3,
                               4, 5, 6,
                               7, 8, 0};

        createRoot(state, begin_state, goal_state);
        WHEN("Finding shortest state to result by Hill Climbing") {
            state = hillClimbing(state, goal_state);
            THEN("final state is 1, 2, 3, 4, 5, 6, 7, 8, 0") {
                REQUIRE( IsGoal(state, goal_state) == true );
            }
        }
    }
}

SCENARIO( "3. Hill Climbing Test 3", "[hillClimbing]") {
    Node *state = new Node;
    GIVEN( "Begin_state is 1, 2, 3, 4, 8, 0, 7, 6, 5 and Goal_state is 1, 2, 0, 4, 5, 3, 7, 8, 6") {

        vector<int> begin_state{1, 2, 3,
                                4, 8, 0,
                                7, 6, 5};

        vector<int> goal_state{1, 2, 0,
                               4, 5, 3,
                               7, 8, 6};

        createRoot(state, begin_state, goal_state);
        WHEN("Finding shortest state to result by Hill Climbing") {
            state = hillClimbing(state, goal_state);
            THEN("final state is 1, 2, 0, 4, 5, 3, 7, 8, 6") {
                REQUIRE( IsGoal(state, goal_state) == true );
            }
        }
    }
}


SCENARIO( "4. Hill Climbing Test 4", "[hillClimbing]") {
    Node *state = new Node;
    GIVEN( "Begin_state is 3, 2, 8, 4, 5, 6, 7, 1, 0 and Goal_state is 1, 2, 3, 4, 5, 6, 7, 8, 0") {

        vector<int> begin_state{3, 2, 8,
                                4, 5, 6,
                                7, 1, 0};

        vector<int> goal_state{1, 2, 3,
                               4, 5, 6,
                               7, 8, 0};

        createRoot(state, begin_state, goal_state);
        WHEN("Finding shortest state to result by Hill Climbing") {
            state = hillClimbing(state, goal_state);
            THEN("final state is 1, 2, 3, 4, 5, 6, 7, 8, 0") {
                REQUIRE( IsGoal(state, goal_state) == true );
            }
        }
    }
}

SCENARIO( "5. Hill Climbing Test 5", "[hillClimbing]") {
    Node *state = new Node;
    GIVEN( "Begin_state is 7, 2, 4, 5, 0, 6, 8, 3, 1 and Goal_state is 0, 1, 2, 3, 4, 5, 6, 7, 8") {

        vector<int> begin_state{7, 2, 4,
                                5, 0, 6,
                                8, 3, 1};

        vector<int> goal_state{0, 1, 2,
                               3, 4, 5,
                               6, 7, 8};

        createRoot(state, begin_state, goal_state);
        WHEN("Finding shortest state to result by Hill Climbing") {
            state = hillClimbing(state, goal_state);
            THEN("final state is 0, 1, 2, 3, 4, 5, 6, 7, 8") {
                REQUIRE( IsGoal(state, goal_state) == true );
            }
        }
    }
}
