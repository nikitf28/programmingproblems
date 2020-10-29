#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double mile = 1.609344;
    int n;
    cout <<"Kilometres: ";
    cin >>n;
    cout <<"miles" <<setw(20) <<setfill(' ') <<"kilometres" <<setw(20) <<setfill(' ') <<endl;
    for (int i = 1; i <= n; i++){
        double mil, km;
        mil = i*1.0/mile;
        km = i;
        cout <<setprecision(4) <<km <<setw(20) <<setfill(' ')  <<setprecision(4) <<mil <<setw(20) <<setfill(' ')  <<endl;
    }
}
