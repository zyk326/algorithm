#include<iostream>

using namespace std;

string str;
string ans;
int point = 0;
int times = 0;
int dois;

string rules[11] = {"0 ", "1,.?!", "2ABC", "3DEF", "4GHI", "5JKL", "6MNO", "7PQRS", "8TUV", "9WXYZ"};

int main(){
    getline(cin, str);
    str += ' ';
    string buf;
    buf = str.substr(0, 1);
    dois = atoi(buf.c_str());
    // cout << dois << endl;
    while(str[point] != '\0'){
        if(str[point] == ' '){
            // cout << dois << endl;
            int len = rules[dois].length();
            times = times % len;
            if(times == 0){
                times = len - 1;
            }else{
                times -= 1;
            }
            // cout << dois << " " << times << "   - " << point << "  -";
            // cout << rules[dois][times] << endl;
            ans += rules[dois][times];
            times = 0;
            buf = str.substr(++point, 1);
            dois = atoi(buf.c_str());
        }else{
            // cout << " in ";
            times++;
            point++;
        }
    }
    cout << ans ;
    return 0;
}