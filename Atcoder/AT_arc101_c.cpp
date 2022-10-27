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

const int maxn = 5e3 + 5;
const int inf = ~0u >> 2;
const int mod = 1e9 + 7;
int &norm(int &x) {
    if (x >= mod) x -= mod;
    else if (x < 0) x += mod;
    return x;
}

int n, sz[maxn], f[maxn][maxn], g[maxn], h[maxn], A;
vector<int> G[maxn];

void dfs(int u, int fa) {
    sz[u] = 1, f[u][1] = 1;
    for (int v : G[u]) if (v != fa) {
        dfs(v, u);
        fill(h + 1, h + sz[u] + sz[v] + 1, 0);
        for (int i = 1; i <= sz[u]; ++i)
            for (int j = 1; j <= sz[v]; ++j) {
                norm(h[i] -= (ll)f[u][i] * f[v][j] % mod * g[j] % mod);
                norm(h[i + j] += (ll)f[u][i] * f[v][j] % mod);
            }
        sz[u] += sz[v];
        copy(h + 1, h + sz[u] + 1, f[u] + 1);
    }
}

int main() {
    rd(n);
    for (int i = 1, u, v; i < n; ++i)
        rd(u), rd(v), G[u].push_back(v), G[v].push_back(u);
    for (int i = 0; i <= n; i += 2) g[i] = (i ? (ll)g[i - 2] * (i - 1) % mod : 1);
    dfs(1, -1);
    for (int i = 2; i <= n; i += 2) norm(A += (ll)f[1][i] * g[i] % mod);
    printf("%d", A);
    return 0;
}
