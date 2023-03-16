#include<iostream>
#include<regex>
#include<stack>
#include<map>

//中缀转后缀
using namespace std;

regex reg1("[0-9]");
int N;
int point;
int i, j;
string str;
string ans;
string buf;
stack<string> sst;
map<string, int> rule;
int growp, firstN = 1;

int getPoint(int pp){
    int ansp = 0;
    string temp = str.substr(pp, 1);
    if((point == 0 || str.substr(pp - 1, 1) == "(") && (temp == "+" || temp == "-")){
        ansp++;
        pp++;
        temp = str.substr(pp, 1);
    }
    while(regex_match(temp, reg1) || temp == "."){
        firstN = 0;
        ansp++;
        pp++;
        temp = str.substr(pp, 1);
    }
    return ansp;
}

int main(){
    cin >> str;
    rule[")"] = 3;
    rule["("] = 3;
    rule["/"] = 2;
    rule["*"] = 2;
    rule["+"] = 1;
    rule["-"] = 1;
    while(true){
        growp = getPoint(point);
        buf = str.substr(point, growp);
        if(growp){
            if(point != 0 || firstN == 1)
                cout << " ";
            if(buf[0] == '+'){
                buf = buf.substr(1);
            }
            cout << buf;
        }else{
            buf = str.substr(point, 1);
            growp = 1;
            if(buf == "("){
                sst.push(buf);
            }else if(buf == ")"){
                while(sst.top() != "("){
                    cout << " " << sst.top();
                    sst.pop();
                }
                sst.pop();
            }else{
                if(!sst.empty() && sst.top() == "("){

                }else{
                    while(!sst.empty() && rule[sst.top()] >= rule[buf]){
                        cout << " " << sst.top();
                        sst.pop();
                    }
                }    
                sst.push(buf);        
            }
        }
        point += growp;
        if(point >= str.length())
            break;
    }
    while(!sst.empty()){
        cout << " " << sst.top();
        sst.pop();
    }
    cout << endl;
    return 0;
}