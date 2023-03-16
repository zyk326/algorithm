#include<iostream>

using namespace std;

int N;
int n;

int main(){
    cin >> N;
    n = N;
    N = N % 5;
    if(N == 0 || N == 4){
        cout << "Drying in day " << n;
    }else{
        cout << "Fishing in day " << n;
    }
    return 0;
}