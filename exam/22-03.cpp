#include<iostream>
#include<math.h>

#define long long ll

using namespace std;

int N;
int ans = 0;
int i, j;

int main(){
    cin >> N;
    for(i = 2; i <= sqrt(N); i++){
        if(N % i == 0){
            ans++;
        }
        while(N % i == 0){
            N /= i;
        }
    }
    if(N > 1){
        ans++;
    }
    cout << ans;
    return 0;
}
