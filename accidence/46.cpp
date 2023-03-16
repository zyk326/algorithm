#include<iostream>

using namespace std;

int N;
bool flag = false;

int main(){
    cin >> N;
    for(int i = 1; i * i <= N; i++){
        for(int j = 1; j * j <= N; j++){
            if(i * i + j * j == N && i <= j){
                flag = true;
                cout << i << " " << j << endl;
            }
        }
    }
    if(!flag){
        cout << "No Solution";
    }
    return 0;
}