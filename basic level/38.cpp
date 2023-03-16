#include<iostream>

using namespace std;

int N;
int point;
int i, j;

struct ele{
    int d; 
    int z;
}eles[1001];

int main(){
    bool fir = false;
    cin >> eles[0].d;
    cin >> eles[0].z;
    while(eles[point].z != 0){
        point++;
        cin >> eles[point].d;
        cin >> eles[point].z;
    }
    for(i = 0; i < point; i++){
        eles[i].d *= eles[i].z--;
        if(!fir){
            if(eles[i].d != 0){
                cout << eles[i].d << " " << eles[i].z;
                fir = true;
            }
        }else{
            if(eles[i].d != 0){
                cout << " " << eles[i].d << " " << eles[i].z; 
                fir = true;
            }
        }
    }
    if(point == 0){
        cout << "0 0";
    }
    return 0;
}