#include<iostream>
#include<map>

using namespace std;

int N;
int point;
int i, j;
map <int, int>mii;

int main(){
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> point;
        mii[point]++;
    }
    for(auto ii : mii){
        cout << ii.first << ":" << ii.second << endl;
    }
    return 0;
}