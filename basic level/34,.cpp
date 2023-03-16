#include<iostream>
#include<regex>
#include<algorithm>

using namespace std;

int N;
int point;
int i, j;
string str1, str2, buf;

int main(){
    getline(cin, str1);
    getline(cin, str2);
    regex reg("[" + str2 + "]");
    while(str1[point] != '\0'){
        if(regex_match(str1.substr(point, 1), reg)){
            // c out << str1[point] << endl;
            str1.erase(point, 1);
        }else{
            point++;
        }
    }
    cout << str1;
    return 0;
}