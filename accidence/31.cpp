#include<iostream>

using namespace std;

double cm;
double foot = 0.0;
double inch = 0.0;

int main(){
    cin >> cm;
    cm /= 30.48;
    double buf = cm;
    foot = (int)buf;
    cm -= foot * 1.0;
    cm *= 12;
    inch = (int)cm;
    cout << foot << " " << inch;
    return 0;
}