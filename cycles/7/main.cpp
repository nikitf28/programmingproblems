#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long double e, x = 1, oldSin;
    cout << "Insert ebselent: " <<endl;
    while (!(cin >> e)){
            cout << "error\n";
            cin.clear();
            fflush(stdin);
    }


    cout <<x <<" " <<sin(x)/x <<endl;
    oldSin = sin(x)/x;
    x/=2.0;
    cout <<x <<" " <<sin(x)/x <<endl;
    while (abs(oldSin - sin(x)/x) > e){
        oldSin = sin(x)/x;
        x/=2.0;
        cout <<x <<" " <<fixed <<sin(x)/x <<endl;
    }
}
