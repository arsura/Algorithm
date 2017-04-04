#ifndef EIGHT_PUZZLE_H_INCLUDED
#define EIGHT_PUZZLE_H_INCLUDED

// ================================================================================
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Node
{
    vector<int> state_table;
    Node *children[4];
    Node *parent;
    int heuristic;
    int distance;
    int empty_index;
};

void vectorDisplay(vector<int> state);
vector<int> ReadFile(string choice);
void createRoot(Node *root, vector<int> state, vector<int> goal);
int misplacedHeuristic(Node *node, vector<int> goal_state);
int manhattanHeuristic(Node *node, vector<int> goal_state);
bool isGoal(Node *node, vector<int> goal_state);
void findIndex(Node *node);
bool Move(Node *parent, Node *child, char moving, vector<int> goal_state);
Node *createChild(Node *parent, vector<int> goal_state);
void hillClimbing(Node *node, vector<int> goal_state);

// ================================================================================

#endif // EIGHT_PUZZLE_H_INCLUDED
