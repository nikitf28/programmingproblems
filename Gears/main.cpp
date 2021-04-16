#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

struct point{
    int x = 0, y = 0;
    int minX = 999999, minY = 999999, maxX = 0, maxY = 0;
};

point findCenter(vector<vector<short> > &data, int width, int height){
    point p;
    int line = height / 2;
    int col = width / 2;
    cout <<line <<" " <<col <<endl;
    while (data[line - 1][col] == 0){
        line--;
    }
    while (data[line+1][col] == 0){
        for (int i = col; i >= 0; i--){
            if (data[line][i] == 1){
                p.minX = min(p.minX, i + 1);
                break;
            }
        }
        for (int i = col; i < width; i++){
            if (data[line][i] == 1){
                p.maxX = max(p.maxX, i - 1);
                break;
            }
        }
        //cout <<p.minX <<" " <<p.maxX <<" " <<line <<" " <<col <<endl;
        line++;
    }
    p.x = (p.minX + p.maxX)/2;

    line = height / 2;
    col = width / 2;
    while (data[line][col - 1] == 0){
        col--;
    }
    while (data[line][col+1] == 0){
        for (int i = line; i >= 0; i--){
            if (data[i][col] == 1){
                p.minY = min(p.minY, i + 1);
                break;
            }
        }
        for (int i = line; i < height; i++){
            if (data[i][col] == 1){
                p.maxY = max(p.maxY, i - 1);
                break;
            }
        }
        col++;
    }
    p.y = (p.minY + p.maxY)/2;

    return p;

}

void paintCenter(vector<vector<short> > &data, point p){
    for (int i = p.minY; i <= p.maxY; i++){
        for (int j = p.minX; j <= p.maxX; j++){
            if (data[j][i] == 0){
                data[j][i] = 2;
            }
        }
    }

}

int findRecord(vector<vector<short> > &data, point p, int width, int height){
    int xr, yr, cx = p.x, cy = p.y;
    xr = max(cx - p.minX, p.maxX - cx) + 50;
    yr = max(cy - p.minY, p.maxY - cy) + 50;
    int R = max(xr, yr);
    int innerR = 0, outterR = 0;
    while (R < min(width/2, height/2)){
        //cout <<R <<endl;
        for (int x = -width/2 + 100; x < width/2 - 100; x++){

            if (R*R - x*x < 0){
                continue;
            }
            int y1 = sqrt(R*R - x*x);
            int y2 = -sqrt(R*R - x*x);
            //cout <<x + cx <<" " <<y1 + cy <<" " <<y2 + cy <<endl;
            //cout <<data[x + cx][y1 + cy] <<" " <<data[x + cx][y2 + cy] <<endl;
            if (data[x + cx][y1 + cy] == 0 || data[x + cx][y2 + cy] == 0){
                innerR = R;
                return innerR;
                cout <<R <<endl;
                break;
            }
        }
        R++;
    }
}

void drawCircle(vector<vector<short> > &data, int R, int width, point p){
    for (int x = -width/2 + 100; x < width/2 - 100; x++){

        if (R*R - x*x < 0){
            continue;
        }
        int y1 = sqrt(R*R - x*x);
        int y2 = -sqrt(R*R - x*x);
        //cout <<x + cx <<" " <<y1 + cy <<" " <<y2 + cy <<endl;
        //cout <<data[x + cx][y1 + cy] <<" " <<data[x + cx][y2 + cy] <<endl;
        int cx = p.x, cy = p.y;
        data[x + cx][y1 + cy] = 4;
        data[x + cx][y2 + cy] = 4;
    }
}

int main()
{
    vector<vector<short> > data;
    ifstream cin("input.txt");
    ofstream fout("output.txt");
    int a, n, m, b;
    cin >>a >>n >>m >>b;
    for (int i = 0; i < n; i++){
        string str;
        cin >>str;
        vector<short> data_line;
        for (int j = 0; j < m; j++){
            if (str[j] == '0'){
                data_line.push_back(0);
            }
            else{
                data_line.push_back(1);
            }
        }
        data.push_back(data_line);
    }
    point p = findCenter(data, m, n);
    paintCenter(data, p);
    int R = findRecord(data, p, n, m);
    drawCircle(data, R, n, p);
    cout <<p.minX <<" " <<p.maxX <<" " <<p.minY <<" " <<p.maxY <<endl;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            fout <<data[i][j];
        }
        fout <<endl;
    }
}
