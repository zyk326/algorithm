#include<iostream>
#include<stack>
#include<regex>

using namespace std;

int N;
int point;
int i, j;
string datas, oriwords;
stack <string> ss;
regex reg("[\\/\\*\\(\\)\\[\\]\\{\\}]");
regex reg1("[\\/\\(\\[\\{]");
string str, buf;

bool judge(string tt){
    if((buf == ")" && tt != "(") || (buf == "]" && tt != "[") || (buf == "}" && tt != "{") || (buf == "/*" && tt != "*/")){
        return false;
    }
    return true;
}

bool deal(){
    point = 0;
    while(str[point] != '\0'){
        buf = str.substr(point, 1);
        // cout << "now buf : " << buf;
        if(regex_match(buf, reg1)){
            if(buf == "/" && str[point + 1] == '*'){
                buf += "*";
                point++;
            }else if(buf == "/" && str[point + 1] != '*'){
                cout << "NO" << endl << "/*-?";
                return false;
            }
            ss.push(buf);
        }else{
            if(ss.empty()){
                cout << "NO" << endl << "?-" << buf; 
                return false;
            }
            string tt = ss.top();
            // cout << tt << endl;
            if(buf == "*" && str[point + 1] == '/'){
                buf += "/";
                point++;
            }else if(buf == "*" && str[point + 1] != '/'){
                point++;
                continue;
            }
            if(!judge(tt)){
                cout << "NO" << endl << "?-" << buf;
                return false;
            }
            ss.pop();
        }
        point++;
    }
    return true;
}

int main(){
    getline(cin, datas);
    while(datas != "."){  //point shi .
        oriwords += datas;
        getline(cin, datas);
    }
    while(oriwords[point] != '\0'){
        string buf = oriwords.substr(point, 1);
        if(regex_match(buf, reg)){
            str += buf;
        }
        point++;
    }
    // cout << str;
    if(deal()){
        cout << "YES";
    }
    return 0;
}