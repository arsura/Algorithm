#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

struct Point
{
    int x;
    int y;
};

double distance(Point point1, Point point2)
{
    return sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));
}

void minimumDistance(Point point[], int no)
{
    Point p1, p2;
    double minDistance = distance(point[0], point[1]);
    for (int i = 0; i < no; ++i) {
        for (int j = i + 1; j < no; ++j) {
            cout << point[i].x << " : " << point[i].y << " and " << point[j].x << " : " << point[j].y << " == " << distance(point[i], point[j]) << endl;
            if (minDistance >= distance(point[i], point[j])) {
                minDistance = distance(point[i], point[j]);
                p1 = point[i];
                p2 = point[j];
            }
        }
    }

    cout << "\n" << p1.x << " : " << p1.y << " and " << p2.x << " : " << p2.y << endl;
}

int main()
{
    Point point[100];

    ifstream readfile("Closest_Pair_Data.txt", ios::in);

    int no = 0;
    while (readfile >> point[no].x >> point[no].y) {
        ++no;
    }

    minimumDistance(point, no);

}
