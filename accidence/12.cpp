#include<iostream>
#define MaxSize 101

using namespace std;

int ra, ca, rb, cb;
int a[MaxSize][MaxSize], b[MaxSize][MaxSize], ans[MaxSize][MaxSize] = {0};

void init(int a[][MaxSize], int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
        }
    }
}

int main(){
    cin >> ra >> ca;
    init(a, ra, ca);
    cin >> rb >> cb;
    init(b, rb, cb);

    if(ca != rb)
        cout << "Error: " << ca << " != " << rb;
    else{
        int k = 0;
        for(int ii = 0; ii < ra; ii++){
            for(int jj = 0; jj < cb; jj++){
                for(int i = 0; i < ca; i++){
                    ans[ii][jj] += a[ii][i] * b[i][jj]; 
                }
            }
        }
        cout << ra << " " << cb << endl;
        for(int i = 0; i < ra; i++){
            for(int j = 0; j < cb; j++){
                cout << ans[i][j];
                if(j != cb - 1){
                     cout << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}