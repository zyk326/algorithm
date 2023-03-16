#include<iostream>
#include<map>

using namespace std;

int N;
int point;
int i, j;
map <int, int> mii;
string str;

int main(){
    cin >> N;
    while(N != -1){
        mii[N]++;
        cin >> N;
    }
    cin >> N;
    while(N != -1){
        mii[N]++;
        cin >> N;
    }
    for(auto ii : mii){
        for(i = 0; i < ii.second; i++){
            // cout << ii.first << "-";
            str += to_string(ii.first) + " ";
        }
    }
    str = str.substr(0, str.length() - 1);
    if(str.length() == 0){
        cout << "NULL";
    }else{
        cout << str;
    }
    return 0;
}