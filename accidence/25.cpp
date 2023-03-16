#include<iostream>

using namespace std;

string str;
int ans = 0;
int len, i;

void deal(){
    len = str.length();
    i = 0;
    while(str[i] == ' '){
        i++;
    }
    str = str.substr(i);
    i = str.length() - 1;
    while(str[i] == ' '){
        i--;
    }
    str = str.substr(0, i + 1);
}

int main(){
    getline(cin, str);
    deal();
    if(str.length() == 0){
        cout << 0;
    }else{
        while(!str.empty()){
            // cout << str << endl;
            if(str.find(" ") == -1)
                break;
            else{
                i = str.find(" ");
                ans++;
                while(str[++i] == ' '){}
                str = str.substr(i);
            }
        }
        cout << ans + 1;
    }
    return 0;
}