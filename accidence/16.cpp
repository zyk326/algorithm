#include<iostream>
#include<algorithm>

using namespace std;

int L, N;
string str = "zzzzzz";
int remain;

int main(){
    cin >> L >> N;
    str = str.substr(0, L);
    N -= 1;
    for(int i = 0 ; i < L; i++){
        remain = N % 26;
        N = N / 26;
        str[i] -= remain;
    }
    reverse(str.begin(),str.end());
    cout << str << endl;
    return 0;
}