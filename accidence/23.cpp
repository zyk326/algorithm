#include<iostream>

using namespace std;

string str;
int h, m, s;
int ss;

int pluss(int &before, int add){
    int buf = 0;
    buf = (before + add) / 60;
    before = (before + add) % 60;
    return buf;
}

void format_zero(string &a){
    if(a.length() == 1)
        a = "0" + a;
}

void format(){
    string hh, mm, ss;
    hh = to_string(h);
    mm = to_string(m);
    ss = to_string(s);
    format_zero(hh);
    format_zero(mm);
    format_zero(ss);
    cout << hh << ":" <<  mm << ":" << ss;
}

int main(){
    cin >> str;
    h = atoi(str.substr(0, 2).c_str());
    m = atoi(str.substr(3, 2).c_str());
    s = atoi(str.substr(6, 2).c_str());
    cin >> ss;
    pluss(h, pluss(m, pluss(s, ss)));
    if(h > 23)
        h -= 24;
    format();
    return 0;
}