#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 505, M = 5005;
// 图的邻接矩阵 
int edge[N][N];
// 遍历图的标记数组 
bool isVisit[N]; 
// 标记城市的状态：(0: 未被攻占，-1: 被攻占) 
int city[N];
int n, m, k;

// 从顶点 x 开始深度优先遍历其所在的连通图 
void dfs(int x) {
    if(isVisit[x]) {
        return ;
    }
    isVisit[x] = true;
    for(int i = 0; i < n; i++) {
        if(edge[x][i] == 1) {
            dfs(i);
        }
    }
}

int main() {
    // 当前图的连通子图个数 
    int counnt = 0;
    cin >> n >> m;
    int s, e;
    // 邻接矩阵初始化 
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        edge[s][e] = edge[e][s] = 1;
    }
    // 对所有的顶点都遍历一次，求出当前图的连通子图个数 
    for(int i = 0; i < n; i++) {
        // 如果顶点 i 未被访问，证明顶点 i 在一个新的连通子图中 
        if(!isVisit[i]) {
            dfs(i);
            counnt++;
        }
    }
    // lastCount 记录图的上一次状态时的连通子图个数 
    int x, lastCount;
    cin >> k;
    for(int i = 0; i < k; i++) {
        scanf("%d", &x);
        // 城市 x 被攻占，标记 
        city[x] = -1;
        // 删除被攻占城市和其他城市的边 
        for(int j = 0; j < n; j++) {
            if(edge[j][x] == 1) {
                edge[j][x] = edge[x][j] = 0;
            }
        }
        // 初始化顶点访问标记用于求出图的连通子图个数 
        memset(isVisit, 0, sizeof(isVisit));
        lastCount = counnt;
        counnt = 0; 
        for(int j = 0; j < n; j++) {
            if(!isVisit[j]) {
                dfs(j);
                counnt++;
            }
        }
        // 如果连通子图的个数相比上一次增加了 2 个或者两个以上，发出红色警报 
        if (lastCount + 2 <= counnt) {
            printf("Red Alert: City %d is lost!\n", x);
            // 这里调用了 algorithm 中的函数 count，求出给定范围中给定的值的个数，这里表示所有城市都被攻占 
        } else if(count(city, city+n, -1) == n){
            printf("City %d is lost.\n", x);
            printf("Game Over.\n");
            return 0;
        } else {
            printf("City %d is lost.\n", x);
        }
    }

    return 0;
} 
