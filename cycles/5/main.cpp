#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double mile = 1.609344;
    int milInt = 1;
    int n;
    cout <<"Kilometres: ";
    cin >>n;
    cout <<"miles" <<setw(25) <<setfill(' ') <<"kilometres" <<setw(20) <<setfill(' ') <<left <<endl;
    for (int i = 1; i <= n; i++){
        double mil, km;
        int kmInt = i;
        mil = kmInt*1.0/mile;
        if (milInt < mil){
            km = milInt * 1.0 * mile;
            cout <<fixed <<setprecision(4) <<double(milInt) <<setw(20) <<setfill(' ') <<left  <<setprecision(4) <<km <<setw(20) <<setfill(' ') <<left  <<endl;
            milInt++;
        }
        cout <<fixed <<setprecision(4) <<mil <<setw(20) <<setfill(' ') <<left  <<setprecision(4) <<double(kmInt) <<setw(20) <<setfill(' ') <<left  <<endl;
    }
}
