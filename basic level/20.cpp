#include<iostream>

using namespace std;

string str;
int N;
string buf;
int len;

int main(){
    getline(cin, str);
    cin >> N;
    len = str.length();
    N = N % (len);
    if(N != 0){
        buf = str.substr(N, len - N);
        str = str.substr(0, N);
    }
    cout << buf << str;
    return 0;
}