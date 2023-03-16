#include<iostream>
#define MaxSize 1001

using namespace std;

string str;
int num[MaxSize];
int size = 0;
bool first = false;
int sum = 0;
int i = 0;

void getNums(){
    int buf = 0;
    while(str[i] != '\0'){
        if(str[i] == ' '){
            // cout << buf << endl;
            if(buf % 2 == 1){
                sum += buf;
            }
            buf = 0;
            first = true;
            i++;
        }else if(str[i] == '-'){
            break;
        }else{
            if(first && str[i] == '0'){
                break;
            }else{
                first = false;
                buf *= 10;
                buf += str[i] - '0';
                i++;
            }
        }
    }
}

int main(){
    getline(cin, str);
    getNums();
    cout << sum;
    return 0;
}