#include<iostream>
#include<queue>

using namespace std;

int N;
int point;
int i, j;
int cost;
priority_queue<int, vector<int>, greater<int> > piig;

int main(){
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> point;
        piig.push(point);
    }
    while(piig.size() > 1){
        i = piig.top();
        piig.pop();
        j = piig.top();
        piig.pop();
        piig.push(i + j);
        cost += i + j;
    }
    cout << cost;
    return 0;
}