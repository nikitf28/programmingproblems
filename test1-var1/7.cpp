#include <iostream>

using namespace std;

int main(){
    int totalCount = 0;
    for (int i = 0; i < 10000000; i++){
        int bin = i, oct = i;
        int countB = 0, countO = 0;


        while (bin > 0){
            int ostB = bin % 2;
            if (ostB == 1){
                countB++;
            }
            bin/=2;
        }

        while (oct > 0){
            int ostO = oct % 8;
            if (ostO == 1){
                countO++;
            }
            oct/=8;
        }

        if (countB == countO){
            cout <<i <<endl;
            totalCount++;
        }
    }

    cout <<"Total: " <<totalCount;
}
