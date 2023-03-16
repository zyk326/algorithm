#include<iostream>
#include<vector>

#define MaxSize 100001

using namespace std;

int N;
double K, r;
int i, j;
vector <int> ori[MaxSize];
int mul[MaxSize];
int point, point2;
double ans = 0.0;

void DFS(int po, double power){
    if(mul[po]){
        ans += mul[po] * power;
    }else{
        for(int kk = 0; kk < ori[po].size(); kk++){
            DFS(ori[po][kk], power * r);
        }
    }
}

int main(){
    cin >> N >> K >> r;
    r = (100.0 - r) / 100.0;
    for(i = 0; i < N; i++){
        cin >> point;
        if(point == 0){
            cin >> point2;
            mul[i] = point2;
        }else{
            for(j = 0; j < point; j++){
                cin >> point2;
                ori[i].push_back(point2);
            }
        }
    }    
    DFS(0, K);
    cout << (int)ans;
    return 0;
}