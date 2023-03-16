#include<iostream>

using namespace std;

int L, K;
string N;
int point;
int i, j;

bool deal(string bb){
    int de = atoi(bb.c_str());
    if(de == 1){
        return false;
    }
    for(i = 2; i * i <= de; i++){
        if(de % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> L >> K >> N;
    N = N.substr(0, L);
    while(point + K <= L){
        string buf = N.substr(point, K);
        if(deal(buf)){
            cout << buf;
            break;
        }
        point++;
    }
    if(point + K > L){
        cout << "404";
    }
    return 0;
}