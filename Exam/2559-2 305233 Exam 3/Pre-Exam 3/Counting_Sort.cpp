#include <iostream>

using namespace std;

// SIWAKORN RUENRIT
// 4-27-2017
// Counting Sort

// A = 9, 4, 10, 8, 2, 4
// find min and max of A , min = 2, max = 10
// create index arr, size = max - min + 1
//
//         2 3 4 5 6 7 8 9 10
// index = 1 0 2 0 0 0 1 1 1
// sum_i = 1 1 3 3 3 3 4 5 6
//
// pos   = 1 2 3 4 5 6
// lastA =         9
// lastA =     4   9
// lastA =     4   9 10
// lastA =     4 8 9 10
// lastA = 2   4 8 9 10
// lastA = 2 4 4 8 9 10

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {10, 50, 20, 11, 90, 111, 325, 10};
    int Min, Max;
    int size_of_arry = sizeof(a)/sizeof(a[0]);
    int size_of_index;
    int last_of_a[size_of_arry] = {0};

    // Find min max
    Min = Max = a[0];
    for (int i = 0; i < size_of_arry; i++) {
        if (Min > a[i]) Min = a[i];
        if (Max < a[i]) Max = a[i];
    }

    size_of_index = (Max - Min) + 1;
    int index[size_of_index] = {0};

    // Count
    for (int i = 0; i < size_of_arry; i++) {
        ++index[a[i] - Min];
    }

    // Sum Count
    for (int i = 0; i < size_of_index; i++)
        index[i + 1] = index[i] + index[i + 1];

    // Sorted
    for (int i = 0; i < size_of_arry; i++) {
        last_of_a[index[a[i] - Min] - 1] = a[i];
        --index[a[i] - Min];
    }

    print_array(last_of_a, size_of_arry);

}
