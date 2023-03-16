#include<iostream>
#include<stack>
#include<regex>
#include<math.h>

using namespace std;
stack <char> sc;
string str = "";
int len = 0;
int i = 0;
regex regexStr("[A-Fa-f0-9+-]");
string sign;
bool changeSign = true;
string nowMatch = "";

int judge(){
    int ans = regex_match(nowMatch, regexStr);
    return ans;
}

int trans(){
    len = str.size() - 1;
    int n = len;
    int temp, sum = 0;
    while(len >= 0){
        switch (str[len]){
            case 'A':
            case 'a': temp = 10; break;
            case 'B':
            case 'b': temp = 11; break;
            case 'C':
            case 'c': temp = 12; break;
            case 'D':
            case 'd': temp = 13; break;
            case 'E':
            case 'e': temp = 14; break;
            case 'F':
            case 'f': temp = 15; break;
            default: temp = str[len] - '0';break;
        }
        sum += temp * pow(16, n - len);
        len--;
    }
    return sum;
}

int main(){
    cin >> str;
    len = str.size() - 1;
    while(i < len){
        nowMatch = str[i];
        if(!judge()){
            str.erase(i, 1);
            len--;
        }else{
            if(str[i] == '+' || str[i] == '-'){
                if(changeSign)
                    sc.push(str[i]);
                str.erase(i, 1);
                len--;
            }else{
                changeSign = false;
                i++;
                if(sc.empty() || sc.top() == '+'){
                    sign = "";
                }else{
                    sign = "-";
                }
            }
        }
    }
    str = str.substr(0, len);
    cout << sign << trans();
    return 0;
}