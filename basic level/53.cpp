#include<iostream>
#include<deque>
#include<numeric>

using namespace std;

int N, k, x;
int point = 1;
int i, j;
deque<int>di[100];//列优先

int main(){
    cin >> N >> k >> x;
    for(j = 0; j < N; j++){
        for(i = 0; i < N; i++){
            cin >> point;
            di[i].push_back(point);
        }
    }
    point = 1;
    for(i = 1; i < N; i += 2){
        if(point > k){
            point = 1;
        }
        for(j = 1; j <= point; j++){
            di[i].pop_back();
            di[i].push_front(x);
        }
        point++;
    }
    for(i = 0; i < N; i++){
        point = 0;
        for(j = 0; j < N; j++){
            point += di[j][i];
        }
        if(i == 0){
            cout << point;
        }else{
            cout << " " << point;
        }
    }
    // cout << endl;
    // for(i = 0; i < N; i++){
    //     for(j = 0; j < N; j++){
    //         cout << di[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}