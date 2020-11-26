#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double minSum = 999999999;
int r, b;

vector<int> rX, rY, bX, bY;

void visitNumber(int point, char color, vector<int> ocB, vector<int> ocR, double sum){

    if (color == 'b'){
        ocB.push_back(point);
    }
    else{
        ocR.push_back(point);
    }
    if (ocR.size() == rX.size() && ocB.size() == bX.size()){
        minSum = min(sum, minSum);
        cout <<"SUM " <<sum <<endl;
        return;
    }
    if (color == 'b'){
        for (int i = 0; i < rX.size(); i++){
            bool Free = true;
            for(int j = 0; j < ocR.size(); j ++){
                if (ocR[j] == i){
                    Free = false;
                }
                break;
            }
            if (!Free){
                continue;
            }
            sum += sqrt((bX[point]-rX[i])*(bX[point]-rX[i]) + (bY[point]-rY[i])*(bY[point]-rY[i]));
            visitNumber(i, 'r', ocB, ocR, sum);
        }
    }
    else{
        for (int i = 0; i < bX.size(); i++){
            bool Free = true;
            for(int j = 0; j < ocB.size(); j ++){
                if (ocB[j] == i){
                    Free = false;
                }
                break;
            }
            if (!Free){
                continue;
            }
            //sum += sqrt((rX[point]-bX[i])*(rX[point]-bX[i]) + (rY[point]-bY[i])*(rY[point]-bY[i]));
            visitNumber(i, 'b', ocB, ocR, sum);
        }
    }
}

int main(){

    cin >>r;
    b = r;
    for (int i = 0; i < r; i++){
        int x, y;
        cin >>x >>y;
        rX.push_back(x);
        rY.push_back(y);
    }

    for (int i = 0; i < b; i++){
        int x, y;
        cin >>x >>y;
        bX.push_back(x);
        bY.push_back(y);
    }

    vector<int> ocB, ocR;
    visitNumber(0, 'b', ocB, ocR, 0.0);

    cout <<minSum;
}
