#include<iostream>

using namespace std;

int N;
int point;
int j;
int ss = 0;

void output(string a){
    a = a.substr(1);
    cout << N << "=";
    int len = 0;
    while(a[len] != '\0'){
        if(len == 0){
            cout << a[len];
        }else{
            cout << a[len];
        }
        len++;
    }
}

void dfs(int k, string ans, int pre){
    if(k > N)
        return;
    if(k == N){
        output(ans);
        ss++;
        if(ss % 4 == 0){
            cout << endl;
        }else{
            if(pre != N)
                cout << ";";
        }
    }else{
        for(int i = pre; i <= N - k; i++){
            dfs(k + i, ans + "+" + to_string(i), i);
        }
    }
}
int main(){
    cin >> N;
    dfs(0, "", 1);
    return 0;
}