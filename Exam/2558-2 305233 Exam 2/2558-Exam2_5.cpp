#include <iostream>

// 2558-Exam2_5

using namespace std;

int power(int x, int n)
{
    if (n == 0) return 1;
    else {
        return x * power(x, n - 1);
    }
}

int main()
{
    int n = 2;
    int x = 10;
    int a[] = {5, 3, 2, 1, 4, 5};
    int p = 0;

    for (int i = n; i >=0; i--) {
        p += a[i] * power(x, i);
    }

    cout << p << endl;

}
