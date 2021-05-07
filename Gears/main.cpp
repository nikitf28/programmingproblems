#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

#define PI 3.14159265

using namespace std;

struct point{
    int x = 0, y = 0;
    int minX = 999999, minY = 999999, maxX = 0, maxY = 0;
};

struct radiuses{
    int inner = 0;
    int outter = 0;
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

radiuses findRecord(vector<vector<short> > &data, point p, int width, int height){
    int xr, yr, cx = p.x, cy = p.y;
    xr = max(cx - p.minX, p.maxX - cx) + 50;
    yr = max(cy - p.minY, p.maxY - cy) + 50;
    int R = max(xr, yr);
    int innerR = 0, outterR = 0;
    bool innerF = true;
    while (R < min(width/2, height/2)){
        //cout <<R <<endl;
        bool noZero = true;
        for (int x = -width/2 + 100; x < width/2 - 100; x++){
            if (R*R - x*x < 0){
                continue;
            }
            int y1 = sqrt(R*R - x*x);
            int y2 = -sqrt(R*R - x*x);
            //cout <<x + cx <<" " <<y1 + cy <<" " <<y2 + cy <<endl;
            //cout <<data[x + cx][y1 + cy] <<" " <<data[x + cx][y2 + cy] <<endl;
            if (innerF){
                if (data[x + cx][y1 + cy] == 0 || data[x + cx][y2 + cy] == 0){
                    innerR = R;
                    innerF = false;
                    continue;
                }
            }
            else{
                if (data[x + cx][y1 + cy] == 0 || data[x + cx][y2 + cy] == 0){
                    noZero = false;
                }
            }
        }
        if (noZero && !innerF){
            outterR = R;
            break;
        }
        R++;
    }
    radiuses r;
    r.inner = innerR;
    r.outter = outterR;
    return r;
}

void burnData2(vector<vector<short> > &data, int R1, int R2, point p, int width, int height, string toWrite){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int x = j - p.x;
            int y = p.y - i;
            int r = sqrt(x*x + y*y);
            //cout <<x <<" " <<y <<" "  <<r <<endl;
            if (r >= R1 && r <= R2){
                int angle = atan2(y, x) * 180.0 / PI;
                if (angle < 0){
                    angle += 360;
                }
                //cout <<angle <<endl;
                int index = toWrite.length() * angle * 1.0 / 360;
                int write = 0;
                if (toWrite[index] == '0'){
                    write = 1;
                }
                int cx = p.x, cy = p.y;
                data[i][j] = write;

            }
        }
    }
}


int main()
{
    vector<vector<short> > data;
    ifstream cin("input.txt");
    ofstream fout("output.txt");
    string toWrite = "10110010100101111110000";
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
    //paintCenter(data, p);
    radiuses r = findRecord(data, p, n, m);
    cout <<endl <<"Radiuses: " <<r.inner <<" " <<r.outter <<endl;
    burnData2(data, r.inner, r.outter, p, n, m, "0");
    burnData2(data, r.inner, r.outter, p, n, m, toWrite);
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            fout <<data[i][j];
        }
        fout <<endl;
    }
}
