#include<iostream>
#include<algorithm>

using namespace std;

string str;
int point = 0;

void doit(){
    sort(str.begin(), str.end());
    int small = atoi(str.c_str());
    reverse(str.begin(), str.end());
    int big = atoi(str.c_str());
    cout << point << ": " << big << " - " << small << " = " << big - small << endl;
    str = to_string(big - small);
}

int main(){
    cin >> str;
    while(str != "495" || point == 0){
        point++;
        doit();
    }
    return 0;
}