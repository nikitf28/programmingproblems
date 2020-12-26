#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> row1, row2, toDo;

    for (int i = 0; i < 25; i++){
        int a;
        cin>>a;
        row1.push_back(a);
        row2.push_back(a);
    }
/*
    ¬ ситуации, кога уменьшение происходит на 1, все числа должны быть или чЄтными или нечЄтными (разница между числами кратна 2), дл€ гарантированного решени€ этой задачи. »наче может выйтти бесконечный цикл.
    ¬о втором случаее, разница между числами должны быть краина 4.
*/
/*
    bool doSmth = true;
    int cycles = 0;
    while (doSmth){
        cycles++;
        doSmth = false;
        toDo.resize(25, 0);
        for (int i = 1; i < 25 - 1; i++){
            if (row1[i-1] < row1[i] && row1[i+1] < row1[i]){
                toDo[i] = -1;
                doSmth = true;
            }
            if (row1[i-1] > row1[i] && row1[i+1] > row1[i]){
                toDo[i] = 1;
                doSmth = true;
            }
        }
        for (int i = 1; i < 25 - 1; i++){
            row1[i] += toDo[i];
        }

        for (int i = 0; i < 25; i++){
            cout <<row1[i] <<" ";
        }
        cout <<endl;
    }

    cout <<"Minutes1: " <<cycles;

*/
    bool doSmth = true;
    int cycles = 0;
    while (doSmth){
        cycles++;
        doSmth = false;
        toDo.resize(25, 0);
        for (int i = 1; i < 25 - 1; i++){
            if (row2[i-1] < row2[i] && row2[i+1] < row2[i]){
                toDo[i] = -2;
                doSmth = true;
            }
            if (row2[i-1] > row2[i] && row2[i+1] > row2[i]){
                toDo[i] = 2;
                doSmth = true;
            }
        }
        for (int i = 1; i < 25 - 1; i++){
            row2[i] += toDo[i];
        }

        for (int i = 0; i < 25; i++){
            cout <<row2[i] <<" ";
        }
        cout <<endl;
    }

    cout <<"Minutes1: " <<cycles;
}
