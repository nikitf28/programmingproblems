#include <iostream>
#include <cmath>

using namespace std;

string decToBin(int dec){
    if (dec == 1){
        return "1";
    }
    else if (dec == 0){
        return "0";
    }
    else{
        string add = decToBin(dec/2);
        if (dec % 2 == 0){
            return add + "0";
        }
        else{
            return add + "1";
        }
    }
}

string anyDecToBin(int dec){
    string bin = decToBin(abs(dec));
    if (dec >= 0){
        bin = "0" + bin;
    }
    else{
        string newBin = "1";
        for (int i = 0; i < bin.length(); i++){
            if (bin[i] == '1'){
                newBin += "0";
            }
            else{
                newBin += "1";
            }
        }
        bin = newBin;
    }
    return bin;

}

int main(){
    int dec;
    cin >>dec;
    string bin = anyDecToBin(dec);

    cout <<bin;

}
