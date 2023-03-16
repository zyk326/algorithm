#include<iostream>
#include<string>
#define MaxSize 1001

using namespace std;

int point = 0; //字符串当前下标(待处理)
int ans = 0;
string str = ""; // string 以\0 结尾

bool judge(string str){
    ans++;
    bool flag = false;
    flag = str == "250";
    return flag;
}

void cut(string str){
    string cutstr = "";
    while(str[point] != '\0' && str[point] != ' '){
        cutstr += str[point++];
    }
    point++;
    bool flag = judge(cutstr);
    if(flag){
        cout << ans << endl;
        exit(0);
    }
}

void tran(){
    while(str[point] != '\0'){
        cut(str);
    }
}

int main(){
    getline(cin, str);
    tran();
    return 0;
}