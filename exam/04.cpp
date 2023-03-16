
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int N = 1E5 + 7;
char s[N];

 
int main()
{
    int T;
    scanf("%d", &T);
    while(T --) {
        string res;
        scanf("%s", s+1);
        int n = strlen(s+1);
        for(int fg = 0, i = 1;i <= n;i ++) {
            if(!fg) {
                int t = s[i] - '0';
                if(t % 2 == 0) {
                    res += s[i];
                    continue;
                }
                if(t == 9) {
                    fg = 1;
                    res += '8';
                    continue;
                }
                bool ok = 1;
                for(int j = i + 1;j <= n;j ++) {
                    if(s[j] == '4') continue;
                    if(s[j] < '4') break;
                    if(s[j] > '4') {
                        ok = 0; break;
                    }
                }
                if(ok) {
                    res += (s[i] - 1);
                    fg = 1;
                }
                else {
                    res += (s[i] + 1);
                    fg = 2;
                }
            } else {
                if(fg == 1) res += '8';
                else res += '0';
            }
        }
        if((int)res.size() == 1) {
            cout << res << '\n';
        } else {
            int pos = 0;
            if(res[0] == '0') res.erase(res.begin());
            cout << res << endl;
        }
    }
    return 0;
}