#include<iostream>
#include<queue>

using namespace std;

int num, N;
int point = 0;
int putNum = 0;
queue <int>qi;
bool flag = false;

int main(){
    cin >> num >> N;
    if(num < 0){
        cout << "Game Over";
    }else{
        while(putNum >= 0){
            cin >> putNum;
            if(putNum >= 0)
                qi.push(putNum);
        }
        while(!qi.empty()){
            point++;
            if(point > N){
                break;
            }
            int buff = qi.front();
            qi.pop();
            if(buff > num){
                cout << "Too big" << endl;
            }else if(buff < num){
                cout << "Too small" << endl;
            }else{
                if(point == 1){
                    cout << "Bingo!";
                }else if(point > 1 && point <=3){
                    cout << "Lucky You!";
                }else{
                    cout << "Good Guess!";
                }
                flag = true;
                break;
            }
        }
        if(!flag)
            cout << "Game Over";
    }
    return 0;
}