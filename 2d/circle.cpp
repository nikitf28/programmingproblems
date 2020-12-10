#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream cin("C:/Users/nikit/Desktop/Задачи2/problem1/examples/input2.dat");
    //ofstream cout;
    //cout.open("output.txt");

    vector<vector<int>> matrix;

    int n, m;

    vector<int> row0;
    row0.resize(402, 0);
    matrix.push_back(row0);

    for (int i = 0; i < 400; i++){
        vector<int> row;
        for (int j = 0; j < 402; j++){
            int num;
            cin >>num;
            row.push_back(num);
        }
        matrix.push_back(row);
    }

    matrix.push_back(row0);

    int repl = 0;

    for (int i = 1; i < 401; i++){
        for (int j = 1; j < 401; j++){
            //cout <<matrix[i][j];
            if (matrix[i][j] == 1){
                int oneCount = 0;

                if (matrix[i-1][j-1] == 1){
                    oneCount++;
                }
                if (matrix[i-1][j] == 1){
                    oneCount++;
                }
                if (matrix[i-1][j+1] == 1){
                    oneCount++;
                }
                if (matrix[i][j-1] == 1){
                    oneCount++;
                }
                if (matrix[i][j+1] == 1){
                    oneCount++;
                }
                if (matrix[i+1][j-1] == 1){
                    oneCount++;
                }
                if (matrix[i+1][j] == 1){
                    oneCount++;
                }
                if (matrix[i+1][j+1] == 1){
                    oneCount++;
                }

                if (oneCount == 0){
                    repl++;
                    matrix[i][j] = 0;
                }
            }
        }
    }

    cout <<"REPLACED: " <<repl <<endl;

    int minX = 999, maxX = 0;
    int minY = 999, maxY = 0;

    for (int i = 1; i < 401; i++){
        bool start = false;
        int startX = 0, endX = 0;
        for (int j = 1; j < 401; j++){
            if (matrix[i][j] == 1 && !start){
                startX = j;
                start = true;
                //cout <<"ONE_1" <<endl;
                continue;
            }
            if (matrix[i][j] == 1 && start){
                endX = j;
                cout <<startX <<" " <<endX <<" Y: " <<i <<endl;
                minX = min(minX, startX);
                maxX = max(maxX, endX);
                //cout <<"TWO_1" <<endl;
                break;
            }
        }
        //cout <<minX <<" " <<maxX <<endl;
    }

    for (int i = 1; i < 401; i++){
        bool start = false;
        int startY = 0, endY = 0;
        for (int j = 1; j < 401; j++){
            if (matrix[j][i] == 1 && !start/* && matrix[j+1][i] != 1*/){
                startY = j;
                start = true;
                continue;
            }
            if (matrix[j][i] == 1 && start){
                endY = j;
                minY = min(minY, startY);
                maxY = max(maxY, endY);
                break;
            }
        }
    }

    cout <<"X: " << (minX + maxX) / 2 <<" Y: " <<(minY + maxY)/ 2 <<" R: " << (maxX - minX + 1)/2;

}
