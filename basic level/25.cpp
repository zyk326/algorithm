#include<iostream>
#include<algorithm>

using namespace std;

#define Max 100005

int n;
int nums[Max];
int dp[Max];
int i, j;
int ans = 1;
int u = 0;

void init(){
    cin >> n;
    fill_n(dp, Max, 1);
    for(i = 0; i < n; i++){
        cin >> nums[i];
    }
}

void solve(){ // 这是最长连续子序列
    for(i = 1; i < n; i++){
        if(nums[i - 1] < nums[i]){
            dp[i] = dp[i - 1] + 1;
        }
        if(ans < dp[i]){
            ans = dp[i];
            u = i;
        }
    }
}

int main(){
    init();
    solve();
    for(i = u - ans + 1; i <= u; i++){
        if(i == u - ans + 1){
            cout << nums[i];
        }else{
            cout << " " << nums[i];
        }
    }
    return 0;
}