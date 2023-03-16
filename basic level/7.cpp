#include<iostream>

using namespace std;

int T;
int WF, TF;
int point;
int TX;

//wugui --> 3m/min  |  tuzi --> 9m/min
int main(){
    cin >> T;
    while(point < T){
        WF += 3;
        if(TX > 0){
            TX--;
        }else{
            TF += 9;            
        }
        if(TX == 0 && (point + 1) % 10 == 0 && WF < TF){
            TX = 30;
        }
        // cout << point << " : " << WF << " - " << TF << endl;
        point++;
    }
    if(WF > TF){
        cout << "@_@ " << WF;
    }else if(WF < TF){
        cout << "^_^ " << TF;
    }else{
        cout << "-_- " << TF;
    }
    return 0;
}