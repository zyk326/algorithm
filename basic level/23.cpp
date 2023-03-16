#include<iostream>

using namespace std;

int x;
int n;
string s;
string ans;

void format(){
    int point;
    while(ans[point] != '\0' && ans[point] == '0'){
        point++;
    }
    ans = ans.substr(point);
}

bool deal(){
    ans.clear();
    int nums = 0;
    int len = s.length();
    int point = 0;
    // cout << "now s is: " << s << endl;
    while(s[point] != '\0'){
        nums = nums * 10 + (s[point] - '0');
        ans += to_string(nums / x);
        nums = nums % x;
        point++;
    }
    if(nums == 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    cin >> x;
    while(1){
        n++;
        s += "1";
        if(deal()){
            break;
        }
    }
    format();
    cout << ans << " " << n;
    return 0;
}