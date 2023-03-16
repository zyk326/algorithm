#include<iostream>
#include<deque>

using namespace std;

int K;
int point;
int i, j;
deque <int> dqi;

int main(){
    cin >> K;
    cin >> i;
    while(i != -1){
        if(K > 0){
            dqi.push_back(i);
            K--;
        }else{
            dqi.push_back(i);
            dqi.pop_front();

        }
        cin >> i;
    }
    if(K == 0){
        cout << dqi.front();
    }else{
        cout << "NULL";
    }
    return 0;
}