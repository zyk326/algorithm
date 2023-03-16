#include<iostream>

using namespace std;

int N;
int ans = 1;

int main(){
    cin >> N;
    while(N > 1){//第三天只剩一个，说明只吃了两天
        ans += 1;
        ans *= 2;
        N--;
    }
    cout << ans;
    return 0;
}