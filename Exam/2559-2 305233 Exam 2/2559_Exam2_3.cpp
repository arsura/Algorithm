#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 1000000

using namespace std;

bool hasMajorityElementBruteForce(int *a, int n)
{
    int Count = 0;
    for (int i = 0; i < n; ++i) {
        Count = 0;
        for (int j = 0; j < n; ++j) {
            if (a[i] == a[j]) {
                ++Count;
                if (Count > int(n / 2)) return true;
            }
        }
    }
    return false;
}

bool hasMajorityElementDecrease(int *a, int n)
{
    vector<int> arry(a, a + n);
    // if has 0 in array a -----------------
    int Count = 0;
    for (int i = 0; i < n; i++) {
        if (arry[i] == 0) Count++;
        if (Count > int(n / 2)) return true;
    }
    // -------------------------------------

    int temp;
    Count = 0;
    for (int j = 0; j < n; j++) {
        if (arry[j] != 0) {
            Count = 0;
            temp = arry[j];
//            for (int l = 0; l < n; l++) cout << a[l] << " ";
//            cout << endl;
            for (int k = 0; k < n; k++) {
                if (temp == arry[k]) {
                    ++Count;
                    arry[k] = 0;
                    if (Count > int(n / 2)) return true;
                }
            }
        }
    }

    return false;
}

bool hasMajorityElement3(int *a, int n)
{
    vector<int> arry(MAX_SIZE);
    for (int i = 0; i < n; ++i) {
        ++arry[a[i]];
        if (arry[a[i]] > int(n / 2)) return true;
    }
    return false;
}


int main()
{
//    int a[] = {7, 7, 8, 8, 7, 5, 8, 8, 8, 8, 8};
    int a[] = {1, 2, 5, 2, 9, 2, 2, 8, 1, 5, 7};
//    int a[] = {1, 2, 2, 2, 5};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "hasMajorityElement Brute-Force: " << hasMajorityElementBruteForce(a, n) << endl;
    cout << "hasMajorityElement Decrease and Conquer: " << hasMajorityElementDecrease(a, n)  << endl;
    cout << "hasMajorityElement3: " << hasMajorityElement3(a, n) << endl;

//    do {
//        for (int i = 0; i < n; ++i) cout << a[i] << " ";
//        cout << endl;
//        cout << "hasMajorityElement Brute-Force: " << hasMajorityElementBruteForce(a, n) << endl;
//        cout << "hasMajorityElement Decrease and Conquer: " << hasMajorityElementDecrease(a, n)  << endl;
//        cout << "hasMajorityElement3: " << hasMajorityElement3(a, n) << endl;
//        cout << endl;
//    } while (next_permutation(a, a + n));

}
