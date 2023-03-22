#include<iostream>

#define MaxSize 550

using namespace std;

int V, E, K, N;
int point, point2;
int i, j;
int map[MaxSize][MaxSize];//我的map是从零开始的
int ans[MaxSize];

bool wayed(int color[], int rear, int col){
    for(int kk = 0; kk <= rear; kk++){
        if(color[kk] == col && map[kk + 1][rear + 2] == 1){
            return true;
        }
    }
    return false;
}

int deal(){
    int color[MaxSize];
    int load[MaxSize];
    int cnt = 0;
    fill(load, load + MaxSize, 0);
    for(int ii = 0; ii < V; ii++){
        cin >> color[ii];
    }
    for(int ii = 0; ii < V; ii++){
        if(!load[color[ii]]){
            load[color[ii]] = 1;
            cnt++;
        }else{
            if(wayed(color, ii - 1, color[ii])){
                return 0;
            }
        }
    }
    if(cnt != K)
        return 0;
    // cout << " -- " << cnt << endl;
    return 1;
}

int main(){
    cin >> V >> E >> K;
    fill(map[0], map[0] + MaxSize * MaxSize, 0);
    fill(ans, ans + MaxSize, 0);
    for(i = 0; i < E; i++){
        cin >> point >> point2;
        map[point][point2] = 1;
        map[point2][point] = 1;
    }
    cin >> N;
    for(i = 0; i < N; i++){
        ans[i] = deal();
    }
    for(i = 0; i < N; i++){
        if(ans[i] == 0){
            cout << "No" << endl;
        }else if(ans[i] == 1){
            cout << "Yes" << endl;
        }
    }
    return 0;
}