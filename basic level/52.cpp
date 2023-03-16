#include<iostream>
#include<regex>

using namespace std;

int N;
int point;
int i, j;
string str1, str2, ans;

int main(){
    getline(cin, str1);
    getline(cin, str2);
    regex reg("[" + str2 + "]");
    while(str1[point] != '\0'){
        if(!regex_match(str1.substr(point, 1), reg)){
            ans += str1[point];
        }
        point++;
    }
    cout << ans;
    return 0;
}