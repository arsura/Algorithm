#include <iostream>

using namespace std;

// Binary Search

int bsearch (int *a, int x, int left, int right)
{
    if (left > right) return -1;
    int middle = (right + left) / 2;

    if (a[middle] == x) {
        return 1;
    }
    if (x > a[middle]) {
        return bsearch(a, x, middle + 1, right);
    }
    else {
        return bsearch(a, x, left, middle - 1);
    }

}
// m = right - left + 1
// t(m) = t(m / 2) + O(1)

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << bsearch(a, 5, 0, 9);

}
