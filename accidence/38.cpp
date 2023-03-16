// 在得到全班学生的排名后，在当前尚未分组的学生中，
// 将名次最靠前的学生与名次最靠后的异性学生分为一组。

#include<iostream>
#include<list>

using namespace std;

int N;

struct Stu{
    int gender;
    string name;
};
list <Stu>a;
Stu buf, bufr;
list<Stu>::iterator lsi;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> buf.gender;
        cin >> buf.name;
        a.push_back(buf);
    }
    while(N > 0){
        cout << a.front().name;
        // a.pop_front();
        lsi = a.end();
        lsi--;
        // cout << a.front().gender << " " << a.front().name << endl;
        // cout << "| " << lsi->gender << "| " << lsi->name << endl;
        // cout << endl;

        while(lsi->gender == a.front().gender){
            // cout << lsi->gender << " " << lsi->name << endl;
            // cout << "-" << endl;
            lsi--;
        }
        cout << " " << lsi->name << endl;
        a.erase(lsi);
        a.pop_front();
        N -= 2;
    }
    return 0;
}