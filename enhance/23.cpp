#include<iostream>

typedef long long ll;
#define inf 0x3f3f3f3f
#define MaxSize 510

using namespace std;

int vis[MaxSize];
int N, M, S, D;
int g[MaxSize][MaxSize], p[MaxSize][MaxSize];//g是路线图，p是花费图
struct Node{
    int dis, money;
}cost[MaxSize];//到下标点时花费的距离和花费
int i, j;
int a, b, c, d;

void dijkstra(int fr, int to){
    cost[fr].dis = cost[fr].money = 0;
    for(int ii = 0; ii < N - 1; ii++){
        int u = 0, dis = inf;
        for(int jj = 0; jj < N - 1; jj++){//贪心的思想，找到最小距离的呆搜索结点
            if(!vis[jj] && cost[jj].dis < dis){
                dis = cost[jj].dis;
                u = jj;
            }
        }
        vis[u] = 1;
        for(int v = 0; v < N; v++){
            if(g[u][v] < inf){
                if(cost[v].dis > dis + g[u][v]){
                    cost[v].dis = dis + g[u][v];
                    cost[v].money = cost[u].money + p[u][v];
                }else if(cost[v].dis == dis + g[u][v]){
                    cost[v].money = min(cost[v].money, cost[u].money + p[u][v]);
                }
            }
        }
    }
    cout << cost[to].dis << " " << cost[to].money;
}

int main(){
    cin >> N >> M >> S >> D;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            g[i][j] = inf;
        }
        cost[i].dis = cost[i].money = inf;
        g[i][i] = 0;
    }
    for(i = 0; i < M; i++){
        cin >> a >> b >> c >> d;
        g[a][b] = g[b][a] = c;
        p[a][b] = p[b][a] = d;
    }
    dijkstra(S, D);
    return 0;
}