#include<iostream>

#define long long ll

using namespace std;

// int N;
constexpr int N=1e5+7,M=(1<<20)+7;
int i, j;
int n, m, x, a, last[M], g[N];


int main(){
    // cin >> N;
    cin >> n >> m >> x;
    for(i = 1; i <= n; i++){
        cin >> a;
        g[i] = max(g[i - 1], last[a^x]);
        last[a] = i;
    }
    while(m--){
        int l, r;
        cin >> l >> r;
        if(g[r] >= l) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}