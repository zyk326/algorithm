#include<iostream>

using namespace std;

int N;
int point = 0;
int buf, num = -1;

int trans(int a){
    int ans = 0;
    while(a != 0){
        ans += a % 10;
        a /= 10;
    }
    ans *= 3;
    ans++;
    return ans;
}

void deal(){
    if(num == N){
        return;
    }else{
        num = N;
        N = trans(N);
        cout << ++point << ":" << N << endl;
        deal();
    }
}

int main(){
    cin >> N;
    deal();
    return 0;
}