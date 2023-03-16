#include<iostream>
#include<algorithm>

using namespace std;

string str;

int main(){
    getline(cin , str);
    reverse(str.begin(), str.end());
    cout << str;
    return 0;
}