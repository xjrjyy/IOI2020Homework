/*
Author: jyy
Mail: admin@xjrjyy.cn
Blog: https://blog.xjrjyy.cn/
*/

#include <bits/stdc++.h>

#define fo(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);

typedef long long ll; typedef unsigned long long ull; typedef std::pair<int, int> pii;

using namespace std;

clock_t _timer;
void timer_begin() { _timer = clock(); }
void timer_end(const char *msg) { fprintf(stderr, "%s: %.3fs\n", msg, double(clock() - _timer) / CLOCKS_PER_SEC); }

mt19937 rnd((unsigned)chrono::system_clock::now().time_since_epoch().count());

const int maxn = 1e2 + 5;
const int inf = ~0u >> 2;
const int mod = 998244353;
const int P = 1145141;

void Norm(int &x) {
    if (x >= mod) x -= mod;
    else if (x < 0) x += mod;
}

map<string, int> f, g;

int F(const string &s);
int G(const string &s) {
    if (g.count(s)) return g[s];
    int n = (int)s.size(), A = 0;
    for (int d = 1; d < n; ++d) if (n % d == 0) {
        string t = s.substr(0, d);
        for (int i = d; i < n; i += d)
            for (int j = 0; j < d; ++j) t[j] &= s[i + j];
        Norm(A += F(t));
    }
    return g[s] = A;
}
int F(const string &s) {
    if (s.empty()) return 1;
    if (f.count(s)) return f[s];
    int n = (int)s.size(), A = (s.front() - '0' + 1) * F(s.substr(1)) % mod;
    for (int i = 2; i <= n; ++i)
        Norm(A += (ll)G(s.substr(0, i)) * F(s.substr(i)) % mod);
    return f[s] = A;
}

int main() {
    string s;
    cin >> s;
    printf("%d", F(s));
    return 0;
}
