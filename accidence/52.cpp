#include<iostream>

using namespace std;

int M, N, k;
int i, j;
char map[21][21];
int map1[21][21];
int x, y;
int die[1001];

int main(){
    cin >> M >> N;
    for(i = 1; i <= M; i++){
        for(j = 1; j <= N; j++){
            cin >> map[i][j];
            if(map[i][j] == '#'){
                map1[i][j] = 2;
            }else{
                map1[i][j] = -100;
            }
        }
    }
    // cout << "-------" << endl;
    // for(i = 1; i <= M; i++){
    //     for(j = 1; j <= N; j++){
    //         cout << map1[i][j];
    //     }  
    //     cout << endl;
    // }

    cin >> k;
    for(i = 0; i < k; i++){
        cin >> x >> y;
        x++;
        y++;
        int die1 = 0;
        if(map1[x][y] >= 1){
            die1++;
            map1[x][y] -= 2;
        }
        if(map1[x - 1][y] == 1){
            die1++;
            map1[x - 1][y] -= 1;
        }else if(map1[x - 1][y] == 2){
            map1[x - 1][y] -= 1;
        }
        if(map1[x + 1][y] == 1){
            die1++;
            map1[x + 1][y] -= 1;
        }else if(map1[x + 1][y] == 2){
            map1[x + 1][y] -= 1;
        }
        if(map1[x][y + 1] == 1){
            die1++;
            map1[x][y + 1] -= 1;
        }else if(map1[x][y + 1] == 2){
            map1[x][y + 1] -= 1;
        }
        if(map1[x][y - 1] == 1){
            die1++;
            map1[x][y - 1] -= 1;
        }else if(map1[x][y - 1] == 2){
            map1[x][y - 1] -= 1;
        }
        die[i] = die1;
    }
    for(i = 0; i < k; i++){
        cout << die[i] << endl;
    }
    return 0;
}