#include<iostream>
#include<map>
#include<math.h>

using namespace std;

int A, B;
int point;
int ans;
int i, j;
map<int , int>finans;

int getmulsum(int num){
    int ans = 0;
    while(num != 0){
        ans += pow(num % 10, 2);
        num /= 10;
    }
    return ans;
}

bool sushu(int num){
    for(j = 2; j * j <= num; j++){
        if(num % j == 0){
            return false;
        }
    }
    return true;
}

bool deal(int num){
    ans = 1;
    if(num == 1){
        return true;
    }
    map<int, int>mii;
    int mulsum = getmulsum(num);
    mii[mulsum]++;
    while(mii[mulsum] <= 1 && mulsum != 1){
        ans++;
        mulsum = getmulsum(mulsum);
        mii[mulsum]++;
    }
    if(mulsum != 1){
        return false;
    }else{
        if(finans[num] == 0)
            finans[num] = 1;
        for(auto jj : mii){
            finans[jj.first] = -1;
        }
        if(sushu(num)){
            ans *= 2;
        }
        if(finans[num] == 1)
            finans[num] = ans;
    }
    return true;
}

int main(){
    cin >> A >> B;
    for(i = A; i <= B; i++){
        // if(deal(i)){
        //     cout << i << " " << ans << endl;
        // }
        deal(i);
    }
    bool flag = false;
    for(auto kk : finans){
        if(kk.second > 0){
            cout << kk.first << " " << kk.second << endl;
            flag = true;
        }
    }
    if(!flag){
        cout << "SAD";
    }
    return 0;
}