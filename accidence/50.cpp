#include<iostream>

using namespace std;

char ch;
int N;
string map[101], map1[101];
int i, j;
string buf;

bool same(){
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(map1[i][j] != map[i][j]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    cin >> ch >> N;
    // cout << N << endl;
    getline(cin, buf);
    for(i = 0; i < N; i++){
        getline(cin, map[i]);
        for(j = 0; j < N; j++){
            if(map[i][j] == '@'){
                map[i][j] = ch;
            }
        }
        map1[i] = map[i];
    }

    for(i = 0; i < N / 2; i++){
        string buf = map[i];
        map[i] = map[N - i - 1];
        map[N - i - 1] = buf;
    }

    for(i = 0; i < N; i++){
        for(j = 0; j < N / 2; j++){
            char buf1 = map[i][j];
            map[i][j] = map[i][N - 1 - j];
            map[i][N - 1 - j] = buf1;
        }
        
    }

    if(same()){
        cout << "bu yong dao le" << endl;
    }

    for(i = 0; i < N; i++){
        cout << map[i] << endl;
    }

    return 0;
}