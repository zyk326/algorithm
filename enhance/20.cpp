#include<iostream>
#include<algorithm>

#define MaxSize 10001

using namespace std;

//原始数据
struct DATA{
    int id, fa, ma, num, area;
    int child[10];//?
}a[MaxSize];

//输出数据结构
struct node{
    int id, people;
    double num, area;
    bool flag = false;
}b[MaxSize];

//并查集
int father[MaxSize];
bool visit[MaxSize];
int k, cnt = 0;

int find(int x){
    while(x != father[x]){
        x = father[x];
    }
    return x;
}

void Union(int a, int b){
    int faA = find(a);
    int faB = find(b);
    if(faA > faB) father[faA] = faB;
    else if(faA < faB) father[faB] = faA;
}

int cmp(node a, node b){
    if(a.area != b.area)
        return a.area > b.area;
    return a.id < b.id;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < MaxSize; i++){
        father[i] = i;
    }
    for(int i = 0; i < n; i++){
        cin >> a[i].id >> a[i].fa >> a[i].ma >> k;
        visit[a[i].id] = 1;
        if(a[i].fa != -1){
            visit[a[i].fa] = 1;
            Union(a[i].fa, a[i].id); 
        }
        if(a[i].ma != -1){
            visit[a[i].ma] = 1;
            Union(a[i].ma, a[i].id);
        }
        for(int j = 0; j < k; j++){
            cin >> a[i].child[j];
            visit[a[i].child[j]] = 1;
            Union(a[i].child[j], a[i].id);
        }
        cin >> a[i].num >> a[i].area;
    }
    for(int i = 0; i < n; i++){
        int id = find(a[i].id);
        b[id].id = id;
        b[id].num += a[i].num;
        b[id].area += a[i].area;
        b[id].flag = 1;
    }
    for(int i = 0; i < MaxSize; i++){
        if(visit[i]) b[find(i)].people++;
        if(b[i].flag) cnt++;
    }
    for(int i = 0; i < MaxSize; i++){
        if(b[i].flag){
            b[i].num = 1.0 * b[i].num / b[i].people;
            b[i].area = 1.0 * b[i].area / b[i].people;
        }
    }
    sort(b, b + MaxSize, cmp);
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++){
        printf("%04d %d %.3f %.3f\n", b[i].id, b[i].people, b[i].num, b[i].area);
    }
    return 0;
}