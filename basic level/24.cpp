#include<iostream>
#include<map>

using namespace std;

int N;
int point;
int i, j;
int K, M;
map<string, int> msi;
string buf;
bool flag = false;

int main(){
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> K;
        for(j = 0; j < K; j++){
            cin >> buf;
            if(K != 1){  //如果是1，那么表明只有自己一个人在这个朋友圈里
                msi[buf]++;                
            }
        }
    }
    cin >> M;
    for(i = 0; i < M; i++){
        cin >> buf;
        if(msi[buf] == 0){
            msi[buf] = -1;
            if(!flag){
                cout << buf;
            }else{
                cout << " " << buf;
            }
            flag = true;
        }
    }
    if(!flag){
        cout << "No one is handsome";
    }
    return 0;
}