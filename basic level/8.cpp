#include<iostream>

using namespace std;

int x;
int f5, f2, f1;
int count;
int i, j, k;

int main(){
    cin >> x;
    for(i = 20; i > 0; i--){
        for(j = 50; j > 0; j--){
            for(k = 100; k > 0; k--){
                if(5 * i + 2 * j + k == x){
                    count++;
                    cout << "fen5:" << i << ", fen2:" << j << ", fen1:" << k << ", total:" << i + j + k << endl;
                }
            }
        }
    }
    cout << "count = " << count;
    return 0;
}