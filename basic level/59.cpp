#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int D, P;
int point;
int i, j;

struct peo{
    string name;
    string id;
    int healthy;
    string time;
    bool operator <(peo const &a) const{
        if(time < a.time){
            return true;
        }else{
            return false;
        }
    }
};

vector<peo> vpans;
map<string, string> mpsh;
peo buf;
map<string, int>mss;

void deal(){
    int T, S;
    vector<peo> vps;
    cin >> T >> S; //T个申请，S个口罩
    for(j = 0; j < T; j++){
        cin >> buf.name >> buf.id >> buf.healthy >> buf.time;
        if(buf.id.length() == 18){
            vps.push_back(buf);
            if(buf.healthy == 1){
                mpsh[buf.name] = buf.id;
            }
        }
        else{
            T--;
            j--;
        }
    }
    sort(vps.begin(), vps.end());    
    string bufs;
    // cout << "ready for while" << endl;
    while(T > 0 && S > 0){
        // cout << " -in- ";
        buf = vps.front();
        bufs = buf.name;
        // cout << "now bufs name is : " << bufs << "now day is : " << mss[bufs] << endl;
        if(mss[bufs] <= 0){
            // cout << "pushed the : " << bufs << endl;
            mss[bufs] = P + 1;
            vpans.push_back(buf);
            S--;
        }
        T--;
        vps.erase(vps.begin());    
    }
    for(auto & ii : mss){
        ii.second--;
    }
}

int main(){
    cin >> D >> P; //D个数据块，P是间隔
    for(i = 0; i < D; i++){
        deal();
    }
    for(auto jj : vpans){
        cout << jj.name << " " << jj.id << endl;
    }
    for(auto iii : mpsh){
        cout << iii.first << " " << iii.second << endl;
    }
    return 0;
}