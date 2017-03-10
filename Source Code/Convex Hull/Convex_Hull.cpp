#include <iostream>
#include <fstream>

using namespace std;

void readFile(int *x, int *y);
int data_number;

int main()
{
    int x_coordinate[100] = {0};
    int y_coordinate[100] = {0};

    readFile(x_coordinate, y_coordinate);

    for (int i = 0; i < data_number; ++i) {
        cout << x_coordinate[i] << " " << y_coordinate[i] << endl;
    }


    cout << endl;
    for (int i = 0; i < data_number; ++i) {
        if (x_coordinate[i]) {
            cout << x_coordinate[i];
            break;
        }
    }


}

void readFile(int *x, int *y)
{
    data_number = 0;
    ifstream inFile("Convex_Hull_Data.txt");
    while (inFile >> x[data_number] >> y[data_number]) {
        ++data_number;
    }

}
