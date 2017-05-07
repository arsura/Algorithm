// Postman's sort
// SIWAKORN RUENRIT
// 4-27-2017

#include <iostream>
#include <vector>

using namespace std;

// 5915 / 1 % 10 = 5
// 5915 / 10 % 10 = 1
// 5915 / 100 % 10 = 9
// 5915 / 1000 % 10 = 5

 // (1 -> 10 -> 100 -> 1000) = exp , for Radix
 // reverse for Postman's

// 1. find max number
// 2. while max_number / exp > 0

bool sortIsCollect(vector<int> a)
{
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;

}

void bucket_print(vector<vector<int> > &bucket)
{
    cout << endl;
    cout << "========================================== " << endl;
    for (int i = 0; i < bucket.size(); ++i) {
        for (int j = 0; j < bucket[i].size(); ++j) {
            cout << bucket[i][j] <<  " ";
        }
        cout << endl;
    }
    cout << "========================================== " << endl;
}

void vector_print(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
    cout << endl;
}

vector<int> bucket_to_array(vector<vector<int> > &bucket)
{
    vector<int> a;
    for (int i = 0; i < bucket.size(); ++i) {
        for (int j = 0; j < bucket[i].size(); ++j) {
            a.push_back(bucket[i][j]);

        }
        bucket[i].erase(bucket[i].begin(), bucket[i].end());
    }
    return a;
}

vector<int> fooHelper(vector<int> &a, int exp)
{
    int value;
    int DuplicateCount = 0;
    vector<vector<int> > bucket_temp(10);
    vector<int> helper;

    if (exp > 0) {
        for (int i = 0; i < a.size(); i++) {
            value = a[i] / exp % 10;
            bucket_temp[value].push_back(a[i]);
        }

        cout << "exp: " << endl;
        bucket_print(bucket_temp);

        for (int i = 0; i < bucket_temp.size(); ++i) {
            if (bucket_temp[i].size() > 1) {
                a = bucket_temp[i];
                helper = fooHelper(a, exp/10);
                bucket_temp[i] = helper;
            }
        }

        bucket_print(bucket_temp);
        helper = bucket_to_array(bucket_temp);
        return helper;
    }
    else {
        // have duplicate element
        return a;
    }
}

vector<int> foo(vector<vector<int> > &bucket, vector<int> &a, int exp)
{
//  first digit to bucket --------------------------------
    int value;

    vector_print(a);

    for (int i = 0; i < a.size(); i++) {
        value = a[i] / exp % 10;
        bucket[value].push_back(a[i]);
    }
    exp /= 10;

    bucket_print(bucket);

//  first digit to bucket --------------------------------

    for (int i = 0; i < bucket.size(); i++) {
        if (bucket[i].size() > 1) {
            a = bucket[i];
            bucket[i] = fooHelper(a, exp);
        }
    }

    vector<int> helper;
    bucket_print(bucket);
    helper = bucket_to_array(bucket);
    return helper;
}

int max_value(vector<int> &a)
{
    int Max = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (Max < a[i]) Max = a[i];
    }
    return Max;
}

int max_exp(int Max)
{
    int exp = 1;
    while (Max / exp > 0) {
        exp *= 10;
    }
    exp /= 10;
    return exp;
}

int main()
{
    vector<int> a{10, 50, 20, 11, 90, 111, 325, 10};
    vector<vector<int> > bucket(10);

    int max_number = max_value(a);
    int exp = max_exp(max_number);

    a = foo(bucket, a, exp);

    vector_print(a);
    cout << sortIsCollect(a);
}
