#include <iostream>

using namespace std;

int N, NN;
int point = 2;
int i, j;
string ans;
string outans;
int times = 0;
int d[10000];
int mi[10000];
int top = 0;

int getnum(int innum)
{
    for (i = innum + 1;; i++)
    {
        bool flag = true;
        for (j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return i;
        }
    }
}

int main()
{
    cin >> N;
    NN = N;
    if (N == 1)
    {
        cout << "1=1";
    }
    else
    {
        while (N != 1)
        {
            if (N % point == 0)
            {
                d[top] = point;
                mi[top]++;
                N /= point;
                ans += to_string(point);
            }
            else
            {
                if (d[top] != 0)
                {
                    top++;
                }
                point = getnum(point);
            }
        }
        cout << NN << "=";
        for (i = 0; i <= top; i++)
        {
            cout << d[i];
            if (mi[i] != 1)
            {
                cout << "^" << mi[i];
            }
            if (i != top)
                cout << "*";
        }
    }
    return 0;
}