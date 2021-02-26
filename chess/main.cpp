#include<iostream>
#include<vector>

using namespace std;

struct chessNum{
    int col = -1;
    int row = -1;
};

chessNum letterToNum(string letters){
    chessNum ans;
    if (letters.length() != 2){
        return ans;
    }
    char let1 = letters[0];
    char let2 = letters[1];
    if (let1 < 'A' || let1 > 'H' || let2 < '1' || let2 > '8'){
        return ans;
    }
    chessNum.col = let1 - 'A';
    chessNum.row = let2 - '1';
    return ans;
}

int main(){
    int num;
    vector<chessNum> figures;
    cout <<"Enter number of chess figures: ";
    cin >>num;

    for (int i = 0; i < num; i++){
        string letters;
        cin >>letters;
    }
}
