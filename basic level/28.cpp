#include<iostream>
#include<vector>

using namespace std;

int N, M;
int procession[101];
int i, j;
int point = 1;
vector<int> sits[101];
int sum = 0;

int main(){
    cin >> N;
    M = N;
    for(i = 0; i < N; i++){
        cin >> procession[i];
        procession[i] *= 10;
        sum += procession[i];
    }
    while(point <= sum){
        for(i = 0; i < N; i++){
            if(procession[i] > 0){
                sits[i].push_back(point++);
                if(M == 1){
                    point++;
                    sum++;
                }
                procession[i]--;
                if(procession[i] == 0){
                    M--;
                }
            }
        }
    }
    for(i = 0; i < N; i++){
        cout << "#" << i + 1 << endl;
        for(j = 0; j < sits[i].size(); j++){
            if(j % 10 == 0 && j != sits[i].size() - 1 && j != 0){
                cout << endl;
            }
            if(j % 10 == 0){
                cout << sits[i][j];
            }else{
                cout << " " << sits[i][j];
            }
            
        }
        cout << endl;
    }
    return 0;
}
