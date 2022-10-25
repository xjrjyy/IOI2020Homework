/*
Author: Xjrjyy
LANG: C++
PROG: $FileName$
Mail: admin@xjrjyy.cn
Blog: https://blog.xjrjyy.cn/
*/

#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

typedef long long ll;
typedef double db;
using std::cin;
using std::cout;
using std::endl;

const int maxn = 2e5 + 5;

int n;
int a[maxn];
int ans;
std::pair<int, int> stk[maxn * 10]; int stp;

void set(int p, int k) {
    while (stk[stp].first > p) --stp;
    if (stk[stp].first == p) ++stk[stp].second;
    else stk[++stp] = { p, 1 };
    if (stp > 1 && stk[stp].second >= k) 
        --stp, set(p - 1, k);
}

bool check(int k) {
    stk[stp = 1] = { 0, 0 };
    for (int i = 1; i <= n; ++i) {
        if (a[i] > a[i - 1]) continue;
        set(a[i], k);
        if (stk[1].second) return false;
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt += (a[i] > a[i - 1]);
    }
    if (cnt == n) {
        cout << 1;
        return 0;
    }
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}
