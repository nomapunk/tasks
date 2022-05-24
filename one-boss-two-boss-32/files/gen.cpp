#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int MAX_N, cur;

vector<int> res;

pair<int, int> g[1000000 + 1];

pair<int, int> buff(int v) {
    cur++;
    int l = cur;
    cur++;
    int r = cur;
    return {l, r};
}

int gen(int u) {
    if (u == 1 || 2 + cur <= MAX_N && rnd.next(6)) {
        g[u] = buff(u);
        int L = gen(g[u].first);
        int R = gen(g[u].second);
        res.push_back(L);
        res.push_back(R);
        return std::max(L, R) + 1;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    if (n == 1) {
        MAX_N = 3 + rnd.next(997);
        if (MAX_N % 2 == 0 && rnd.next(997) % 4) {
            MAX_N++;
        } else {
            MAX_N += 0;
        }
    } else if (n == 2) {
        MAX_N = 1000 + rnd.next(1000000 - 1000);
        if (MAX_N % 2 == 0) {
            MAX_N++;
        }
    }
    cur = 1;
    res.push_back(gen(1));
    cout << res.size() << ' ';
    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    cout << res[0] << ' ' << res[1] << ' ' << res[2] << endl;
}