/*
Author: jyy
Mail: admin@xjrjyy.cn
Blog: https://blog.xjrjyy.cn/
*/

#include <bits/stdc++.h>

#define fo(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);

typedef long long ll; typedef unsigned long long ull; typedef std::pair<int, int> pii;

namespace FastIO {
#if __cplusplus >= 201103L
#define CALL_INT typename std::enable_if<std::is_integral<T>::value || std::is_same<T, ll>::value || std::is_same<T, ull>::value>::type
#else
#define CALL_INT void
#endif
const std::size_t buf_size = 1 << 18;
char I[buf_size], *p1, *p2;
inline char gc() { return p1 == p2 && (p2 = (p1 = I) + fread(I, 1, sizeof(I), stdin), p1 == p2) ? EOF : *p1++; }

template <typename T> CALL_INT rd(T &x) {
    x = 0; bool f = false; char c = gc();
    while (!isdigit(c)) f = f || (c == '-'), c = gc();
    while (isdigit(c)) x = x * 10 + c - '0', c = gc();
    x *= (f ? -1 : 1);
}
}
using FastIO::rd; using FastIO::gc; using namespace std;

clock_t _timer;
void timer_begin() { _timer = clock(); }
void timer_end(const char *msg) { fprintf(stderr, "%s: %.3fs\n", msg, double(clock() - _timer) / CLOCKS_PER_SEC); }

mt19937 rnd((unsigned)chrono::system_clock::now().time_since_epoch().count());

const int maxn = 1e6 + 5;
const int inf = ~0u >> 2;
const int mod = 998244353;

int qpow(int a, int b) {
    int c = 1;
    for (; b; b >>= 1, a = (ll)a * a % mod) if (b & 1) c = (ll)c * a % mod;
    return c;
}
int inv(int x) { return qpow(x, mod - 2); }

int n, k, fac[maxn], ifac[maxn], A;

void init(int n) {
    for (int i = 0; i <= n; ++i) fac[i] = (i ? (ll)fac[i - 1] * i % mod : 1);
    ifac[n] = inv(fac[n]);
    for (int i = n; i--; ) ifac[i] = (ll)ifac[i + 1] * (i + 1) % mod;
}
int C(int n, int m) {
    if (n < m) return 0;
    return (ll)fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int main() {
    rd(n), rd(k), init(k);
    for (int i = n; i <= k; ++i) (A += C(k - 1, i - 1)) %= mod;
    printf("%d", A);
    return 0;
}
