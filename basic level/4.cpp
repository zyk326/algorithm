#include<iostream>

using namespace std;

string str;
int ans;
string ansstr;
int point;
string buf;
int happy, unhappy;

//X什么都不放，T放捕鼠夹，C放奶酪
int main(){
    cin >> str;
    while(str[point] != '\0' && str[point] != '$'){
        buf = str.substr(point, 1);
        if(buf == "X"){
            if(happy > 0 || unhappy == 0){
                unhappy = 2;
                ansstr += "U";
            }else{
                ansstr += "-";
            }
        }else if(buf == "T"){
            if(happy > 0 || unhappy == 0){
                ans += 7;
                unhappy = 3;
                ansstr += "D";
            }else{
                ansstr += "-";
            }
        }else if(buf == "C"){
            if(happy > 0 || point == 0 || unhappy == 0){
                ans -= 3;
                happy = 3;
                ansstr += "!";
            }else{
                ansstr += "-";
            }
        }
        if(unhappy > 0){
            unhappy--;
        }
        if(happy > 0){
            happy--;
        }
        point++;
        // cout << ans << " --- " << endl;
    }
    cout << ansstr << endl;
    cout << ans;
    return 0;
}