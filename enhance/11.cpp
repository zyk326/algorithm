#include<iostream>
#include<vector>

using namespace std;

int N;
int point;
int i;
struct lowPeo{
    vector<int> sons;
}lowPeos[100001];
int level[100001];
int father;
int maxlevel;
bool flag = true;

void deal(int fa){
    if(lowPeos[fa].sons.size() == 0){
        if(level[fa] > maxlevel) maxlevel = level[fa];
        return;
    }
    else{
        for(int j = 0; j < lowPeos[fa].sons.size(); j++){
            // cout << " j is : " << j << "  --   " << lowPeos[father].sons[j] << endl;
            level[lowPeos[fa].sons[j]] = level[fa] + 1;
            deal(lowPeos[fa].sons[j]);
        }  
    }
}

int main(){
    cin >> N;
    for(i = 1; i <= N; i++){
        cin >> point;
        if(point != -1){
            lowPeos[point].sons.push_back(i); // i编号的爹是point
        }else{
            father = i;
        }
    }
    deal(father);
    // for(i = 1; i <= N; i++){
    //     cout << level[i] << " ";
    // }
    cout << maxlevel + 1 << endl;
    for(i = 1; i <= N; i++){
        if(level[i] == maxlevel){
            if(flag) {cout << i; flag = false;}
            else cout << " " << i;
        }
    }
    return 0;
}