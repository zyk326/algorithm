#include<iostream>
#include<regex>

using namespace std;

regex reg("[0-9]");
string str;
string ans = "";
string buf;
int i = 0;

void deal(){
    i = 0;
    while(ans[i] == '0'){
        i++;
    }
    ans = ans.substr(i);
    if(ans.empty()){
        ans = "0";
    }
}

int main(){
    getline(cin, str);
    while(str[i] != '\0'){
        buf = str.substr(i, 1);
        if(regex_match(buf, reg)){
            ans.append(buf);
        }
        i++;
    }
    deal();
    cout << ans;
    return 0;
}