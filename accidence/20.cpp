#include<iostream>

using namespace std;

int days[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string times;
string year;
string month;
string day;
int y, m, d;
int ans = 0;

bool run(int ye){
    if(ye % 400 == 0 || (ye % 4 == 0 && ye % 100 != 0))
        return true;
    else
        return false;
}

int main(){
    cin >> times;
    year = times.substr(0, 4);
    month = times.substr(5, 2);
    day = times.substr(8, 2);
    // cout << year << " " << month << " " << day << endl;
    y = atoi(year.c_str());
    m = atoi(month.c_str());
    d = atoi(day.c_str());
    // cout << y << " " << m << " " << d << endl;
    m -= 1;
    if(m >= 2){
        if(run(y)){
            ans += 29;
        }else{
            ans += 28;
        }
    }
    while(m != 0){
        ans += days[m];
        m--;
    }
    ans += d;
    
    cout << ans;
    return 0;
}