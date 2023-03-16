#include<iostream>
#include<iomanip>
#define MaxSize 100

using namespace std;

int N;

struct Stu{
    string number;
    string name;
    int course;
};
Stu students[MaxSize];

double avg(){
    double ans = 0.0;
    int sum = 0;
    int i = 0;
    while(i < N){
        sum += students[i].course;
        i++;
    }
    ans = sum * 1.0 / N;
    return ans;
}

int main(){
    cin >> N;
    int i = 0;
    while(i < N){
        cin >> students[i].number;
        cin >> students[i].name;
        cin >> students[i].course;
        i++;
    }
    double avgc = avg();
    cout << setprecision(2) << fixed << avgc << endl;
    i = 0;
    while(i < N){
        if(students[i].course < avgc){
            cout << students[i].name << " " << students[i].number << endl;
        }
        i++;
    }
    return 0;
}