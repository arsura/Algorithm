#include <iostream>
#include <vector>

// 2558-Exam3_2
// Summation Divide and Conquer

using namespace std;

int sum(int *a, int n)
{
    if (n == 0) return 0;
    else if (n == 1) return a[0];

    int mid = n / 2;
    int rsize = n - mid;
    int left_sum = sum(a, mid);
    int right_sum = sum(a + mid, rsize);
 //   cout << left_sum << " + " << right_sum << endl;
    return left_sum + right_sum;
}

int sum2(int *a, int left, int right)
{
    if (right - left == 0) return a[right];
    if (right - left == 1) return a[right] + a[left];

    if (right >= 2) {
        int middle = (right + left) / 2;
        int left_sum = sum2(a, left, middle);
        int right_sum = sum2(a, middle + 1, right);
//        cout << left_sum << " + " << right_sum << endl;
        return left_sum + right_sum;
    }
}


int main()
{
    int a[] = {5, 20, 10, 30, 50, 60, 1, 10 ,5};

    cout << sum(a, 9) << endl;

}
