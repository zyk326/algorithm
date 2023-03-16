// 一个整数“犯二的程度”定义为该数字中包含2的个数与其位数的比值。如果这个数是负数，则程度增加0.5倍；如果还是个偶数，则再增加1倍。
// 例如数字-13142223336是个11位数，其中有3个2，并且是负数，也是偶数，则它的犯二程度计算为：3/11×1.5×2×100%，约为81.82%。本题就请你计算一个给定整数到底有多二。

// 输入格式：
// 输入第一行给出一个不超过50位的整数N。

// 输出格式：
// 在一行中输出N犯二的程度，保留小数点后两位。

// 输入样例：
// -13142223336
// 输出样例：
// 81.82%

#include<iostream>
#include<iomanip>

using namespace std;

string N;
double pluss = 1;
int point = 0;
int len = 0;
int lenss = 0;
double ans;

int main(){
    cin >> N;
    len = N.length();
    if(N[0] == '-'){
        pluss = pluss * 1.5;
        N = N.substr(1);
        len--;
        // cout << "in" << pluss << " " << pluss * 1.5 << endl;
    }
    // cout << N << endl;
    if((atoi(N.substr(len - 1).c_str()) % 2 == 0)){
        pluss = pluss * 2;
        // cout << "in" << endl;
    }
    while(N[point] != '\0'){
        if(N[point] == '2'){
            lenss++;
        }
        point++;
    }
    // cout << pluss << endl;
    // cout << 3 * 1.0 * 3 / 11 << endl;
    // cout << lenss << " * 1.0 " << " * " << pluss << " / " << len << " = ";  
    ans =  lenss * 1.0 * pluss / len;
    cout << setprecision(2) << fixed << ans * 100 << "%";
    return 0;
}