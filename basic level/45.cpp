#include<iostream>

using namespace std;

int N;
int point;

bool exit(int i, string str){
    for(int j = 0; j < str.length(); j++){
        if(str[j] - '0' == i){
            return true;
        }
    }
    return false;
}

void dfs(int deep, string str){
    if(deep == N){
        cout << str << endl;
    }else{
        for(int i = 0; i < N; i++){
            if(!exit(i + 1, str)){
                dfs(deep + 1, str + to_string(i + 1));
            }
        }
    }
}

int main(){
    cin >> N;
    string ans;
    dfs(0, ans);
    return 0;
}