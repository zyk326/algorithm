#include<iostream>
#define MaxSize 1001

using namespace std;

int M, N;
int numb[MaxSize][MaxSize];
int buf, up, down, leftt, rightt;
bool flag = false;

void init(){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> numb[i][j];
        }
    }
}

int main(){
    cin >> M >> N;
    init();

    for(int i = 1; i < M - 1; i++){
        for(int j = 1; j < N - 1; j++){
            buf = numb[i][j];
            up = numb[i - 1][j];
            down = numb[i + 1][j];
            leftt = numb[i][j - 1];
            rightt = numb[i][j + 1];
            if(buf > up && buf > down && buf > leftt && buf > rightt){
                if(!flag){
                    flag = true;
                }
                cout << buf << " " << i + 1 << " " << j + 1 << endl;
            }
        }
    }
    if(!flag){
        cout << "None " << M << " " << N;
    }
    return 0;
}