#include<iostream>

using namespace std;

int N;
int point;
int i, j;
string str;

bool deal(string aa, int len){
    int kk = 0;
    while(kk < len - 1){
        if(aa[kk] != aa[len - 1]){
            return false;
        }
        kk++;
        len--;
    }
    return true;
}

int main(){
    getline(cin, str);
    N = str.length();
    string buf;
    for(i = 0; i < N; i++){
        for(j = i; j < N; j++){
            if(deal(str.substr(i, 1 + j - i), 1 + j - i)){
                point = point < 1 + j - i ? 1 + j - i : point;
            }
        }
    }
    cout << point;
    return 0;
}