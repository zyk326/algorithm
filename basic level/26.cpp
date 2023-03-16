#include<iostream>

using namespace std;

int N;
int point;
int i, j;
string map[11];
int K;
struct doit{
    int x1, y1, x2, y2;
}doits[55];
int bad = 0;
int operate = 0;

bool deal(doit opt){
    // cout <<" in " << opt.x1 << opt.y1 << opt.x2 << opt.y2 << endl;
    if(map[opt.x1][2 * (opt.y1 - 1)] == map[opt.x2][2 * (opt.y2 - 1)] && map[opt.x1][2 * (opt.y1 - 1)] != '*' && map[opt.x2][2 * (opt.y2 - 1)] != '*'){
        map[opt.x1][2 * (opt.y1 - 1)] = '*';
        map[opt.x2][2 * (opt.y2 - 1)] = '*';
        // cout << "x1: " << opt.x1 << " y1: " << 2 * (opt.y1 - 1) << " x2: " << opt.x2 << " y2: " << 2 * (opt.y2 - 1) << endl;
        return true;
    }else{
        return false;
    }
}

void output(){
    for(j = 1; j <= 2 * N; j++){
        if(j == 1){
            cout << map[j];
        }else{
            cout << endl << map[j];

        }
    }
}

void init(){
    cin >> N;
    getline(cin, map[0]);
    for(i = 1; i <= N * 2; i++){
        getline(cin, map[i]);
    }
    cin >> K;
    for(i = 0; i < K; i++){
        cin >> doits[i].x1;
        cin >> doits[i].y1;
        cin >> doits[i].x2;
        cin >> doits[i].y2;
    }
}

int main(){
    init();
    for(i = 0; i < K; i++){
        if(i != 0){
            cout << endl;
        }
        if(deal(doits[i])){
            operate++;
            if(operate == N * N * 2){
                cout << "Congratulations!";
                break;
            }else{
                output();
            }
        }else{
            bad++;
            cout << "Uh-oh";
            if(bad == 3){
                cout << endl << "Game Over";
                break;
            }
        }
    }
    return 0;
}