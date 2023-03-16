#include<iostream>
#include<queue>
#include<iomanip>

using namespace std;

int N;
double M;
queue <double> qd;
double money;

int main(){
    cin >> N >> M;
    int i = 0;
    while(i < N){
        cin >> money;
        qd.push(money);
        i++;
    }
    while(i > 0){
        money = qd.front();
        qd.pop();
        if(money < M){
            cout << "On Sale! " << setprecision(1) << fixed << money << endl;
        }
        i--;
    }
    return 0;
}