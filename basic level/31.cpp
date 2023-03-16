#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

int N;
int point;
int i, j;
struct peo{
    string name;
    string bir;
    string numb;
    bool operator <(peo const & a)const{
        if(bir < a.bir){
            return true;
        }else{
            return false;
        }
    }
}peos[11];

int main(){
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> peos[i].name;
        cin >> peos[i].bir;
        cin >> peos[i].numb;
    }
    sort(peos, peos + N);
    for(i = 0; i < N; i++){
        cout << peos[i].name << " " << peos[i].bir << " " << peos[i].numb << endl;
    }
    return 0;
}