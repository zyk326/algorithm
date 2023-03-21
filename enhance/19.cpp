#include<iostream>
#include<string.h>

#define MaxSize 100001

using namespace std;

int N, N1;
int point, point2;
int i, j;
int id, fa, mo;
string sex;
string sexs[MaxSize];
int father[MaxSize], mother[MaxSize];
string ans[MaxSize];

bool deal(int po1, int po2, int num){
    if(po1 == -1 || po2 == -1)
        return true;
    if((father[po1] != -1 && father[po1] == father[po2]) || (mother[po1] != -1 && mother[po1] == mother[po2])){
        return false;
    }
    num++;
    if(num >= 4)
        return true;
    return deal(father[po1], father[po2], num) && deal(mother[po1], mother[po2], num)
            && deal(father[po1], mother[po2], num) && deal(mother[po1], father[po2], num);
}

int main(){
    cin >> N;
    memset(father, -1, sizeof(father));
    memset(mother, -1, sizeof(mother));
    for(i = 0; i < N; i++){
        cin >> id >> sex >> fa >> mo;
        sexs[id] = sex;
        father[id] = fa;
        mother[id] = mo;
        sexs[fa] = "M";
        sexs[mo] = "F";
    }
    cin >> N1;
    for(i = 0; i < N1; i++){
        cin >> point >> point2;
        if(sexs[point] == sexs[point2]){
            ans[i] = "Never Mind";
        }else{
            if(deal(point, point2, 0)){
                ans[i] = "Yes";
            }else{
                ans[i] = "No";
            }
        }
    }
    for(i = 0; i < N1; i++){
        cout << ans[i] << endl;
    }
    return 0;
}