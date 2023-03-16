#include<iostream>
#include<regex>

using namespace std;

string str;
int ans;
regex reg("[0-9]");
regex reg1("[\\+\\-\\*\\/]");
int point = 0;

int getnum(){
    string buf;
    string numb;
    int numbn;
    //find first number
    while(str[point] != '\0'){
        buf = str.substr(point, 1);
        // cout << buf << endl;
        if(!regex_match(buf, reg)){
            // cout << numb << " - is string ;" << endl;
            numbn = atoi(numb.c_str());
            break;
        }else{
            // cout << buf << endl;
            numb += buf;
        }
        point++;
    }
    // cout << "this num of string is:" << numb << "and trans to int is:" << numbn << endl;
    return numbn;
}

bool deal(){
    ans = getnum();
    // cout << ans << endl;
    //first sign at point
    // string fuhao = str.substr(point++, 1);
    string fu;
    while(str[point] != '=' && str[point] != '\0'){
        fu = str.substr(point++, 1);
        if(!regex_match(fu, reg1)){
            if(fu == "="){
                return true;
            }else{
                return false;
            }
        }
        int nextnum = getnum();
        // cout << "the next number is:" << nextnum << endl;
        if(fu == "+"){
            ans += nextnum;
        }else if(fu == "-"){
            ans -= nextnum;
        }else if(fu == "*"){
            ans *= nextnum;
        }else if(fu == "/"){
            if(nextnum == 0){
                return false;
            }else{
                ans /= nextnum;
            }
        }
        // cout << "do is ans :" << ans << endl;
        // cout << str[point] << endl;
    }
    return true;
}

int main(){
    cin >> str;
    if(deal()){
        cout << ans;
    }else{
        cout << "ERROR";
    }
    return 0;
}