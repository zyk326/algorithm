#include<iostream>
#include<regex>

using namespace std;

string str;

int rule[] = {25, 23, 21, 19, 17, 15, 13, 11, 9, 7, 5, 3, 1,
             -1, -3, -5, -7, -9, -11, -13, -15, -17, -19, -21, -23, -25};
int point = 0;
regex reg1("[A-Z]");
regex reg2("[a-z]");

int main(){
    getline(cin, str);
    while(str[point] != '\0'){
        string buf = str.substr(point, 1);
        if(buf != " "){
            if(regex_match(buf, reg1)){
                // cout << str[point] << " + " << rule[str[point] - 'A'] << " = " << (char)(str[point] + rule[str[point] - 'A']) << endl; 
                str[point] += rule[str[point] - 'A'];
            }
            // if(regex_match(buf, reg2)){
            //     cout << str[point] << " + " << rule[str[point] - 'a'] << " = " << (char)(str[point] + rule[str[point] - 'a']) << endl; 
            //     str[point] += rule[str[point] - 'a'];
            // }
        }
        point++;
    }
    cout << str;
    return 0;
}