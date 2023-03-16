#include<iostream>
#include<regex>

using namespace std;

int N;
int i;
string str;
string ans[101];
regex regS("[a-z]");

bool deal(string swork){
    int point = 0;
    string buf = swork.substr(point, 1);
    point++;
    // cout << buf << " -- " << point << endl;
    while(swork[point] != '\0'){
        if(regex_match(buf, regS)){
            // cout << swork[point] << " - " << (char)(swork[point - 1] - 32) << " | " << (char)(swork[point - 1] - 1);
            if(swork[point] != (char)(swork[point - 1] - 32) && swork[point] != (char)(swork[point - 1] - 1)){
                return false;
            }
        }else{
            // cout << swork[point] << " -* " << swork[point - 1] + 32 << " | " << (char)(swork[point - 1] + 1);
            if(swork[point] != (char)(swork[point - 1] + 32) && swork[point] != (char)(swork[point - 1] + 1)){
                return false;
            }
        }
        // cout << endl;
        buf = swork.substr(point, 1);
        point++;
    }
    return true;
}

int main(){
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> str;
        if(deal(str)){
            ans[i] = "Y";
        }else{
            ans[i] = "N";
        }
    }
    for(i = 0; i < N; i++){
        cout << ans[i] << endl;
    }
    return 0;
}