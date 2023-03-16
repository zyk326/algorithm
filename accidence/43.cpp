#include<iostream>
#include<vector>
#include<algorithm>
#define MaxSize 1001

using namespace std;

int N;
vector<int> vi;
int X;
int buf;
vector<int>::iterator vii;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> buf;
        vi.push_back(buf);
    }
    cin >> X;
    vi.push_back(X);
    sort(vi.begin(), vi.end());
    for(vii = vi.begin(); vii != vi.end(); vii++){
        cout << *vii << " ";
    }
    return 0;
}