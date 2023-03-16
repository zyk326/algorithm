#include<iostream>
#include<algorithm>

using namespace std;

string str;

int main(){
    getline(cin , str);
    sort(str.begin(), str.end());
    int point = 0;
    string ans = "";
    while(str[point] != '\0'){
        if(str[point] != str[point + 1]){
            ans += str.substr(point, 1);
        }
        point++;
    }
    cout << ans;
    return 0;
}