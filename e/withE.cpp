#include<iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

bool ifEasy(long long num){
    for (int i = 2; i < sqrt(num); i++){
        if (num % i == 0){
            return true;
        }
    }
    return false;
}

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

    for (int i = 9; i < e.length(); i++){
        string strNum = "";
        for (int j = i - 9; j <= i; j++){
            strNum += e[j];
        }
        cout <<i-8 <<". " <<strNum <<endl;
        long long num = stoll(strNum);
        if (!ifEasy(num)){
            cout <<"================" <<endl <<endl <<num;
            return 0;
        }
    }

}
