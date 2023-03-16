#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<regex>

using namespace std;

int N;
int point;
int i, j;
string str;
map<string, int> rule;
string ans;
stack<string> sst;
string nowNum, lookStr;
regex reg1("[0-9]");

string getNumber(){
    string bufnum;
    int savepoint = point;
    if(str[point] == '-' || str[point] == '+'){
        if(point == 0 || (point != 0 && str[point - 1] == ')'))
            point++; 
    }
    string nowbufnum = str.substr(point, 1);
    while(regex_match(nowbufnum, reg1) || nowbufnum == "."){
        point++;
        nowbufnum = str.substr(point, 1);
    }
    // cout << "now gap : " << point - savepoint << endl;
    if(point - savepoint != 0)
        return str.substr(savepoint, point - savepoint);
    else{
        return "";
    }
}

int main(){
    cin >> str;
    reverse(str.begin(), str.end());
    rule[")"] = 3;
    rule["("] = 3;
    rule["/"] = 2;
    rule["*"] = 2;
    rule["+"] = 1;
    rule["-"] = 1;
    while(str[point] != '\0'){
        // cout << " -- " << point << endl;
        lookStr = str.substr(point, 1);
        // cout << "now look : " << lookStr << endl;
        nowNum = getNumber();
        if(nowNum == ""){
            if(lookStr == "("){
                while(!sst.empty() && sst.top() != ")"){
                    ans += sst.top();
                    sst.pop();
                }
                sst.pop();
            }else{
                if(!sst.empty() && sst.top() == ")"){

                }else{
                    while(!sst.empty() && rule[sst.top()] >= rule[lookStr]){
                        ans += sst.top();
                        sst.pop();
                    }
                }

                sst.push(lookStr);
            }           
            point++;
        }else{
            ans += nowNum;
        }
        cout << ans << endl;
    }
    while(!sst.empty()){
        ans += sst.top();
        sst.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}