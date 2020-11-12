#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    int pops[] = {1,2,5,10,20,50,100, 200, 1000};
    int weight = -1;
    while (weight < 0){
        cout << "Insert weight: " <<endl;
        while (!(cin >> weight)){
                cout << "Insert weight: " <<endl;
                cin.clear();
                fflush(stdin);
        }
    }
    int total = 0;
    for (int i = sizeof(pops)/sizeof(int)-1; i >= 0; i--){
        int m = weight / pops[i];
        weight = weight % pops[i];
        total += m;
        if (m > 0){
            cout << m << " x " <<pops[i] <<" gr"<<endl;
        }
    }
    cout <<"Total: " <<total;
}
