#include<iostream>
#include<vector>
#include<cstdlib>

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
    ans.col = let1 - 'A';
    ans.row = let2 - '1';
    return ans;
}

char numToChar(int n){
    return n + 'A';
}

void checkFerz(const int board[8][8], int row, int col){
    for (int i = col - 1; i >= 0; i--){
        if (board[row][i] == 1){
            cout <<numToChar(col)<<row+1 <<" <---> " <<numToChar(i)  <<row+1 <<endl;
            break;
        }
    }
    for (int j = row - 1; j >= 0; j--){
        if (board[j][col] == 1){
            cout <<numToChar(col)<<row+1 <<" <---> " <<numToChar(col)  <<j+1 <<endl;
            break;
        }
    }

    for (int i = col - 1, j = row-1; i >= 0 && j >= 0; i--, j--){
        if (board[j][i] == 1){
            cout <<numToChar(col)<<row+1 <<" <---> " <<numToChar(i)  <<j+1 <<endl;
            break;
        }
    }
    for (int i = col + 1, j = row-1; i < 8, j >= 0; i++, j--){
        if (board[j][i] == 1){
            cout <<numToChar(col)<<row+1 <<" <---> " <<numToChar(i)  <<j+1 <<endl;
            break;
        }
    }
}

int main(){
    int num;
    vector<chessNum> figures;
    cout <<"Enter number of chess figures: ";
    cin >>num;

    int board[8][8];
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            board[i][j] = 0;
        }
    }

    for (int i = 0; i < num; i++){
        string letters;
        cin >>letters;
        chessNum ferz = letterToNum(letters);
        board[ferz.row][ferz.col] = 1;
    }

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (board[i][j] == 1){
                //cout <<i <<" " <<j <<endl;
                checkFerz(board, i, j);
            }
        }
    }

}
