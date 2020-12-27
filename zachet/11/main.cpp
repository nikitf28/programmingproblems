#include<iostream>
#include<vector>

using namespace std;

int x1, y1, x2, y2;
vector<vector<int> > field;
int maxSum = 0;
vector<int> bestXWay, bestYWay, degr;

int checkDed(int trun, int tr0){
        if (tr0 - trun == -90){
            return 90;
        }

        if (tr0 - trun == -180){
            return 180;
        }

        if (tr0 - trun == -270){
            return -90;
        }

        if (tr0 - trun == 0){
            return 0;
        }

        if (tr0 - trun == 90){
            return -90;
        }

        if (tr0 - trun == 180){
            return -180;
        }

        if (tr0 - trun == 270){
            return 90;
        }
        return -1;
}

int ds(int x, int y, int en, int sum, vector<vector<bool> > visited, vector<int> xWay, vector<int> yWay, vector<int> deg){
    en--;
    //cout <<"SIZE: " <<visited.size() <<" " <<visited[x].size() <<endl;

    //cout <<x <<" " <<y <<endl;

    //visited[x][y] = true;
    sum+=field[x][y];
    xWay.push_back(x);
    yWay.push_back(y);

    if (x == x2 && y == y2){
        if (maxSum < sum){
            maxSum = sum;
            bestXWay = xWay;
            bestYWay = yWay;
            degr = deg;
        }
        //cout <<"way finished" <<endl;
        return 2;
    }

    if (en == 0){
        //cout <<"Energy is " <<en <<endl;
        return -1;
    }

    if (x != 0 && !visited[x-1][y]){
        visited[x-1][y] = true;
        int turn = 0;
        deg.push_back(checkDed(turn, deg[deg.size() - 1]));
        int res = ds(x-1, y, en, sum, visited, xWay, yWay, deg);
    }
    if (y != 0 && !visited[x][y-1]){
        visited[x][y-1] = true;
        int turn = -90;
        deg.push_back(checkDed(turn, deg[deg.size() - 1]));
        int res = ds(x, y-1, en, sum, visited, xWay, yWay, deg);
    }
    if (x != 5 && !visited[x+1][y]){
        visited[x+1][y] = true;
        int turn = 180;
        deg.push_back(checkDed(turn, deg[deg.size() - 1]));
        int res = ds(x+1, y, en, sum, visited, xWay, yWay, deg);
    }
    if (y != 5 && !visited[x][y+1]){
        visited[x][y+1] = true;
        int turn = 90;
        deg.push_back(checkDed(turn, deg[deg.size() - 1]));
        int res = ds(x, y+1, en, sum, visited, xWay, yWay, deg);
    }

}

int main(){
    cout <<"Insert field values: " <<endl;

    vector<vector<bool> > v;

    for (int i = 0; i < 6; i++){
        vector<int> b;
        vector<bool> vi;
        vi.resize(6);
        for (int j = 0; j < 6; j++){
            int a;
            cin >>a;
            b.push_back(a);
        }
        field.push_back(b);
        v.push_back(vi);
    }

    cout <<"SIZE: " <<v.size() <<" " <<v[0].size() <<endl;

    cout <<"Insert A point" <<endl;
    cin >>x1 >>y1;

    cout <<"Insert B point" <<endl;
    cin >>x2 >>y2;


    vector<int> xWay, yWay;

    degr.push_back(0);

    v[x1][y1] = true;
    ds(x1, y1, 17, 0, v, xWay, yWay, degr);


    cout <<endl <<endl <<endl <<"====================================" <<endl <<endl;

    cout <<"Buildings: " << maxSum <<endl;
    cout <<"Way: " <<endl;
    for (int i = 0; i < bestXWay.size(); i++){
        cout <<i+1 <<". " <<bestXWay[i] <<" " << bestYWay[i]/* <<" " <<degr[i] <<" grad"*/ <<endl;
    }

}
