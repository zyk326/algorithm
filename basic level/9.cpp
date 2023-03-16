#include<iostream>

using namespace std;

int N;
int FS, SS;
int count = 0;

bool Su(int i){
    for(int j = 2; j * j <= i; j++){
        if(i % j == 0){
            return false;
        }
    }
    return true;
}

int getS(){
    int buf = SS + 1;
    for(int i = buf; i <= N; i++){
        if(Su(i)){
            return i;
        }
    }
    return N + 1;
}

int main(){
    // ruguo dangchu woneng zainuliyidian jiuyiding neng jiandaota
    cin >> N;
    FS = 2;
    SS = 3;
    while(SS <= N){
        if(SS - FS == 2){
            count++;
        }
        FS = SS;
        SS = getS();
    }
    cout << count;
    return 0;
}