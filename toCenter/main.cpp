#include<iostream>
#include<vector>
#include<string>
#include <fstream>

using namespace std;

const int WIDTH = 100;

string cleanLine(string line){
    int b = 0, e = 0;
    for (int i = 0; i < line.length(); i++){
        if (line[i] != ' '){
            b = i;
        }
    }
    for (int i = line.length() - 1; i >= 0; i--){
        if (line[i] != ' '){
            e = i;
        }
    }

    string newLine = "";
    for (int i = e; i <= b; i++){
        newLine += line[i];
    }
    return newLine;
}

void centerText(vector<string> lines){
    ofstream cout("output.txt", ios::app);
    for (int j = 0; j < lines.size(); j++){
        string line = cleanLine(lines[j]);
        int lngth = WIDTH - line.length();
        //cout <<line.length();
        for (int i = 0; i < lngth/2; i++){
            line = " " + line;
        }
        cout <<line <<endl;
    }
}

void leftText(vector<string> lines){
    ofstream cout("output.txt", ios::app);
    for (int j = 0; j < lines.size(); j++){
        string line = cleanLine(lines[j]);
        cout <<line <<endl;
    }
}

void rightText(vector<string> lines){
    ofstream cout("output.txt", ios::app);
    for (int j = 0; j < lines.size(); j++){
        string line = cleanLine(lines[j]);
        int lngth = WIDTH - line.length();
        for (int i = 0; i < lngth; i++){
            line = " " + line;
        }
        cout <<line <<endl;
    }
}

int main(){
    setlocale(LC_ALL, "Russian");
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    string line;
    vector<string> lines;
    while (true){
        getline(cin, line);
        if (line == "end"){
            break;
        }

        lines.push_back(line);
    }

    centerText(lines);
    leftText(lines);
    rightText(lines);
}
