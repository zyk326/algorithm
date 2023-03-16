#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int point;
int i, j;

struct timess{
    string strs;
    string stre;
    bool operator < (timess const &a) const{
        if(strs < a.strs){
            return true;
        }else{
            return false;
        }
    }
};
vector<timess>oris;

// void deal(timess &a, string buf){
//     // cout << buf << endl;
// }

int main(){
    cin >> N;
    string buf;
    getline(cin, buf);
    timess tib;
    for(i = 0; i < N; i++){
        getline(cin, buf);
        // deal(oris[i], buf);
        tib.strs = buf.substr(0, 8);
        tib.stre = buf.substr(11, 8);
        oris.push_back(tib);
    }
    sort(oris.begin(), oris.end());
    for(i = 0; i < N; i++){
        if(i == 0){
            if(oris[i].strs != "00:00:00"){
                cout << "00:00:00 - " << oris[i].strs << endl;
            }
        }
        if(i == N - 1){
            if(oris[i].stre != "23:59:59"){
                cout << oris[i].stre << " - 23:59:59" << endl;
            }
        }
        if(i != N - 1 && oris[i].stre != oris[i + 1].strs){
            cout << oris[i].stre << " - " << oris[i + 1].strs << endl;
        }
    }
    return 0;
}