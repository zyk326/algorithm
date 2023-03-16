#include<iostream>
#include<iomanip>

using namespace std;

int A, B;
int ans = 0;
int tick = 0;
int sum = 0;

void show(int a){
    cout << setw(5)  << setfill(' ') << right << a;
}

int main(){
    cin >> A >> B;
    for(int i = A; i <= B; i++){
        sum += i;
        show(i);
        tick++;
        if(tick % 5 == 0 && i != B){//注意最后一个没有回车
            cout << endl;
        }
    }
    cout << endl << "Sum = " << sum;
    return 0;
}