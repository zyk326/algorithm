#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int point;
int i, j;
map<string, string>mss1;
map<string, string>mpf;
vector<string>mss2;
int doed[100001];
vector<string>::iterator vsi;
string buf1, buf2;

int main(){
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> buf1;
        cin >> buf2;
        mss1[buf1] = buf2;
        mss1[buf2] = buf1;
    }
    cin >> M;
    for(i = 0; i < M; i++){
        cin >> buf1;
        mss2.push_back(buf1);
    }
    int kk, mm;
    for(i = 0; i < M; i++){
        kk = atoi(mss2[i].c_str());
        // cout << kk << endl;
        if(doed[kk] == 0){
            doed[kk] = 1;
            vsi = find(mss2.begin(), mss2.end(), mss1[mss2[i]]);
            if(vsi == mss2.end()){
                mss2[point++] = mss2[i];
            }else{
                // cout << *vsi;
                mm = distance(mss2.begin(), vsi); 
                mm = atoi(mss2[mm].c_str());
                doed[mm] = 1;
            }
        }
    }
    sort(mss2.begin(), mss2.begin() + point);
    cout << point << endl;
    for(i = 0; i < point; i++){
        if(i == 0)
            cout << mss2[i];
        else{
            cout << " " << mss2[i];
        }
    }
    return 0;
}