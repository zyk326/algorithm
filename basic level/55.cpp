#include<iostream>

using namespace std;

int point;
int a1, a2, n;
string ans;

int main(){
    cin >> a1 >> a2 >> n;
    ans += to_string(a1) + to_string(a2);
    while(ans.length() < n){
        ans += to_string(a1 * a2);
        point++;
        a1 = atoi(ans.substr(point, 1).c_str());
        a2 = atoi(ans.substr(point + 1, 1).c_str());
    }
    point = 0;
    ans = ans.substr(0, n);
    while(ans[point] != '\0'){
        if(point == 0){
            cout << ans[point];
        }else{
            cout << " " << ans[point];
        }
        point++;
    }
    return 0;
}