#include<iostream>
#include<algorithm>
#include<regex>

using namespace std;

int times[4];
int point, sump;
regex reg("[GPLT]");
string buf;
string str;

int main(){
    cin >> str;
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    while(str[point] != '\0'){
        buf = str.substr(point, 1);
        if(regex_match(buf, reg)){
            if(buf == "G"){
                times[0]++;
                sump++;
            }
            if(buf == "P"){
                times[1]++;
                sump++;
            }
            if(buf == "L"){
                sump++;
                times[2]++;
            }
            if(buf == "T"){
                sump++;
                times[3]++;
            }
        }
        point++;
    }
    while(sump > 0){
        if(times[0] > 0){
            sump--;
            times[0]--;
            cout << "G";
        }
        if(times[1] > 0){
            sump--;
            times[1]--;
            cout << "P";
        }
        if(times[2] > 0){
            sump--;
            times[2]--;
            cout << "L";
        }
        if(times[3] > 0){
            sump--;
            times[3]--;
            cout << "T";
        }
    }
    return 0;
}