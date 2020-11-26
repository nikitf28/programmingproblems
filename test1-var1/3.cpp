#include <iostream>
#include <cmath>

//SNILS check

using namespace std;

bool validateSyntax(string number){
    if (number.length() != 14){
        return false;
    }
    if (number[3] != '-' || number[7] != '-' || number[11] != ' '){
        return false;
    }
    for (int i = 0; i < number.length(); i++){
        if (!(number[i] >= '0' && number[i] <= '9' || number[i] == '-' || number[i] == ' ')){

            return false;
        }
    }
    return true;
}

bool validateNumber(string number){
    int sum1 = (number[0]-'0')*9 + (number[1]-'0')*8 + (number[2]-'0')*7;
    int sum2 = (number[4]-'0')*6 + (number[5]-'0')*5 + (number[6]-'0')*4;
    int sum3 = (number[8]-'0')*3 + (number[9]-'0')*2 + number[10]-'0';
    int sum = sum1 + sum2 + sum3;
    int checkSum = (number[12]-'0')*10 + number[13]-'0';
    //cout <<checkSum <<endl;
    if (sum % 101 == checkSum){
        return true;
    }
    return false;
}

int genCheckSum(string number){
    int sum1 = (number[0]-'0')*9 + (number[1]-'0')*8 + (number[2]-'0')*7;
    int sum2 = (number[4]-'0')*6 + (number[5]-'0')*5 + (number[6]-'0')*4;
    int sum3 = (number[8]-'0')*3 + (number[9]-'0')*2 + number[10]-'0';
    int sum = sum1 + sum2 + sum3;
    return sum%101;
}

string formatSNILS(int num){
    string ans="";
    while (num > 0){
        ans = char(num%10+'0') + ans;
        num /= 10;
        if (ans.length() == 3 || ans.length() == 7){
        ans = '-' + ans;
        }
    }
    return ans;
}

int isEasy(int num){
    for (int i = 2; i < sqrt(num); i++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    /*cout <<"Inserts SNILS number: XXX-XXX-XXX XX" <<endl;
    string number;
    while (true){
        getline(cin, number);
        if (validateSyntax(number)){
            break;
        }
        else{
            cout <<"Wrong syntax! Try again.\n";
        }
    }

    if (validateNumber(number)){
        cout <<"SNILS is OK!";
    }
    else{
        cout <<"Wrong SNILS!";
    }*/

    int amm = 0;
    for (long long i = 100000000; i < 1000000000; i++){
      if (i % 10 == 2 || i % 10 == 4 || i % 10 == 5 || i % 10 == 6 || i % 10 == 8 || i % 10 == 0){
        continue;
      }
      if (isEasy(i)){
        amm++;
        string num = formatSNILS(i);
        cout <<num <<" " <<genCheckSum(num) <<endl;
      }
      if (amm > 100){
        return 0;
      }
    }

}
