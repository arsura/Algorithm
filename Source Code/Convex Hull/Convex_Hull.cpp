#include <iostream>
#include <fstream>

using namespace std;

struct Point
{
    int x;
    int y;
};

int data_number;

void readFile(Point *point)
{
    data_number = 0;
    ifstream inFile("Convex_Hull_Data.txt");
    while (inFile >> point[data_number].x >> point[data_number].y) {
        ++data_number;
    }
}

void Swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

int main()
{
    Point point[100];

    readFile(point);

    for (int i = 0; i < data_number; ++i) {
        cout << point[i].x << " " << point[i].y << endl;
    }

    int least_of_y = point[0].y;
    int least_of_y_index = 0;
    for (int i = 0; i < data_number; ++i) {
        if (point[i].y <= least_of_y) {
            if (point[i].y == least_of_y && point[i].x > point[least_of_y_index].x) {

            }
            else {
                least_of_y = point[i].y;
                least_of_y_index = i;
            }
        }
    }

    cout << "\n" << point[least_of_y_index].x << " " << point[least_of_y_index].y << endl;

    Swap(point[1], point[least_of_y_index]);

    cout << endl;
    for (int i = 0; i < data_number; ++i) {
        cout << point[i].x << " " << point[i].y << endl;
    }

}
