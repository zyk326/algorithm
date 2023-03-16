#include<iostream>

using namespace std;

string str1, str2;
int i;

int main(){
    cin >> str1 >> str2;
    string s1 = "";
    string s2 = "";
    for(i = 1; i < str1.length(); i++){
        if(str1[i] % 2 == str1[i-1] % 2){
            s1 += max(str1[i], str1[i-1]);
        }
    }
    for(i = 1; i < str2.length(); i++){
        if(str2[i] % 2 == str2[i-1] % 2){
            s2 += max(str2[i], str2[i-1]);
        }
    }
    if(s1 == s2){
        cout << s1;
    }else{
        cout << s1 << endl << s2;
    }
    return 0;
}