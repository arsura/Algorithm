#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// is Binary Search Tree

struct BST
{
    int data;
    BST* left;
    BST* right;

    BST(int newData)
    {
        data = newData;
        left = NULL;
        right = NULL;
    }
};

BST* Insert(BST* node, int data)
{
    if (node == NULL) {
        node = new BST(data);
    }
    else if (data > node->data) {
        node->right = Insert(node->right, data);
    }
    else if (data < node->data) {
        node->left = Insert(node->left, data);
    }
    return node;
}

void Inorder(BST* node, vector<int> &List)
{
    if (node) {
        Inorder(node->left, List);
//        cout << node->data << " ";
        List.push_back(node->data);
        Inorder(node->right, List);
    }
}

bool isBinarySearchTree(vector<int> &a, BST* bst)
{
    vector<int> List;

    Inorder(bst, List);

    for (int i = 0; i < List.size() - 1; i++)
        if (List[i] > List[i + 1]) return false;

    return true;
}

void LevelOrder(BST *root)
{
    if (root == NULL) return;
    queue<BST*> Q;
    Q.push(root);
    while (!Q.empty()) {
        BST *currentNode = Q.front();
        cout << currentNode->data << " ";
        if (currentNode->left != NULL) {
            Q.push(currentNode->left);
        }
        if (currentNode->right != NULL) {
            Q.push(currentNode->right);
        }
        Q.pop();
    }
}

bool chckIsHeap(vector<int> &a)
{
	for (int i = 0; i < a.size() / 2; i++)
	{
		if (!(a[i] > a[2*i + 1] && a[i] > a[2*i + 2]))  {
			return false;
		}
	}
	return true;
}

void Breadth_First_Search(BT *root)
{
    if (root == NULL) return;

    queue<BT*> Q;
    Q.push(root);
    while (!Q.empty()) {
        BT *currentNode = Q.front();
        cout << currentNode->data << " ";
        if (currentNode->left != NULL) {
            Q.push(currentNode->left);
        }
        if (currentNode->right != NULL) {
            Q.push(currentNode->right);
        }
        Q.pop();
    }
}

int main()
{
    vector<int> a{1, 2, 3, 4, 5, 6};
    BST* bst = NULL;

    for (int i = 0; i < a.size(); i++)
        bst = Insert(bst, a[i]);

	vector<int> fromH{50, 30, 15, 19, 20, 10, 5, 2};

//	cout << chckIsHeap(fromH);
    cout << isBinarySearchTree(a, bst);

}

