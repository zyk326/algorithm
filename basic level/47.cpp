#include<iostream>

using namespace std;

int N, M;
int point;
int i, j;
string str;
string ans[10001];

string deal(string ss){
    int nowmax = 0, nowS = 0;
    point = 0;
    while(ss[point] != '\0'){
        if(ss[point] == 'S'){
            nowmax++;
            nowS++;
            if(nowmax > M){
                return "NO";
            }
        }else if(ss[point] == 'X'){
            nowmax--;
            nowS--;
            if(nowS < 0){
                return "NO";
            }
        }
        point++;
    }
    if(nowmax != 0){
        return "NO";
    }
    return "YES";
}

int main(){
    cin >> N >> M;
    for(i = 0; i < N; i++){
        cin >> str;
        ans[i] = deal(str);
    }
    for(i = 0; i < N; i++){
        cout << ans[i] << endl;
    }
    return 0;
}