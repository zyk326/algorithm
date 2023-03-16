#include<iostream>

using namespace std;

long long ans = 1;
int a, b;

void comp(int a, int b){
    int c = 1;
    while(c <= (a + b)){
        ans *= c++;
    }
    cout << ans;
}

int main(){
    cin >> a;
    cin >> b;
    comp(a, b);
    return 0;
}