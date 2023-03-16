#include<iostream>
#include<string>

using namespace std;

string str = "";
string str1, str2, strnum1, strnum2, strnum3, strnum4;
int num1, num2, num3, num4;

int gcd(int num2, int num4){
    if(num2 < num4){
        int temp = num2;
        num2 = num4;
        num4 = temp;
    }
    if(num2 % num4 == 0)
        return num4;
    else return gcd(num4, num2 % num4);
}

int comp(string str1, string str2){
    int gap1 = str1.find("/");
    strnum1 = str1.substr(0, gap1);
    strnum2 = str1.substr(gap1 + 1);
    num1 = atoi(strnum1.c_str());
    num2 = atoi(strnum2.c_str());

    int gap2 = str2.find("/");
    strnum3 = str2.substr(0, gap2);
    strnum4 = str2.substr(gap2 + 1);
    num3 = atoi(strnum3.c_str());
    num4 = atoi(strnum4.c_str());

    int maxsame = gcd(num2, num4);
    int f, s;
    f = num4 / maxsame * num1;
    s = num2 / maxsame * num3;
    if(f == s){
        return 0;
    }else if(f < s){
        return -1;
    }else if(f > s){
        return 1;
    }
    return -2;
}

int main(){
    getline(cin, str);
    int space = str.find(" ");
    str1 = str.substr(0, space);
    str2 = str.substr(space + 1);
    int ans = comp(str1, str2);//-1 小于 0 等于 1 大于
    cout << str1;
    if(ans == -1){
        cout << " < ";
    }else if(ans == 0){
        cout << " = ";
    }else if(ans == 1){
        cout << " > ";
    }
    cout << str2;
    return 0; 
}