#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <cstring>

// Binary Expression Tree Construct

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
    char data;
    BT* right;
    BT* left;
    BT(char d)
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

bool isOperator(char op)
{
    return op == '+' || op == '-' || op == '*' || op == '/';
}


BT* Construct(string postfix)
{
    vector<BT *> Stack;
    BT *t, *t1, *t2;

    for (int i = 0; i < postfix.length(); i++) {
        if (!isOperator(postfix[i])) {
            // operand
            t = new BT(postfix[i]);
            Stack.push_back(t);
        }
        else {
            // operator
            t = new BT(postfix[i]);
            t1 = Stack.back();
            Stack.pop_back();
            t2 = Stack.back();
            Stack.pop_back();

            t->right = t1;
            t->left = t2;

            Stack.push_back(t);
        }
    }

    t = Stack.back();
    Stack.pop_back();

    return t;
}

int main()
{
    BT* Bxt = Construct("ab+ef*g*-");

    cout << "Inorder: " << endl;
    Inorder(Bxt);
    cout << endl;

    cout << "Preorder: " << endl;
    Preorder(Bxt);
    cout << endl;

    cout << "Postorder: " << endl;
    Postorder(Bxt);
    cout << endl;
}
