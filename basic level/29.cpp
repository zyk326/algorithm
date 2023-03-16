#include<iostream>
#include<algorithm>

using namespace std;

int N;
int point;
int i, j;
string str;
string strs[101];
int ansx, ansy;
bool finall = false;

string tosimple(int a, int b){
    // cout << a << " - " << b << endl;
    int top = a;
    if(a > b){
        top = b;
    }
    int point = 2;
    while(point <= top){
        if(a % point == 0 && b % point == 0){
            a /= point;
            b /= point;
            top /= point;
            point = 2;
        }else{
            point++;            
        }
    }
    // cout << a << " " << b;
    if(finall){
        if(a == 0){
            return "0";
        }else if(b == 1){
            return to_string(a);
        }
    }
    if(a == 0){
        return "0/1";
    }
    return to_string(a) + "/" + to_string(b);
}

string dosum(string one, string two){
    // //step one : get '-'
    // bool fuone = false;
    // bool futwo = false;
    // if(one[0] == '-'){
    //     fuone = true;
    //     one = one.substr(1);
    // }
    // if(two[0] == '-'){
    //     fuone = true;
    //     two = two.substr(1);
    // }
    //step two : get the digtal number
    // cout << one << "  -  " << two << endl;
    int x1, y1, x2, y2;
    x1 = atoi(one.substr(0, one.find('/')).c_str());
    y1 = atoi(one.substr(one.find("/") + 1).c_str());
    x2 = atoi(two.substr(0, two.find('/')).c_str());
    y2 = atoi(two.substr(two.find("/") + 1).c_str());
    //step three : get the same /-
    x1 = x1 * y2;
    y1 = y1 * y2;
    x2 = x2 * y1 / y2;
    y2 = y2;
    //setp four : get the sum
    x1 += x2;
    return tosimple(x1, y1);
    // return to_string(x1) + "/" + to_string(y1);
}

string getsum(int l, int r){
    if(l == r){
        return strs[l];
    }else{
        return dosum(getsum(l, (l + r) / 2), getsum((l + r) / 2 + 1, r));
    }
}

int main(){
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> strs[i];
    }
    str = getsum(0, N - 1);
    // cout << str << endl;
    // cout << str.substr(0, str.find("/"));
    // cout << str.substr(str.find("/") + 1);
    // cout << endl;
    finall = true;
    cout << tosimple(atoi(str.substr(0, str.find("/")).c_str()), atoi(str.substr(str.find("/") + 1).c_str()) * N);
    
    return 0;
}