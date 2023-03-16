#include<iostream>

using namespace std;

int N;
int ans = 0, maxans = 0;
int i, j;
int numb[100001];

int main(){
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> numb[i];
        if(numb[i] + ans >= 0){
            ans += numb[i];
            if(maxans < ans){
                maxans = ans;
            } 
        }else{
            ans = 0;
        }
    }
    cout << maxans;
    return 0;
}