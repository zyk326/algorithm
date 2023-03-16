#include<iostream>
#include<regex>

using namespace std;

string S1, S2;

int main(){
    getline(cin, S1);
    getline(cin, S2);
    regex reg(S2);
    regex reg1(".*" + S2 + ".*");
    while(regex_match(S1, reg1)){
        S1 = regex_replace(S1, reg, "");
    }
    cout << S1;
    return 0;
}