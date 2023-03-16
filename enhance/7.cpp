#include<iostream>
#include<queue>

using namespace std;

int N;
int point;
int i, j;
queue<int> A, B;
string ans;

int main(){
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> point;
        if(point % 2 == 0){
            B.push(point);
        }else{
            A.push(point);
        }
    }
    while(!A.empty() && !B.empty()){
        if(!A.empty()){
            ans.append(" " + to_string(A.front()));
            A.pop();
        }
        if(!A.empty()){
            ans.append(" " + to_string(A.front()));
            A.pop();
        }
        if(!B.empty()){
            ans.append(" " + to_string(B.front()));
            B.pop();
        }
    }
    while(!A.empty()){
        ans.append(" " + to_string(A.front()));
        A.pop();
    }
    while(!B.empty()){
        ans.append(" " + to_string(B.front()));
        B.pop();
    }
    cout << ans.substr(1);
    return 0;
}