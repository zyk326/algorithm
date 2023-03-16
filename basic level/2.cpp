#include<iostream>
#include<regex>

using namespace std;

string str;
int point = 0;
regex reg("[0-9\\.]");
regex reg1("[\\+\\-\\*\\/\\(\\)]");
bool flag = true;

string getnum(){
    string buf;
    string numb;
    // int numbn;
    while(str[point] != '\0'){
        buf = str.substr(point, 1);
        if(!regex_match(buf, reg)){
            if((!flag || point == 0) && (buf == "-" || buf == "+")){
                numb += buf;
                flag = true;
            }else{  
                break;
            }
        }else{
            numb += buf;
            flag = true;
        }
        point++;
    }
    // numbn = atoi(numb.c_str());
    return numb;
}

int main(){
    cin >> str;
    string buf;
    while(str[point] != '\0'){
        buf = str.substr(point, 1);
        if(regex_match(buf, reg1)){
            if(buf == "("){
                flag = false;
            }
            if((!flag || point == 0) && (buf == "-" || buf == "+")){
                cout << getnum() << endl;
            }else{
                cout << buf << endl;
                point++;
            }
        }else{
            cout << getnum() << endl;
        }         
    }
    return 0;
}