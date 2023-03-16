#include<iostream>

using namespace std;

int M, N;
int point;
int i, j;
int init[1001];
int lower, upper;
bool locklow;

bool deal(int de){
    if(de == 1){
        return false;
    }
    for(int ii = 2; ii * ii <= de; ii++){
        if(de % ii == 0){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> M >> N;
    for(i = 1; i <= 1000; i++){
        if(deal(i)){
            if(!locklow && i >= M){
                lower = point;
                locklow = true;
            }
            if(i <= N){
                upper = point;
            }
            init[point++] = i;
        }
    }
    M = lower;
    N = upper;
    // for(i = 0; i < point; i++){
    //     cout << init[i] << " ";
    // }
    // cout << M << " " << N << endl;
    point = 0;
    for(i = M; i <= N; i++){
        for(j = i + 1; j <= N; j++){
            for(int k = j + 1; k <= N; k++){
                if(deal(init[i] * init[j] + init[k]) && deal(init[j] * init[k] + init[i]) && deal(init[i] * init[k] + init[j])){
                    // cout << i << " " << j << " " << k << endl;
                    point++;
                }
            }
        }
    }
    cout << point;
    return 0;
}