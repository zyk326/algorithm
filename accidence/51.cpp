#include<iostream>

using namespace std;

string str1, str2;
int a1, b1, a2, b2;

void deal1(){
    int buf = min(a1, b1);
    
    for(int i = 2; i <= buf; i++){
        if(a1 % i == 0 && b1 % i == 0){
            a1 /= i;
            b1 /= i;
            i = 2;
            buf = min(a1, b1);
        }
    }
}

void deal(){
    int i = 0;
    while(str1[i] != '/'){
        i++;
    }
    a1 = atoi(str1.substr(0, i).c_str());
    b1 = atoi(str1.substr(i + 1).c_str());
    i = 0;
    while(str2[i] != '/'){
        i++;
    }
    a2 = atoi(str2.substr(0, i).c_str());
    b2 = atoi(str2.substr(i + 1).c_str());
}

int main(){
    cin >> str1 >> str2;
    deal();
    a1 *= b2;
    b1 *= b2;
    a2 *= b1 / b2;
    b2 = b1;
    // cout << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
    a1 += a2;
    deal1();
    if(b1 == 1 || a1 == b1){
        a1 /= b1;
        cout << a1;
    }else{
        cout << a1 << "/" << b1;
    }
    return 0;
}