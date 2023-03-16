#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int N, M, K;
queue <int>qi[1001];
queue <int>sizes;
stack <int>si; // box
int point; //number of tree
int i, j;

int main(){
    cin >> N >> M >> K;
    for(i = 0; i < N; i++){
        cin >> j;
        sizes.push(j);
    }
    // qi[point].push(sizes.front());
    // sizes.pop();
    while(!si.empty() || !sizes.empty()){
        // cout << "now point is : " << point << endl;
        if(qi[point].size() >= K){
            point++;
        }
        if(!si.empty()){
            i = si.top(); //盒子
            // cout << "now si top is : " << i << endl;
            if(qi[point].empty() || qi[point].back() >= i){
                // cout << " in qi[" << point << "]" << endl;
                qi[point].push(i);
                si.pop();
                continue;
            }else if(qi[point].back() < i){ //check the conveger
                if(sizes.empty()){
                    point++;
                    continue;
                }else{
                    if(sizes.front() > qi[point].back()){
                        if(si.size() >= M){
                            point++;
                            continue;
                        }else{
                            si.push(sizes.front());
                            sizes.pop();
                            continue;
                        }
                    }else{
                        qi[point].push(sizes.front());
                        sizes.pop();
                        continue;
                    }
                }
            }
        }else{
            if(!qi[point].empty()){
                if(sizes.front() > qi[point].back()){
                    si.push(sizes.front());
                    sizes.pop();
                    continue;
                }else{
                    qi[point].push(sizes.front());
                    sizes.pop();
                    continue;
                }
            }else{
                qi[point].push(sizes.front());
                sizes.pop();
                continue;
            }
        }
    }
    for(i = 0; i <= point; i++){
        while(!qi[i].empty()){
            if(qi[i].size() == 1){
                cout << qi[i].front();
            }else{
                cout << qi[i].front() << " ";
            }
            qi[i].pop();
        }
        cout << endl;
    }
    return 0;
}