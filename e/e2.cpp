#include<iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;


int main(){
    ifstream fin("e2mil.txt");
    string e, buffer;

    while (fin >> buffer){
        string filtered = "";
        for (int i = 0; i < buffer.length(); i++){
            if (buffer[i] >= '0' && buffer[i] <= '9'){
                filtered += buffer[i];
            }
        }
        e += filtered;
    }

    int factorial = 1;
    for (int i = 0; i < 5; i++){
        factorial*=(i+2);
        cout <<factorial <<endl;
        string strNum = "";
        for (int j = factorial - 1; j < factorial + 9; j++){
            strNum += e[j];
        }
        cout <<i+1 <<". " <<strNum <<endl;
    }
}
