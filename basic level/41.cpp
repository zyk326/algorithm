#include<iostream>

using namespace std;

int N;
int point;
int i, j;
int nums[10];
string ans;
string zero;

int main(){
    for(i = 0; i < 10; i++){
        cin >> nums[i];
        for(j = 0; j < nums[i]; j++){
            if(i != 0){
                ans += to_string(i);
            }else{
                zero += "0";
            }
        }
    }
    ans.insert(1, zero);
    cout << ans;
    return 0;
}