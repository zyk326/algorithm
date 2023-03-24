#include<iostream>
#include<math.h>

#define MaxSize 102

using namespace std;

int N, D;
int point;
int i, j;
bool flag = false;
struct Node{
    int x;
    int y;
}nodes[MaxSize];
int vis[MaxSize];

double dis_loc_ii(int loc, int to){
    return sqrt(pow(nodes[loc].x - nodes[to].x, 2) + pow(nodes[loc].y - nodes[to].y, 2));
}

void dfs(int loc){
    vis[loc] = 1;
    if(nodes[loc].x + D >= 50 || nodes[loc].y + D >= 50|| nodes[loc].x - D <= -50|| nodes[loc].y - D <= -50){
        flag = true;
        return;
    }
    if(loc == 0){
        for(int ii = 1; ii <= N; ii++){
            if(!vis[ii] && dis_loc_ii(loc, ii) <= D + 7.5){
                dfs(ii);
            }
        }
    }else{
        for(int ii = 1; ii <= N; ii++){
            if(!vis[ii] && dis_loc_ii(loc, ii) <= D){
                dfs(ii);
            }
        }
    }

}

//这个用深搜做
int main(){
    cin >> N >> D;
    fill(vis, vis + MaxSize, 0);
    for(i = 1; i <= N; i++){
        cin >> nodes[i].x;
        cin >> nodes[i].y;
    }
    dfs(0);
    if(flag){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}