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

void paintCenter(vector<vector<short> > &data, point p){
    for (int i = p.minY; i <= p.maxY; i++){
        for (int j = p.minX; j <= p.maxX; j++){
            if (data[j][i] == 0){
                data[j][i] = 2;
            }
        }
    }

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

void drawCircle(vector<vector<short> > &data, int R, int width, point p, int color){
    for (int x = -width/2 + 100; x < width/2 - 100; x++){

        if (R*R - x*x < 0){
            continue;
        }
        int y1 = sqrt(R*R - x*x);
        int y2 = -sqrt(R*R - x*x);
        //cout <<x + cx <<" " <<y1 + cy <<" " <<y2 + cy <<endl;
        //cout <<data[x + cx][y1 + cy] <<" " <<data[x + cx][y2 + cy] <<endl;
        int cx = p.x, cy = p.y;
        data[x + cx][y1 + cy] = color;
        data[x + cx][y2 + cy] = color;
    }
}

void deleteRecord(vector<vector<short> > &data, int R1, int R2, point p, int width){
    for (int r = R1; r <= R2; r++){
        for (int x = -width/2 + 100; x < width/2 - 100; x++){
            if (r*r - x*x < 0){
                continue;
            }
            int y1 = sqrt(r*r - x*x);
            int y2 = -sqrt(r*r - x*x);
            int cx = p.x, cy = p.y;
            data[x + cx][y1 + cy] = 1;
            data[x + cx][y2 + cy] = 1;
            data[y1 + cy][x + cx] = 1;
            data[y2 + cy][x + cx] = 1;
        }
    }
}

void filter(vector<vector<short> > &data){
    for (int i = 1; i < data.size() - 1; i++){
        for (int j = 1; j < data[i].size() - 1; j++){
            if (data[i][j] == 0){
                bool noZeroes = true;
                if (data[i + 1][j] == 0) noZeroes = false;
                if (data[i - 1][j] == 0) noZeroes = false;
                if (data[i][j + 1] == 0) noZeroes = false;
                if (data[i][j - 1] == 0) noZeroes = false;
                if (noZeroes){
                    data[i][j] = 1;
                }
            }
        }
    }
}

void burnData(vector<vector<short> > &data, int R1, int R2, point p, int width, string toWrite){
    for (int r = R1; r <= R2; r++){
        for (int x = -width/2 + 100; x < width/2 - 100; x++){
            if (r*r - x*x < 0){
                continue;
            }
            int y1 = sqrt(r*r - x*x);
            int y2 = -sqrt(r*r - x*x);
            int angle1 = abs(acos(y1*1.0/x) * 180.0 / PI);
            int angle2 = abs(acos(y2*1.0/x) * 180.0 / PI);
            if (x >= 0){
                if (y1 >= 0){
                    angle1 = angle1;
                }
                else{
                    angle1  = 360 - angle1;
                }
                if (y2 >= 0){
                    angle2 = angle2;
                }
                else{
                    angle2 = 360 - angle2;
                }
            }
            else{
                if (y1 >= 0){
                    angle1 = 180 -  angle1;
                }
                else{
                    angle1 = 180 + angle1;
                }
                if (y2 >= 0){
                    angle2 = 180 -  angle2;
                }
                else{
                    angle2 =  180 + angle1;
                }
            }
            int write1 = 0, write2 = 0;
            int index1 = toWrite.length() * angle1 * 1.0 / 360, index2 = toWrite.length() * angle2 * 1.0 / 360;
            if (angle1 < 0 || angle1 >= 360 || angle1 < 0 || angle1 >= 360){
                continue;
            }
            //cout <<index1 <<" " <<index2 <<" " <<angle1 <<" " <<angle2 <<endl;
            if (toWrite[index1] == '0'){
                write1 = 1;
            }
            if (toWrite[index2] == '0'){
                write2 = 1;
            }

            int cx = p.x, cy = p.y;
            data[x + cx][y1 + cy] = write1;
            data[x + cx][y2 + cy] = write2;
        }
    }
}

int main()
{
    vector<vector<short> > data;
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    string toWrite = "10101010101010";
    int a, n, m, b;
    fin >>a >>n >>m >>b;
    for (int i = 0; i < n; i++){
        string str;
        fin >>str;
        //cout <<str;
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
    radiuses r = findRecord(data, p, n, m);
    //drawCircle(data, r.inner, n, p, 4);
    //drawCircle(data, r.outter, n, p, 5);
    deleteRecord(data, r.inner, r.outter, p, n);
    cout <<endl <<"Radiuses: " <<r.inner <<" " <<r.outter <<endl;
    filter(data);
    burnData(data, r.inner, r.outter, p, n, toWrite);
    filter(data);
    //cout <<p.minX <<" " <<p.maxX <<" " <<p.minY <<" " <<p.maxY <<endl;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            fout <<data[i][j];
        }
        fout <<endl;
    }
}
