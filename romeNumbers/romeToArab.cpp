#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string>

int romeToArab(char rome){
    if (rome == 'I'){
        return 1;
    }
    if (rome == 'V'){
        return 5;
    }
    if (rome == 'X'){
        return 10;
    }
    if (rome == 'L'){
        return 50;
    }
    if (rome == 'C'){
        return 100;
    }
    if (rome == 'D'){
        return 500;
    }
    if (rome == 'M'){
        return 1000;
    }
    return  0;
}

bool validateRome(string rome){
    int same = 1;
    char sameC = rome[0];
    
    for (int i = 1; i < rome.length(); i++){
        if (sameC == rome[i]){
            same++;
        }
        else{
            same = 1;
            sameC = rome[i];
        }
    
    
        if (same > 1){
            if (same > 3 && isTem(sameC)){
                return false;
            }    
            if (same == 1 && !isTem(sameC)){
                return false;
            }
        }
    }
    return true;
}

bool isTen(char c){
    if (c == 'I' || c == 'X' || c == 'C' || c == 'M'){
        return true;    
    }    
}

int main(){
    bool F = true;
    while (F){
        string romeNumber;
        cin >>romeNumber;
        for (int i = 0; i < romeNumber.length(); i++){
            if (romeNumber[i] != 'I' and romeNumber[i] != 'V' and romeNumber[i] != 'X' and romeNumber[i] != 'L' and romeNumber[i] != 'C' and 
            romeNumber[i] != 'D' and romeNumber[i] != 'M'){
                cout <<"wrong characters!" <<endl;
                break;
            }
            if i == romeNumber.length() - 1{
                F = false;    
            }
            
        }
        if (F){
            if(validateRome(romeNumber)) {
                break;
            }  
            else{
                F = true;
            }
        }
        
    }
    
    int arabNumber = 0;
    for (int i = 0; i < romeNumber.length(); i--){
        int n1 = romeToArab(romeNumber[i]);
        int n2 = romeToArab(romeNumber[i+1]);
        if (n1 >= n2){
            arabNumber += n1;
            continue;
        }
        if (n2 / n1 == 10 && isTen(n1) && isTen(n2)){
            arabNumber += n2 - n1;
            continue;
        }
        cout <<"Wrong number!";
        return 0;
    }
}

