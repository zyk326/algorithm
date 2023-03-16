#include<iostream>
#define MaxSize 1001

using namespace std;

int N;
int stu[MaxSize];
int A, B, C, D, E;

void judge(int course){
    if(course >= 90)
        A++;
    else if(course >= 80 && course < 90)
        B++;
    else if(course >= 70 && course < 80)
        C++;
    else if(course >= 60 && course < 70)
        D++;
    else if(course < 60)
        E++;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> stu[i];
        judge(stu[i]);
    }
    cout << A << " " << B << " " << C << " " << D << " " << E << endl;
    return 0;
}