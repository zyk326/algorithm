#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

int N, i, j;

struct peo{
    string name;
    int num;
    bool operator <(peo const &a)const{
        if(num < a.num){
            return true;
        }else{
            return false;
        }
    }
};
vector <peo> vp;
peo buf;
int sumnum = 0;
double avgnum;
vector<peo>::iterator vpi;
int point;

int main(){
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> buf.name;
        cin >> buf.num;
        sumnum += buf.num;
        vp.push_back(buf);
    }
    avgnum = sumnum * 1.0 / N / 2;
    // cout << avgnum << endl;
    sort(vp.begin(), vp.end());
    for(auto vpi = vp.begin(); vpi != vp.end(); vpi++){
        if(vpi->num * 1.0 >= avgnum){
            break;
        }else{
            point++;
        }
        // cout << vpi->name << " " << vpi->num << endl;
    }
    // cout << vpi->name << " " << vpi->num << endl;
    // if(vpi == vp.begin()){
    //     cout << setprecision(0) << fixed << avgnum << vp.begin()->name;
    // }else if(vpi == vp.end()){
    //     --vpi;
    //     cout << setprecision(0) << fixed << avgnum << vpi->name;
    // }else{
    //     if(vpi->num * 1.0 - avgnum > (vpi - 1)->num * 1.0 - avgnum){
    //         cout << setprecision(0) << fixed << avgnum << (vpi-1)->name;
    //     }else{
    //         cout << setprecision(0) << fixed << avgnum << vpi->name;
    //     }
    // }
    cout << setprecision(0) << fixed << avgnum << " ";
    if(point == 0 || point == N - 1){
        cout << vp[point].name;
    }else{
        if(vp[point].num * 1.0 - avgnum > avgnum - vp[point - 1].num * 1.0){
            cout << vp[point - 1].name;
        }else{
            cout << vp[point].name;
        }
    }
    
    return 0;
}