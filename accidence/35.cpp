#include<iostream>
#include<queue>

using namespace std;

int alcoholJ, alcoholY;
int N;
int DJ = 0, DY = 0;
bool WinJ, WinY;

struct guess{
    int JSpoke;
    int JH;
    int Yspoke;
    int YH;
};

guess buf;
queue <guess>qg;


int i;

int main(){
    cin >> alcoholJ >> alcoholY;
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> buf.JSpoke >> buf.JH >> buf.Yspoke >> buf.YH;
        qg.push(buf);
    }
    for(i = 0; i < N; i++){
        WinJ = false;
        WinY = false;
        buf = qg.front();
        qg.pop();
        if(buf.JSpoke + buf.Yspoke == buf.JH){
            WinJ = false;
        }else{
            WinJ = true;
        }
        if(buf.JSpoke + buf.Yspoke == buf.YH){
            WinY = false;
        }else{
            WinY = true;
        }

        if(WinJ != WinY){
            // cout << "in " << endl;
            if(!WinJ){
                DJ++;
            }
            if(!WinY){
                DY++;
            }
        }
        // cout << DJ << "    ---   " << DY << endl;
        if(DJ > alcoholJ){
            cout << "A" << endl << DY;
            break;
        }
        if(DY > alcoholY){
            cout << "B" << endl << DJ;
            break;
        }
    }
    return 0;
}