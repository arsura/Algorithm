#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

int distance(int vx1, int vy1, int vx2, int vy2)
{
    return sqrt(pow((vx1 - vx2), 2) + pow((vy1 - vy2), 2));
}

int main()
{
    int vx[100];
    int vy[100];

    ifstream readfile("Closest_Pair_Data", ios::in);

    int no = 0;
    while (readfile >> vx[no] >> vy[no]) {
        ++no;
    }

    int minDistance = distance(vx[0], vy[0], vx[1], vy[1]);
    for (int i = 0; i < no; ++i) {
        for (int j = i + 1; j < no; ++j) {
            cout << vx[i] << " : " << vy[i] << " and " << vx[j] << " : " << vy[j] << " == " << distance(vx[i], vy[i], vx[j], vy[j]) << endl;
            if (minDistance >= distance(vx[i], vy[i], vx[j], vy[j])) {
                minDistance = distance(vx[i], vy[i], vx[j], vy[j]);
            }
        }
    }

    cout << endl;
    cout << minDistance << endl;


}
