#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <cstring>


// Binary Expression Tree Traversal

using namespace std;

//        +
//       / \
//      3   *
//         / \
//        +   2
//       / \
//      5   9

struct BT
{
    string data;
    BT* right;
    BT* left;
    BT(string d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }
};

void Inorder(BT* bt)
{
    if (bt) {
        Inorder(bt->left);
        cout << bt->data;
        Inorder(bt->right);
    }
}

void Preorder(BT* bt)
{
    if (bt) {
        cout << bt->data;
        Preorder(bt->left);
        Preorder(bt->right);
    }
}

void Postorder(BT* bt)
{
    if (bt) {
        Postorder(bt->left);
        Postorder(bt->right);
        cout << bt->data;
    }
}

bool isOperator(string op)
{
    return op == "+" || op == "-" || op == "*" || op == "/";
}

int calculate(int a, int b, string op)
{
    if (op == "+") return a + b;
    else if (op == "-") return a - b;
    else if (op == "*") return a * b;
    else if (op == "/") return a / b;
}

int Evaluating(BT *node)
{
    int operand;
    int value1;
    int value2;

    if (node) {
        if (!isOperator(node->data)) {
            istringstream(node->data) >> operand;
            return operand;
        }
        int value1 = Evaluating(node->left);
        int value2 = Evaluating(node->right);
//        cout << value1 << node->data << value2 << endl;
        return calculate(value1, value2, node->data);
    }
}

int main()
{
    BT* Bt = new BT("+");
    Bt->left = new BT("3");
    Bt->right = new BT("*");
    Bt->right->right = new BT("2");
    Bt->right->left = new BT("+");
    Bt->right->left->left = new BT("5");
    Bt->right->left->right = new BT("9");

    Inorder(Bt); // Infix
    cout << endl;
    Breadth_First_Search(Bt);

    cout << endl;
    cout << Evaluating(Bt) << endl;
}
