#include<iostream>

using namespace std;

string N;
int point;

int main(){
    cin >> N;
    while(N[point] != '\0'){
        if(N[point] == '0'){
            N[point] = '9';
        }else{
            N[point] = N[point] - 1;
        }
        point++;
    }
    char buf;
    buf = N[0];
    N[0] = N[2];
    N[2] = buf;

    buf = N[1];
    N[1] = N[3];
    N[3] = buf;
    point = 0;
    int len = N.length();
    // cout << N << endl;
    // while(N[point] == '0'){
    //     // cout << "in ";
    //     point++;
    // }
    N = N.substr(point, len - point);
    // if(N.empty()){
    //     N = "0";
    // }
    cout << "The encrypted number is " << N;
    return 0;
}