#include<iostream>

using namespace std;

int N, K;
int point = 0;
int i, j;
string str[101];

void sortstep(){
    for(j = 0; j < N - point - 1; j++){
        if(str[j] > str[j + 1]){
            swap(str[j], str[j + 1]);
        }
    }
}

int main(){
    cin >> N;
    cin >> K;
    for(i = 0; i < N; i++){
        cin >> str[i];
    }
    while(point < K){
        sortstep();
        point++;
    }
    for(i = 0; i < N; i++){
        cout << str[i] << endl;
    }
    return 0;
}