#include<iostream>
#include<regex>

using namespace std;

string a, b;
bool flag1 = true, flag2 = true;
regex reg("[0-9]");
int point = 0;
string buf;
int a1, b1;

int main(){
    cin >> a;
    getline(cin, b);
    b = b.substr(1);
    if(a[0] == '-'){
        flag1 = false;
    }
    while(a[point] != '\0'){
        buf = a.substr(point, 1);
        if(!regex_match(buf, reg)){
            flag1 = false;
            break;
        }
        point++;
    }    

    if(flag1){
        a1 = atoi(a.c_str());
        if(a1 > 10000 || a1 < 1){
            flag1 = false;
        }
    }

    point = 0;
    if(b[0] == '-'){
        flag2 = false;
    }
    while(b[point] != '\0'){
        buf = b.substr(point, 1);
        if(!regex_match(buf, reg)){
            flag2 = false;
            break;
        }
        point++;
    }   
    if(flag2){
        b1 = atoi(b.c_str());
        if(b1 > 10000 || b1 < 1){
            flag2 = false;
        }
    }

    if(flag1){
        cout << a1 << " ";
    }else{
        cout << "? ";
    }
    cout << "+ ";
    if(flag2){
        cout << b1 << " ";
    }else{
        cout << "? ";
    }
    cout << "= ";
    if(!flag1 || !flag2){
        cout << "?";
    }else{
        cout << a1 + b1;
    }
    return 0;
}