#include<iostream>

using namespace std;

int ban, accompany, person1, person2;

int main(){
    cin >> ban >> accompany >> person1 >> person2;
    if(person1 < ban && person2 < ban){
        cout << person1 << "-N " << person2 << "-N" << endl;
        cout << "zhang da zai lai ba";
    }else if(person1 >= ban && person2 >= ban){
        cout << person1 << "-Y " << person2 << "-Y" << endl;
        cout << "huan ying ru guan";
    }else{
        if(person1 < ban){
            if(person2 >= accompany){
                cout << person1 << "-Y " << person2 << "-Y" << endl;
                cout << "qing 2 zhao gu hao 1";
            }else{
                cout << person1 << "-N " << person2 << "-Y" << endl;
                cout << "2: huan ying ru guan";
            }
        }else if(person2 < ban){
            if(person1 >= accompany){
                cout << person1 << "-Y " << person2 << "-Y" << endl;
                cout << "qing 1 zhao gu hao 2";
            }else{
                cout << person1 << "-Y " << person2 << "-N" << endl;
                cout << "1: huan ying ru guan";
            }
        }
    }
    return 0;
}