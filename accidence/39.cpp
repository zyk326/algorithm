#include<iostream>

using namespace std;

string number1;
int point = 0;
string yin[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int len;

int main(){
    getline(cin, number1);
    len = number1.length();
    while(number1[point] != '\0'){
        if(number1[point] == '-'){
            cout << "fu";
        }else{
            cout << yin[number1[point] - '0'];
        }
        if(point < len - 1){
            cout << " ";
        }
        point++;
    }
    return 0;
}