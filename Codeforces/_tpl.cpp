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

const int maxn = 1e1 + 5;
const int inf = ~0u >> 2;



int main() {

    return 0;
}
