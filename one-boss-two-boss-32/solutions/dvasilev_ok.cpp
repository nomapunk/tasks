#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

using Tree = vector<vector<int>>;
Tree g;

int n, h1, h2, h3;
int C = 3;

bool BuildMin(int cur, int len_left) {
    if (cur >= n) return false;
    assert(g[cur].empty());
    if (len_left == 0) return true;
    g[cur].push_back(C++);
    g[cur].push_back(C++);
    return BuildMin(g[cur][0], len_left - 1);
}

bool BuildMax(int cur, int len_left) {
    if (cur >= n) return false;
    if (C == n) return true;
    assert(g[cur].empty() || g[cur].size() == 2);
    if (len_left == 0) return true;
    if (g[cur].empty()) {
        g[cur].push_back(C++);
        g[cur].push_back(C++);
        return BuildMax(g[cur][0], len_left - 1) && BuildMax(g[cur][1], len_left - 1);
    } else {
        return BuildMax(g[cur][0], len_left - 1) && BuildMax(g[cur][1], len_left - 1);
    }
}

void run() {
    cin >> n >> h1 >> h2 >> h3;

    if (n % 2 == 0) { cout << "NO"; return; }
    if (h1 == h2 || h1 == h3) { cout << "NO"; return; }

    g.resize(n);
    g[0] = {1, 2};

    if (!BuildMin(1, h2)) { cout << "NO"; return; }
    if (h2 == h3) { if (!BuildMin(2, h3)) { cout << "NO"; return; } }

    if (!BuildMax(1, h2)) { cout << "NO"; return; }
    if (h2 == h3) { if (!BuildMax(2, h3)) { cout << "NO"; return; } }
    else { if (!BuildMax(2, h1 - 1)) { cout << "NO"; return; } }

    if (C != n) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
        cout << n - 1 << "\n";
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                cout << i + 1 << " " << j + 1 << "\n";
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout << fixed << setprecision(13);

    int t = 1;
    //cin >> t;
    for (int test = 1; test <= t; ++test) {
        run();
    }

    return 0;
}