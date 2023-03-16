#include<iostream>
#include<algorithm>

using namespace std;

int N, k;
int tag[1001];
int ans;

int main(){
    cin >> N;
    fill_n(tag, 1001, 0);
    for(int i = 0; i < N; i++){
        cin >> k;
        int buf;
        for(int j = 0; j < k; j++){
            cin >> buf;
            tag[buf]++;
        }
    }
    for(k = 1; k < 1001; k++){
        if(tag[k] >= tag[0]){
            tag[0] = tag[k];
            ans = k;
        }
    }
    cout << ans << " " << tag[0];
    return 0;
}