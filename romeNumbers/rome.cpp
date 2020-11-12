#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

string arabToRome(int digit, int pos){
    string n1, n5;
    if (pos == 0){
        n1 = "I";
        n5 = "V";
    }
    if (pos == 1){
        n1 = "X";
        n5 = "L";
    }
    if (pos == 2){
        n1 = "C";
        n5 = "D";
    }
    if (pos == 3){
        n1 = "M";
    }
    
    if (digit == 1){
        return <<n1;
    }
    
    if (digit == 2){
        return <<n1 + n1;
    }
    
    if (digit == 3){
        return <<n1 + n1 + n1;
    }
    
    if (digit == 4){
        return <<n1 + n5;
    }
    
    if (digit == 5){
        return <<n5;
    }
    
    if (digit == 6){
        return <<n5 + n1;
    }
    
    if (digit == 7){
        return <<n5 + n1 + n1;
    }
    
    if (digit == 8){
        return <<n5 + n1 + n1 + n1;
    }
    
    if (digit == 9){
        return <<n1 + n5;
    }
    return "";
}

int main()
{
    
    int number = -1;
    while (weight < 0){
        cout << "Insert arab number: " <<endl;
        while (!(cin >> weight)){
                cout << "Insert arab number: " <<endl;
                cin.clear();
                fflush(stdin);
        }
        if (number > 3999){
            cout <<"too big!";
            num = -1;
        }
    }
    
    int i = 0;
    string rome = "";
    while (number > 0){
        int digit = number % 10;
        rome = arabToRome(digit, i) + rome;
        i++;
        number /= 10;
    }
    cout <<rome;
}