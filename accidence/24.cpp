#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int i;
int buf;

struct Dig{
    int num;
    int times;
};
vector <Dig>vc;
vector <Dig> ::iterator t;
Dig ele;

bool finda(int na){
    for(t = vc.begin(); t != vc.end(); ++t){
        if(t->num == na)
            return true;
    }
    return false;
}

void init(){
    for ( i = 0; i < N; i++){
        cin >> ele.num;
        ele.times = 1;
        if(finda(ele.num)){
            t->times++;
        }else{
            vc.push_back(ele);
        }
    }
}

void findd(){
    int maxN = vc.begin()->num, maxT = vc.begin()->times;
    for(auto it = vc.begin(); it != vc.end(); ++it){
        if(it->times > maxT){
            maxN = it->num;
            maxT = it->times;
        }
    }
    cout << maxN << " " << maxT << endl;
}

int main(){
    cin >> N;
    init();
    // for(auto it = vc.begin(); it != vc.end(); ++it){
    //     cout << it->num  << "  " << it->times << endl;
    // }
    findd();
    return 0;
}
