#include<iostream>

using namespace std;

int n;
bool flag = false;

int main(){
    cin >> n;
    for (int  i = 0; i < 199; i++){
        for( int j = 0; j < 100; j++){
            if(j * 100 + i - n == 2 * i * 100 + 2 * j){
                flag = true;
                cout << i << "." << j;
            }
        }
    }
    if(!flag)
        cout << "No Solution";
    return 0;
}