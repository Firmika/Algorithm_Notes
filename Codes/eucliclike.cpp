#include <bits/stdc++.h>
using namespace std;
// 类欧几里得算法
// 计算(ai+b)/c和式
// 递归实现
// long long EucLicLike(int a, int b,int c, int n) {
//     long long res=0;
//     if (a>c) {
//         res += (long long)n*(n+1)/2*(a/c);
//         a %= c;
//     }
//     if (b>c) {
//         res += (long long)(n+1)*(b/c);
//         b %= c;
//     }
//     long long m = ((long long)a*n+b)/c;
//     if (m==0) return res;
//     return res+(long long)m*n-EucLicLike(c,c-b-1,a,m-1);
// }

// 非递归实现
long long EucLicLike(int a, int b, int c, int n) {
    long long res = 0;
    int m = 1, sign = 1;
    while (m) {
        if (a >= c) {
            res += (long long)n * (n + 1) / 2 * (a / c) * sign;
            a %= c;
        }
        if (b >= c) {
            res += ((long long)n + 1) * (b / c) * sign;
            b %= c;
        }
        m = ((long long)a * n + b) / c;
        if (!m)
            break;
        res += (long long)m * n * sign;
        n = m - 1;
        b = c - b - 1;
        int tmp = a;
        a = c;
        c = tmp;
        sign = -sign;
    }
    return res;
}

int main() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    cout << EucLicLike(a, b, c, n);
}