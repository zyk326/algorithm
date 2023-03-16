#include<iostream>

using namespace std;

int K;
string buf;
int point = 0;
string ans[10001];
int times = 0;

int main(){
    cin >> K;
    do{
        cin >> buf;
        if(buf == "ChuiZi"){
            ans[point] = "Bu";
        }else if(buf == "JianDao"){
            ans[point] = "ChuiZi";
        }else if(buf == "Bu"){
            ans[point] = "JianDao";
        }
        if(times == K){
            ans[point] = buf;
            times = -1;
        }
        times++;
        point++;
    }while(buf != "End");
    for(int i = 0; i < point - 1; i++){
        cout << ans[i] << endl;
    }
    return 0;
}