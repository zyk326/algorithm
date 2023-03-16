#include<iostream>
#include<algorithm>

using namespace std;

int N;
int point;
int i, j;
string str, ans1, ans2;
int exi[10];

string output(string ins){
    point = 0;
    while(ins[point] != '\0' && point <= ins.length()){
        if(point != ins.length() - 1){
            ins.insert(point + 1, ",");
        }
        point += 2;
    }
    return ins;
}

int main(){
    cin >> str;
    while(str[point] != '\0'){
        exi[str[point] - '0'] = 1;
        point++;
    }
    for(i = 0; i < 10; i++){
        if(exi[i] == 1){
            ans1 += to_string(i);            
        }
    }
    sort(ans1.begin(), ans1.end());
    reverse(ans1.begin(), ans1.end());
    cout << "int[] arr = new int[]{" << output(ans1) << "};" << endl;
    point = 0;
    while(str[point] != '\0'){
        for(i = 0; i < ans1.length(); i++){
            if(str[point] == ans1[i]){
                ans2 += to_string(i);
            }
        }
        point++;
    }
    cout << "int[] index = new int[]{" << output(ans2) << "};";
    return 0;
}