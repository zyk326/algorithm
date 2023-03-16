#include<iostream>
#include<queue>

using namespace std;

int N, M;
int buf, i, j;

struct stu{
    string numb;
    int test;
    int cour;
};
stu s[1001];
queue <stu>qs;

int main(){
    cin >> N;
    for(i = 0 ; i < N; i++){
        cin >> s[i].numb;
        cin >> s[i].test;
        cin >> s[i].cour;
    }
    cin >> M;
    for(i = 0; i < M; i++){
        cin >> buf;
        for(j = 0; j < N; j++){
            if(s[j].test == buf){
                qs.push(s[j]);
                break;
            }
        }
    }
    while(!qs.empty()){
        cout << qs.front().numb << " " << qs.front().cour << endl;
        qs.pop();
    }
    return 0;
}