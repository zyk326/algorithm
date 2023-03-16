#include<iostream>

using namespace std;

int N;
string str;
string ansstr[100];
int point;

int main(){
    cin >> N;
    getline(cin, str);//读回车
    getline(cin, str);
    while(str.length() % N != 0){
        str += " ";
    }
    while(str[point] != '\0'){
        ansstr[point % N] = str.substr(point, 1) + ansstr[point % N];
        point++;
    }
    for(int i = 0; i < N; i++){
        cout << ansstr[i] << endl;
    }
    return 0;
}