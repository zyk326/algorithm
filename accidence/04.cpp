#include<iostream>
#include<iomanip>
using namespace std;

double ans = 0.0;
double cash = 0.0;

int main(){
    cin >> cash;
    if(cash <= 1600.0){
        ans = 0;
    }else if(cash > 1600.0 && cash <= 2500.0){
        ans = (cash - 1600.0) * 0.05;
    }else if(cash > 2500.0 && cash <= 3500.0){
        ans = (cash - 1600.0) * 0.1;
    }else if(cash > 3500.0 && cash <= 4500.0){
        ans = (cash - 1600.0) * 0.15;
    }else if(cash > 4500.0){
       ans = (cash - 1600.0) * 0.2; 
    }
    cout << setprecision(2) << fixed << ans << endl;
    return 0;
}