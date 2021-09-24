#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Points {
    int x;
    int y;
};

int main() {
    ifstream fin;
    fin.open("granitsy-uchastka2.txt");
    vector<Points> points;

    int N;
    fin >>N;

    for (int i = 0; i < N; i++){
        Points point;
        fin >>point.x >>point.y;
        points.push_back(point);
    }

    int sum = 0;

    for (int i = 0; i < N -1; i++){
        sum += points[i].x * points[i+1].y;
    }
    sum += points[N - 1].x * points[0].y;

    for (int i = 0; i < N - 1; i++){
        sum -= points[i + 1].x * points[i].y;
    }

    sum -= points[0].x * points[N - 1].y;

    int result = abs(sum) / 2;
    cout <<result;
}
