#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct figure{
    int minx = 99999;
    int miny = 99999;
    int maxx = 0;
    int maxy = 0;
    int peremiter = 0;
    int square = 0;
    int squareTaken = 0;
    int color;
};

void colorize(int** arr, int x, int y, figure &newFigure, int color, int xSize, int ySize){
    //cout <<"color: " <<color <<endl;
    arr[y][x] = color;
    newFigure.color = color;
    newFigure.square++;
    newFigure.minx = min(newFigure.minx, x);
    newFigure.miny = min(newFigure.miny, y);
    newFigure.maxx = max(newFigure.maxx, x);
    newFigure.maxy = max(newFigure.maxy, y);
    int nulls = 0;
    //cout <<x <<" " <<y <<endl;
    if (x > 0) if (arr[y][x - 1] == 0) nulls++;
    if (y > 0) if (arr[y - 1][x] == 0) nulls++;
    if (x < xSize - 1) if (arr[y][x + 1] == 0) nulls++;
    if (y < ySize - 1) if (arr[y + 1][x] == 0) nulls++;
    if (nulls != 0) newFigure.peremiter++;

    if (x > 0 && y > 0) if(arr[y-1][x-1] == 1) colorize(arr, x-1, y-1, newFigure, color, xSize, ySize);
    if (x < xSize - 1 && y < ySize - 1) if(arr[y+1][x+1] == 1) colorize(arr, x+1, y+1, newFigure, color, xSize, ySize);
    if (x < xSize - 1 && y > 0) if(arr[y+1][x-1] == 1) colorize(arr, x-1, y+1, newFigure, color, xSize, ySize);
    if (x > 0 && y < ySize - 1) if(arr[y-1][x+1] == 1) colorize(arr, x+1, y-1, newFigure, color, xSize, ySize);

    if (x > 0) if(arr[y][x-1] == 1) colorize(arr, x-1, y, newFigure, color, xSize, ySize);
    if (x < xSize) if(arr[y][x+1] == 1) colorize(arr, x+1, y, newFigure, color, xSize, ySize);
    if (y > 0) if(arr[y-1][x] == 1) colorize(arr, x, y-1, newFigure, color, xSize, ySize);
    if (y < ySize - 1) if(arr[y+1][x] == 1) colorize(arr, x, y+1, newFigure, color, xSize, ySize);
}

int main(){
    int circles = 0, squares = 0, triangles = 0, kalyaka = 0;
    vector<figure> figures;
    ifstream cin("input.dat");
    ofstream cf("output.dat");
    int arr[200][200];
    for (int i = 0; i < 200; i++){
        string str;
        cin >>str;
        for (int j = 0; j < str.length(); j++){
            if (str[j] == '0'){
                arr[i][j] = 0;
            }
            else{
                arr[i][j] = 1;
            }
        }
    }
    int** arr2 = new int*[200];
    for(int i = 0; i<200; i++)
    {
        arr2[i] = &arr[i][0];
    }

    int newColor = 1;
    for (int i = 0; i < 200; i++){
        for (int j = 0; j < 200; j++){
            if (arr[i][j] == 1){
                //cout <<i <<" " <<j <<endl;
                figure newFigure;
                newColor++;
                colorize(arr2, j, i, newFigure, newColor, 200, 200);
                figures.push_back(newFigure);
                cout <<"Color: " <<newFigure.color <<", square: " <<newFigure.square <<", peremiter: "
                <<newFigure.peremiter <<" minx, y, maxx, y " <<newFigure.minx <<" " <<newFigure.miny <<" "
                <<newFigure.maxx <<" " <<newFigure.maxy <<endl;
            }
            //cf <<arr[i][j] <<" ";
        }
        //cf <<endl;
    }

    for (int i = 0; i < figures.size(); i++){
        figure newFigure = figures[i];
        int square = newFigure.square;
        int perimetr = newFigure.peremiter;
        int sq2 = (newFigure.maxx - newFigure.minx + 1) * (newFigure.maxy - newFigure.miny + 1);

        //cout <<i+2 <<". " <<perimetr * 1.0 / square <<" " <<square*1.0/sq2;

        if (perimetr * 1.0 / square >= 0.8){
            kalyaka++;
            //cout <<" Kalyaka" <<endl;
        }
        else if (square == sq2){
            squares++;
            //cout <<" Squares" <<endl;
        }
        else if (square*1.0/sq2 >= 0.7 && square*1.0/sq2 <= 0.78){
            circles++;
            //cout <<" Circles" <<endl;
        }
        else{
            triangles++;
            //cout <<" Triangles" <<endl;
        }
    }


    cout <<"Circles: " <<circles <<"\nTriangles: " <<triangles <<"\nSquares: " <<squares <<"\nKalyaka: " <<kalyaka <<endl;

    for (int i = 0; i < 200; i++){
        for (int j = 0; j < 200; j++){
            cf <<arr[i][j] <<" ";
        }
        cf <<endl;
    }
}
