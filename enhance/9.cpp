#include<iostream>

using namespace std;

int N;
int point;
int j;
char Fi[51], Se[51];

int dfs(char * pre, char * in, int n){
    if(n == 0){
        return 0;
    }else{
        int i;
        for(i = 0; i < n; i++){
            if(in[i] == pre[0])
                break;
        }
        int l = dfs(pre + 1, in, i);
        int r = dfs(pre + i + 1, in + i + 1, n - i - 1);
        return max(l, r) + 1;
    }
}

int main(){
    cin >> N;
    cin >> Fi >> Se;
    cout << dfs(Fi, Se, N);
    return 0;
}