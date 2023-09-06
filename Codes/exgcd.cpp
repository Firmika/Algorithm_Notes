// 扩展欧几里得 递归实现
// x1 = y2;
// y1 = x2 - a / b * y2
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// 通解
// x = x1 + k * b/gcd(a,b)
// y = y1 - k * a/gcd(a,b)