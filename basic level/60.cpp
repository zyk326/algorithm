#include<iostream>
#include<map>
#include<regex>

using namespace std;

string str1, str2;
int point;
int i, j;

map<int, int>mii;

void init(){
    str1 = str1.substr(1, str1.length() - 2);
    str2 = str2.substr(1, str2.length() - 2);
    // cout << str1 << " - " << str2 << endl;
    while(str1[point] != '\0' && point < str1.length()){
        if(str1[point] == '"'){
            mii[(int)str1[point + 1]] += atoi(str1.substr(point + 4, 1).c_str());
            point += 5;
        }else{
            mii[atoi(str1.substr(point, 1).c_str())] += atoi(str1.substr(point + 2, 1).c_str());
            point += 3;
        }
        point++;
    }
    point = 0;
    while(str2[point] != '\0' && point < str2.length()){
        if(str2[point] == '"'){
            mii[(int)str2[point + 1]] += atoi(str2.substr(point + 4, 1).c_str());
            point += 5;
        }else{
            mii[atoi(str2.substr(point, 1).c_str())] += atoi(str2.substr(point + 2, 1).c_str());
            point += 3;
        }
        point++;
    }
    cout << "{";
    for(auto ii = mii.begin(); ii != mii.end(); ii++){
        if(ii->first > 10){
            cout << "\"" << (char)ii->first << "\"";
        }else{
            cout << ii->first;
        }
        cout << ":" << ii->second;
        if(++ii != mii.end()){
            cout << ",";
        }
        ii--;
    }
    cout << "}";
}

int main(){
    getline(cin, str1);
    getline(cin, str2);
    // cout << str1 << "  " << str2 << endl;
    init();
    return 0;
}