#include<iostream>
#include<math.h>
#include<iomanip>
#define MIN_S 1e-6

using namespace std;

double a3, a2, a1, a0;
double a, b;
double ans1, ans2, ans3;
double finans;

double f(double num){
    return a3 * pow(num, 3) + a2 * pow(num, 2) + a1 * num + a0;
}

int main(){
    cin >> a3 >> a2 >> a1 >> a0;
    cin >> a >> b;
    while(true){
        ans1 = f(a);
        ans2 = f(b);
        ans3 = f((a + b) / 2);
        // cout << ans1 << " |  " << ans2 << " | " << ans3 << endl;
        if(abs(ans3 - 0.0) < MIN_S || abs(a - b) < MIN_S){
            finans = (a + b) / 2;
            break;
        }
        if(abs(ans1 - 0.0) < MIN_S){
            finans = a;
            break;
        }
        if(abs(ans2 - 0.0) < MIN_S){
            finans = b;
            break;
        }
        if(ans1 * ans2 < 0){
            if(ans1 * ans3 < 0){
                a = a;
                b = (a + b) / 2;
            }else if(ans2 * ans3 < 0){
                a = (a + b) / 2;
                b = b;
            }
        }
    }
    cout << setprecision(2) << fixed << finans;
    return 0;
}