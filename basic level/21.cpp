#include<iostream>

using namespace std;

int N;
string ch;
string str;
int len;

void addStr(){
    if(len <= N){
        len = N - len;
        while(len > 0){
            str = ch + str;
            len--;
        }
    }
}

void subStr(){
    if(len == 0){
        cout << str;
    }else{
        cout << str.substr(len - N, N);
    }
}

int main(){
    cin >> N;
    cin >> ch;
    getline(cin, str);
    getline(cin, str);
    len = str.length();
    addStr();
    subStr();
    // cout << str;
    return 0;
}