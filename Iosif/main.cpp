#include<iostream>
#include<queue>

using namespace std;

int goRound(int n, int distance){
    queue <int> line;
    for (int i = 1; i <= n; i++){
        line.push(i);
    }
    int steps = 0;
    while(line.size() > 1){
        //cout <<line.size() <<" size\n";
        int last = line.front();
        line.pop();
        steps++;
        if (steps != distance){
            line.push(last);
        }
        else{
            steps = 0;
        }
    }
    return line.back();;
}

int main(){
    for (int i = 1; i <= 1000; i++){
        cout <<i <<". " <<goRound(i, 2) <<endl;
    }
}
