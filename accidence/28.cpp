#include<iostream>

using namespace std;

double Open, High, Low, Close;
bool one, two;
string ans = "";
string ans1 = "";
string ans2 = "";

int main(){
    cin >> Open >> High >> Low >> Close;
    if(Close < Open){
        ans = "BW-Solid";
    }else if(Close > Open){
        ans = "R-Hollow";
    }else if(Close == Open){
        ans = "R-Cross";
    }
    if(Low < Open && Low < Close){
        ans1 = "Lower Shadow";
    }
    if(High > Open && High > Close){
        ans2 = "Upper Shadow";
    }
    cout << ans;
    if(!ans1.empty()){
        cout << " with " << ans1;
    }
    if(!ans2.empty()){
        if(!ans1.empty()){
            cout << " and ";
        }else{
            cout << " with ";
        }
        cout << ans2;
    }
    return 0;
}