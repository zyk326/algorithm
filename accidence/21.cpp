#include<iostream>
#define MaxSize 1001

using namespace std;

int T;
int ans[MaxSize]; // 1 true 0 false
int len;
int matrix[MaxSize][MaxSize];

void judge(){
    cin >> len;
    int i, j;
    for (i = 0; i < len; i++){
        for (j = 0; j < len; j++){
            cin >> matrix[i][j];
        }
    }
    for (i = 1; i < len; i++){
        for (j = 0; j < i; j++){
            if(matrix[i][j] != 0){
                ans[T] = 0;
                return;
            }
        } 
    }
    ans[T] = 1;
}

int main(){
    cin >> T;
    int n = T;
    while(T > 0){
        judge();
        T--;
    }
    T = n;
    while(T > 0){
        if(ans[T] == 1){
            cout << "YES" << endl;
        }else if(ans[T] == 0){
            cout << "NO" << endl;
        }
        T--;
    }
    return 0;
}