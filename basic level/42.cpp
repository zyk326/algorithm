#include<iostream>
#include<algorithm>

using namespace std;

int N;
int point = 0;
int i, j;
int goods[1000];
int storehouse[1000];
int ans[1000];

int main(){
    cin >> N;
    fill_n(storehouse, 1000, 100);
    for(i = 0; i < N; i++){
        cin >> goods[i];
    }
    for(i = 0; i < N; i++){
        j = 0;
        while(storehouse[j] < goods[i]){
            j++;
        }
        point = j > point ? j : point;
        storehouse[j] -= goods[i];
        ans[i] = j;
    }
    for(i = 0; i < N; i++){
        cout << goods[i] << " " << ans[i] + 1 << endl;
    }
    cout << point + 1;
    return 0;
}