#include<iostream>
// #include<regex>
#include<vector>
#include<algorithm>

using namespace std;

// regex reg("\\s+");//简单的事情对于编写正则表达式是过度的。
string str;
int point;
vector<string> vs;
string buf;
vector<string>::iterator vsi;

int main(){
    getline(cin, str);
    str += " ";
    while(str[point] != '\0'){
        if(str[point] != ' '){
            buf += str[point];
        }else{
            if(!buf.empty()){
                vs.push_back(buf);
                buf.clear();
            }
        }
        point++;
    }
    reverse(vs.begin(), vs.end());
    for(int i = 0; i < vs.size(); i++){
        cout << vs[i];
        if(i < vs.size() - 1){
            cout << " ";
        }
    }
    return 0;
}