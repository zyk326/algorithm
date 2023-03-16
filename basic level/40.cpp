#include<iostream>
#include<algorithm>
#include<iomanip>

#define MaxSize 100000

using namespace std;

int N;
int point;
int i, j;
int startstr;
int bufadd;

struct oridata{
    int add;
    int value;
    int next;
}oridatas[MaxSize];
int visit[MaxSize];
int k1, k2;
oridata ans1[MaxSize];
oridata ans2[MaxSize];

int main(){
    cin >> startstr;
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> bufadd;
        cin >> oridatas[bufadd].value;
        cin >> oridatas[bufadd].next;
        oridatas[bufadd].add = bufadd;
    }
    while(startstr != -1){
        if(!visit[abs(oridatas[startstr].value)]){
            visit[abs(oridatas[startstr].value)] = 1;
            ans1[k1] = oridatas[startstr];
            k1++;
        }else{
            ans2[k2] = oridatas[startstr];
            k2++;
        }
        startstr = oridatas[startstr].next;
    }
    for(i = 0; i < k1; i++){
        cout << setw(5) << setfill('0') << right << ans1[i].add;
        cout << " " << ans1[i].value << " ";
        if(i == k1 - 1){
            cout << "-1" << endl;
        }else{
            cout << setw(5) << setfill('0') << right << ans1[i + 1].add << endl;
        }
    }
    for(i = 0; i < k2; i++){
        cout << setw(5) << setfill('0') << right << ans2[i].add;
        cout << " " << ans2[i].value << " ";
        if(i == k2 - 1){
            cout << "-1" << endl;
        }else{
            cout << setw(5) << setfill('0') << right << ans2[i + 1].add << endl;
        }
    }
    return 0;
}