#include<iostream>
#include<vector>

using namespace std;

int x1, y1, x2, y2;
vector<vector<int> > field;
int maxSum = 0;
vector<int> bestXWay, bestYWay;

int ds(int x, int y, int en, int sum, vector<vector<bool> > visited, vector<int> xWay, vector<int> yWay){
    en--;
    visited[x][y] = true;
    sum+=field[x][y];
    xWay.push_back(x);
    yWay.push_back(y);

    if (x == x2 && y == y2){
        if (maxSum < sum){
            maxSum = sum;
            bestXWay = xWay;
            bestYWay = yWay;
        }
    }

    if (x != 0 && visited[x-1][y]){
        ds(x-1, y, en, sum, visited, xWay, yWay);
    }
    if (y != 0 && visited[x][y-1]){
        ds(x, y-1, en, sum, visited, xWay, yWay);
    }
    if (x != 5 && visited[x+1][y]){
        ds(x+1, y, en, sum, visited, xWay, yWay);
    }
    if (y != 5 && visited[x][y+1]){
        ds(x, y+1, en, sum, visited, xWay, yWay);
    }

}

int main(){
    cout <<"Insert field values: " <<endl;

    vector<vector<bool> > v;
    v.resize(6);

    for (int i = 0; i < 6; i++){
        vector<int> b;
        vector<bool> vi;
        for (int j = 0; j < 6; j++){
            int a;
            cin >>a;
            b.push_back(a);
            vi.push_back(false);
        }
        field.push_back(b);
        v.push_back(vi);
    }

    cout <<"Insert A point" <<endl;
    cin >>x1 >>y1;

    cout <<"Insert B point" <<endl;
    cin >>x2 >>y2;


    vector<int> xWay, yWay;

    ds(x1, y1, 16, 0, v, xWay, yWay);

    cout <<"Buildings: " << maxSum <<endl;
    cout <<"Way: " <<endl;
    for (int i = 0; i < bestXWay.size(); i++){
        cout <<bestXWay[i] <<" " << bestYWay[i] <<endl;
    }

}
