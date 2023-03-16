#include<iostream>
#include<map>

using namespace std;

int N;
int point;
int i, j;
map<int, int> mii;

int main(){
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> point;
        mii[point]++;
    }
    cout << mii.begin()->first << " " << mii.begin()->second << endl << mii.rbegin()->first << " " << mii.rbegin()->second;
    return 0;
}