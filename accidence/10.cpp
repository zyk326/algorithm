#include<iostream>
#include<math.h>

using namespace std;

int card, push;

int main(){
    cin >> card >> push;
    if(push % 2 == 0)
        cout << "0 ";
    else 
        cout << "1 ";
    card = card * pow(2, push / 2);
    cout << card;
    return 0;
}