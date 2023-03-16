#include<iostream>
#include<math.h>

using namespace std;

int n;
bool flag = false;

bool Su(int i){
    for(int j = 2; j * j <= i; j++){
        if(i % j == 0){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        if(Su(pow(2, i) - 1)){
            cout << pow(2, i) - 1 << endl;
            flag = true;
        }
        
    }
    if(!flag){
        cout << "None";
    }
    return 0;
}