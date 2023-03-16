// #include<stdio.h>
// int main() {
//     int T, n, m;
//     int px, rx;
//     for (scanf("%d", &T); T; T--) {
//         scanf("%d %d", &n, &m);
//         if (n<0)n = -n; if (m<0)m = -m;
//         if (n + m == 0)printf("0\n");
//         else if (n + m == 1)printf("3\n");
//         else if (n == 1 && m == 1)printf("2\n");
//         else if (n == 2 && m == 2)printf("4\n");
//         else if (m <= 2 * n&&n <= 2 * m)
//             printf("%d\n", (m + n) / 3 + (m + n) % 3);
//         else if (m == 0) {
//             px = (n - 2) / 4, rx = (n - 2) % 4;
//             printf("%d\n", 2 * px + 2 + (rx & 1));
//         }
//         else if (n == 0) {
//             px = (m - 2) / 4, rx = (m - 2) % 4;
//             printf("%d\n", 2 * px + 2 + (rx & 1));
//         }
//         else if (m>2 * n) {
//             px = (m - 2 * n) / 4, rx = (m - 2 * n) % 4;
//             printf("%d\n", n + px * 2 + rx);
//         }
//         else if (n>2 * m) {
//             px = (n - 2 * m) / 4, rx = (n - 2 * m) % 4;
//             printf("%d\n", m + px * 2 + rx);
//         }
//     }
// }

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
 
ll fun(ll x, ll y) {//x <= y && x >= 0 && y >= 0
    x = abs(x);
    y = abs(y);
    if (x > y)
        swap(x, y);
    if (y == 1 && x == 0)
        return 3;
    if (y == 2 && x == 2)
        return 4;
    ll delta = y - x;
    if (x > delta)
        return delta - 2 * floor(1.0 * (delta - x) / 3.0);
    return delta - 2 * floor(1.0 * (delta - x) / 4.0);  
}
 
int main() {
    int T;
    ll n, m;
    scanf("%d", &T);
    while (T--) {
    scanf("%lld%lld", &n, &m);
    ll ans = fun(n, m);
    printf("%lld\n", ans);
    }
    return 0;
}