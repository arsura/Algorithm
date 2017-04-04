#include "Eight_Puzzle.h"

void vectorDisplay(vector<int> state)
{
    int vector_size = state.size();
    for (int i = 0; i < vector_size; ++i) {
        if (i % 3 == 0 && i != 0) cout << endl;
        cout << state[i] << " ";
    }
    cout << endl << endl;
}

vector<int> ReadFile(string choice)
{
    vector<int> state;
    ifstream inFile(choice);
    int item;
    while (inFile >> item) {
        state.push_back(item);
    }
    inFile.close();
    return state;
}

int manhattanHeuristic(Node *node, vector<int> goal_state)
{
    int arrInitial[3][3] = {0};
    int arrGoal[3][3] = {0};

    int c = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arrInitial[i][j] = node->state_table[c];
            arrGoal[i][j] = goal_state[c];
            ++c;
        }
    }
    int Find;
    int x;
    int y;
    int Manhattan = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; j++) {
            if (arrInitial[i][j] != arrGoal[i][j] && arrInitial[i][j] != 0) {
                Find = arrInitial[i][j];
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (arrGoal[k][l] == Find) {
                            x = abs(k - i);
                            y = abs(l - j);
                            Manhattan += x + y;
                        }
                    }
                }
            }
        }
    }
    return Manhattan;
}

void createRoot(Node *root, vector<int> state, vector<int> goal)
{
    int vector_size = state.size();
    for (int i = 0; i < vector_size; ++i) {
        root->state_table.push_back(state[i]);

        if (state[i] == 0) {
            root->empty_index = i;
        }
        if (i < 5) {
            root->children[i] = NULL;
        }
    }
    root->distance = 1;
    root->parent = NULL;
    root->heuristic = manhattanHeuristic(root, goal);

}

int misplacedHeuristic(Node *node, vector<int> goal_state)
{
	int misplacedHeuristic = 0;
	int vector_size = node->state_table.size();
	for (int i = 0; i < vector_size; i++) {
		if (node->state_table[i] != goal_state[i]) {
			misplacedHeuristic++;
		}
	}
	return misplacedHeuristic;
}


bool Move(Node *parent, Node *child, char moving, vector<int> goal_state)
{

    int vector_size = parent->state_table.size();
    for (int i = 0; i < vector_size; ++i) {
        child->state_table.push_back(parent->state_table[i]);
    }
    findIndex(child);

    bool worstMove = false;
    if (parent->distance > 2 && (child->empty_index == parent->empty_index)) {
        worstMove = true;
    }

    switch (moving) { // create condition don't move position to parent empty index
        case 'u':
            if (child->empty_index > 2 && !worstMove) {
                swap(child->state_table[child->empty_index], child->state_table[child->empty_index - 3]);
            }
            else {
                return false;
            }
            break;

        case 'r':
            if (child->empty_index % 3 != 2 && !worstMove) {
                swap(child->state_table[child->empty_index], child->state_table[child->empty_index + 1]);
            }
            else {
                return false;
            }
            break;

        case 'l':
            if (child->empty_index % 3 != 0 && !worstMove) {
                swap(child->state_table[child->empty_index], child->state_table[child->empty_index - 1]);
            }
            else {
                return false;
            }
            break;

        case 'd':
            if (child->empty_index < 6 && !worstMove) {
                swap(child->state_table[child->empty_index], child->state_table[child->empty_index + 3]);
            }
            else {
                return false;
            }
            break;
    }
    return true;
}

Node *createChild(Node *parent, vector<int> goal_state)
{
    cout << "------" << endl;
    vectorDisplay(parent->state_table);
    cout << "------" << endl;

    Node *currentNode;
    Node *children[4];
    char moving[4] = {'u', 'r', 'l', 'd'};
    int minHeuristic;

    for (int i = 0; i < 4; ++i) {
        children[i] = new Node;
        if (Move(parent, children[i], moving[i], goal_state) == true) {
            children[i]->distance = parent->distance + 1;
            children[i]->heuristic = manhattanHeuristic(children[i], goal_state);
            cout << "Heuristic: " << children[i]->heuristic << endl;
            children[i]->parent = parent;
            for (int j = 0; j < 4; ++j) {
                children[i]->children[j] = NULL;
            }
        }
        else {
            children[i]->heuristic = 99;
            cout << "Heuristic: " << children[i]->heuristic << endl;
        }
        vectorDisplay(children[i]->state_table);
    }

    minHeuristic = children[0]->heuristic;
    currentNode = children[0];
    for (int i = 0; i < 4; ++i) {
        if (minHeuristic > children[i]->heuristic && children[i]->heuristic != 99) {
            minHeuristic = children[i]->heuristic;
            currentNode = children[i];
        }
    }

    cout << "======================================================" << endl;

    return currentNode;
}

void findIndex(Node *node)
{
    int vector_size = node->state_table.size();
    for (int i = 0; i < vector_size; ++i) {
        if (node->state_table[i] == 0) {
            node->empty_index = i;
            return;
        }
    }
}

bool isGoal(Node *node, vector<int> goal_state)
{
    int vector_size = goal_state.size();
    for (int i = 0; i < vector_size; ++i) {
        if (node->state_table[i] != goal_state[i])
            return false;
    }
    return true;
}

void hillClimbing(Node *node, vector<int> goal_state)
{
    Node *currentNode = new Node;
    if (isGoal(node, goal_state)) {
        return;
    }
    currentNode = createChild(node, goal_state);

    while (1) {
        if (isGoal(currentNode, goal_state)) break;
        currentNode = createChild(currentNode, goal_state);
    }
}

