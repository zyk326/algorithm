#include<iostream>
#include<iomanip> //用于输出的系数格式化
#include<map>
#include<math.h>

using namespace std;

struct item{
    int e;
    double c;
}p[10000], ans[10000];

int N;
int point;
int i, j;
map<int, double> q;
int frontE, ant;

int main(){
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> point;
        cin >> q[point];
        if(i == 0){
            frontE = point;
        }
    }
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> p[i].e >> p[i].c;
    }
    while(frontE >= p[0].e){
        //减法
        double ch = q[frontE] / p[0].c; // 系数比
        int dif = frontE - p[0].e; // 指数比
        if(fabs(ch) >= 0.05){
            ans[ant].e = dif;
            ans[ant++].c = ch;
            for(i = 0; i < N; i++){
                q[p[i].e + dif] -= p[i].c * ch;
            }
        }else{
            frontE--;
        }        
        while(frontE >= p[0].e && fabs(q[frontE]) < 0.05){
            frontE--;
        }
    }
    cout << ant;
    if(!ant){
        cout << " 0 0.0";
    }
    for(i = 0; i < ant; i++){
        cout << setprecision(1) << fixed << " " << ans[i].e << " " << ans[i].c;
    }
    cout << endl;
    ant = 0;
    while(frontE >= 0){
        if(fabs(q[frontE]) >= 0.05){
            ans[ant].e = frontE;
            ans[ant++].c = q[frontE];
        }
        frontE--;
    }
    cout << ant;
    if(!ant){
        cout << " 0 0.0";
    }
    for(i = 0; i < ant; i++){
        cout << setprecision(1) << fixed << " " << ans[i].e << " " << ans[i].c;
    }
    return 0;
}