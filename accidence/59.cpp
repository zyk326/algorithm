#include<iostream>
#include<regex>

using namespace std;

int M, N, i, j;
regex reg1(".*easy.*");
regex reg2(".*qiandao.*");
string str[31];
bool flag = false;

int main(){
    cin >> N >> M;
    getline(cin, str[0]);
    for(i = 0; i < N; i++){
        getline(cin, str[i]);
    }
    for(i = 0; i < N; i++){
        if(!regex_match(str[i], reg1) && !regex_match(str[i], reg2) ){
            if(M > 0){
                M--;
            }else{
                cout << str[i];
                flag = true;
                break;
            }
        }
    }
    if(!flag){
        cout << "Wo AK le";
    }
    return 0;
}