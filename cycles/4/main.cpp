#include <iostream>

using namespace std;

int main()
{
    double k=-1, p=-1, r=-1, oldK;

    while (k < 0 || r < 0){
        cout <<"Credit Percent Profit\n";
        while (!(cin >> k)){
            cout << "error\n";
            cin.clear();
            k = -1;
            fflush(stdin);
            break;
        }
        while (!(cin >> p)){
            cout << "error\n";
            cin.clear();
            fflush(stdin);
            break;
        }
        while (!(cin >> r)){
            cout << "error\n";
            cin.clear();
            fflush(stdin);
            break;
        }
        if (k < 0 || r < 0){
            cout <<"Values should be positive!" <<endl;
        }
    }
    int i = 0;
    while (k > 0){
        oldK = k;
        k = k * ((p + 100) / 100.0);
        k -= r;
        i++;
        if (oldK <= k){
            cout <<"Impossible!";
            return 0;
        }
    }
    cout <<i <<" years";
}
