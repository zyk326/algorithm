#include<iostream>
#include<iomanip>
#define MIN_VALUE 1e-8
#define IS_DOUBLE_ZERO(d) (abs(d) < MIN_VALUE)

using namespace std;

double a, b, a1, b1;
double aa, bb, a11, b11;

void init(double &num){
    int buf;
    buf = num * 100;
    if(buf % 10 >= 5){
        buf = buf / 10;
        buf++;
        num = buf * 1.0 / 10;  
    }else{
        buf /= 10;
        num = buf * 1.0 / 10; 
    }
}

int main(){
    cin >> a >> b >> a1 >> b1;
    aa = a;
    bb = b;
    a11 = a1;
    b11 = b1;
    init(a);
    init(b);
    init(a1);
    init(b1);
    // cout << a << " " << b << " " << a1 << " " << b1 << endl;

    cout << "(" << setprecision(1) << fixed << a << "+" << b << "i) + (" << a1;if(b1 >= 0.0)cout << "+";cout << b1 << "i) = ";
    if(!IS_DOUBLE_ZERO(a + a1)){
        cout << aa + a11;
    }
    if(!IS_DOUBLE_ZERO(b + b1)){
        if(1.0 + (b + b1) > 1.0 && !IS_DOUBLE_ZERO(a + a1)){
            cout << "+";
        }
        cout << bb + b11 << "i";
    }
    if(IS_DOUBLE_ZERO(a + a1) && IS_DOUBLE_ZERO(b + b1)){
        cout << "0.0";
    }
    cout << endl;

    cout << "(" << setprecision(1) << fixed << a << "+" << b << "i) - (" << a1;if(b1 >= 0.0)cout << "+";cout << b1 << "i) = ";
    if(!IS_DOUBLE_ZERO(a - a1)){
        cout << aa - a11;
    }
    if(!IS_DOUBLE_ZERO(b - b1)){
        if(1.0 + (b - b1) > 1.0 && !IS_DOUBLE_ZERO(a - a1)){
            cout << "+";
        }
        cout << bb - b11 << "i";
    }
    if(IS_DOUBLE_ZERO(a - a1) && IS_DOUBLE_ZERO(b - b1)){
        cout << "0.0";
    }
    cout << endl;

    cout << "(" << setprecision(1) << fixed << a << "+" << b << "i) * (" << a1;if(b1 >= 0.0)cout << "+";cout<< b1 << "i) = ";
    if(!IS_DOUBLE_ZERO((a * a1 - b * b1))){
        cout << aa * a11 - bb * b11;
    }
    if(!IS_DOUBLE_ZERO((b * a1 + a * b1))){
        if(1.0 + (b * a1 + a * b1) > 1.0 && !IS_DOUBLE_ZERO((a * a1 - b * b1))){
            cout << "+";
        }
        cout << bb * a11 + aa * b11 << "i";
    }
    if(IS_DOUBLE_ZERO((a * a1 - b * b1)) && IS_DOUBLE_ZERO((b * a1 + a * b1))){
        cout << "0.0";
    }
    cout << endl;

    cout << "(" << setprecision(1) << fixed << a << "+" << b << "i) / (" << a1;if(b1 >= 0.0)cout << "+";cout << b1 << "i) = ";
    if(!IS_DOUBLE_ZERO(((a * a1 + b * b1) / (a1 * a1 + b1 * b1)))){
        cout << (aa * a11 + bb * b11) / (a11 * a11 + b11 * b11);
    }
    if(!IS_DOUBLE_ZERO(((b * a1 - a * b1) / (a1 * a1 + b1 * b1)))){
        if(1.0 + ((b * a1 - a * b1) / (a1 * a1 + b1 * b1)) > 1.0 && !IS_DOUBLE_ZERO(((a * a1 + b * b1) / (a1 * a1 + b1 * b1)))){
            cout << "+";
        }
        cout << (bb * a11 - aa * b11) / (a11 * a11 + b11 * b11) << "i";
    }
    if(IS_DOUBLE_ZERO(((a * a1 + b * b1) / (a1 * a1 + b1 * b1))) && IS_DOUBLE_ZERO(((b * a1 - a * b1) / (a1 * a1 + b1 * b1)))){
        cout << "0.0";
    }

    return 0;
}