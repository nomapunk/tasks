#include "testlib.h"
#include <vector>
#include <algorithm>
#include <iostream>

int err;

int dfs(int u, std::vector<std::vector<int>>& g, std::vector<int>& p, std::vector<bool>& used) {
    int maxRes = 0;
    used[u] = true;
    for (auto v : g[u]) {
        if (used[v]) {
            err = 1;
            continue;
        }
        maxRes = std::max(maxRes, dfs(v, g, p, used));
    }
    p[maxRes]++;
    return maxRes + 1;
}

bool correct(std::vector<std::vector<int>>& g, int m, std::vector<int>& a, int n) {
    std::vector<int> p(n);
    std::vector<bool> used(m);
    err = 0;
    dfs(0, g, p, used);
    if (err == 1) {
        return false;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (i != 0) {
            p[i - 1] += p[i];
        }
        if (p[i] != a[i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int t;
    t = inf.readInt();
    int score = 0;
    for (int exp = 0; exp < t; ++exp) {
        int n;
        n = inf.readInt();
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            int x;
            x = inf.readInt();
            a[i] = x;
        }
        int m = ouf.readInt();
        if (m != -1) {
            if (m != a[0]) {
                quitf(_pe, "wrong m, expected: %d, found: %d", a[0], m);
            }
            std::vector<std::vector<int>> g(m);
            for (int i = 1; i < m; ++i) {
                int u;
                u = ouf.readInt(0, m - 1, "u");
                int v;
                v = ouf.readInt(0, m - 1, "v");
                g[u].push_back(v);
            }

            if (correct(g, m, a, n)) {
                score += 10;
            }
        } else {
            score += 0;
            // skip test
        }
    }
    quitp(score, "participant's solution is ok");
    return 0;
}
