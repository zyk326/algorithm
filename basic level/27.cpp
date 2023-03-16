#include<iostream>
#include<iomanip>

using namespace std;

int N;
int point = 1;
int i, j, k;
int maps[11][11];

int main(){
    cin >> N;
    for(i = 0; i < N / 2; i++){ //圈数
        for(j = 0; j < 4; j++){ //段数
            for(k = 0; k < N - i * 2 - 1; k++){
                if(j == 0){
                    maps[i][k + i] = point++;
                }else if(j == 1){
                    maps[k + i][N - i - 1] = point++;
                }else if(j == 2){
                    maps[N - i - 1][N - k - i - 1] = point++;
                }else if(j == 3){
                    maps[N - 1 - k - i][i] = point++;
                }
            }
        }
    }
    if(N % 2 ==1){
        maps[N / 2][N / 2] = point;
    }
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            cout << setw(3) << setfill(' ') << maps[i][j];
        }
        cout << endl;
    }
    return 0;
}