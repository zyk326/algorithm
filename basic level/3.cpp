#include<iostream>
#include<algorithm>

using namespace std;

string str;
string ruleDW[5] = {"", "", "S", "B", "Q"};
int len, point;
string ans;
int times = 0;

string deal(string subs, int times){
    int po = 0;
    while(po < subs.length()){
        if(subs[po] == '0' && subs.length() != 1){
            subs[po] = '-';
        }else{
            break;
        }
        po++;
    }
    reverse(subs.begin(), subs.end());
    po = 0;
    string zeroti = "";
    while(po < subs.length()){
        if(subs[po] == '0'){
            zeroti += "-";
        }else{
            break;
        }
        po++;
    }
    if(zeroti.length() > 1){
        subs = subs.substr(zeroti.length() - 1);
        zeroti = zeroti.substr(1);
        subs = zeroti + subs;
    }
    string subans;
    int subpo = 0;
    int sublen = subs.length();    
    while(subpo < subs.length()){
        if(subs[subpo] != '-'){
            subans += (char)(subs[subpo] + 49);
            // subans += (char)(subs[subpo]);
            if((char)(subs[subpo]) != '0'){
                subans += ruleDW[sublen - subpo];
            }
        }
        subpo++;
    }
    if(times == 1){
        subans += "W";
    }else if(times == 2){
        subans += "Y";
    }
    return subans;
}

int main(){
    cin >> str;
    len = str.length();
    reverse(str.begin(), str.end());
    while(point < len){
        if(len - point < 4){
            ans = deal(str.substr(point, len - point), times) + ans;
        }else{
            ans = deal(str.substr(point, 4), times) + ans;
        }
        times++;
        point += 4;
    }
    cout << ans;
    return 0;
}