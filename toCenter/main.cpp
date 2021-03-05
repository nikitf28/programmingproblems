#include<iostream>
#include<vector>

using namespace std;

int main(){
    string line;
    vector<string> lines;
    while (getline(line)){
        if (line == "end"){
            break;
        }
        int lngth = 80 - line.length();
        for (int i = 0; i < lngth/2; i++){
            line = " " + line + " ";
        }
        lines.push_back(line);
    }
    for (int i = 0; i < lines.size(); i++){
        cout <<lines[i] <<endl;
    }
}
