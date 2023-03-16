#include<iostream>

using namespace std;

int N;
int point;
int i, j;
int peo[1001];
int maxc;

int main(){
    cin >> N;
    for(int ii = 0; ii < N; ii++){
        scanf("%d-%d", &i, &j);
        cin >> j;
        peo[i] += j;  
    }
    for(i = 0; i < 1001; i++){
        if(peo[i] > peo[maxc]){
            maxc = i;
        }
    }
    cout << maxc << " " << peo[maxc];
    return 0;
}