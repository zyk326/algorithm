#include<iostream>
#include<regex>

using namespace std;

regex regStr("[B-DF-HJ-NP-TV-Z]");
string str;
int ans = 0;
int i = 0;
string buf;

int main(){
    getline(cin , str);
    while(str[i] != '\0'){
        string buf(1, str[i]);
        // cout << buf << "--------" << endl;
        int fff = regex_match(buf, regStr);
        ans += fff;
        i++;
    }
    cout << ans;
    return 0;
}