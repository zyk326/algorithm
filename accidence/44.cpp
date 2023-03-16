// 150 5 2 1

#include<iostream>

using namespace std;

struct way{
    int fi;
    int tw;
    int on;
};

int n;
way ww[31];
int point;
int i, j, k;
way buf;

void init(){
    for(i = 1; i <= 30; i++){
        for(j = 46; j > 0; j--){
            for(k = 53; k < 150; k++){
                if(5 * i + 2 * j + k == 150 && i + j + k == 100){
                    buf.fi = i;
                    buf.tw = j;
                    buf.on = k;
                    ww[point] = buf;
                    point++;
                }
            }
        }
    }
}

int main(){
    cin >> n;
    init();
    if(n > point){
        n = point;
    }
    for(i = 0; i < n; i++){
        cout << ww[i].fi << " " << ww[i].tw << " " << ww[i].on << endl;
    }
    return 0;
}