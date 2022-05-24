#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e6;

pair<int, int> g[MAX_N + 1];

int h[3];
int n, cur;

std::vector<pair<int, int>> ans;

pair<int, int> buff(int v) {
    cur++;
    int l = cur;
    cur++;
    int r = cur;
    ans.emplace_back(v, l);
    ans.emplace_back(v, r);
    return {l, r};
}

bool empty(int v) {
    return g[v].first == 0;
}

void print() {
    cout << ans.size() << '\n';
    for (const auto [l, r] : ans) {
        cout << l << ' ' << r << '\n';
    }
}

void dfs(int v, int cur_h, int max_h) {
    if (empty(v) && cur + 2 <= n && cur_h + 1 <= max_h) {
        g[v] = buff(v);
    }
    if (!empty(v)) {
        dfs(g[v].first, cur_h + 1, max_h);
        dfs(g[v].second, cur_h + 1, max_h);
    }
}

int main() {
    cin >> n;
    cin >> h[0] >> h[1] >> h[2];
    cur = 1;
    {
        int v = 1;
        int h_boss = h[0];
        while (h_boss --> 0) {
            g[v] = buff(v);
            v = g[v].first;
        }
        if (cur > n) {
            cout << "NO\n";
            return 0;
        }
    }
    if (h[0] - 1 != h[1]) {
        cout << "NO\n";
        return 0;
    }
    if (h[2] == h[1]) {
        int v = g[1].second;
        int h_boss = h[0] - 1;
        while (h_boss --> 0) {
            g[v] = buff(v);
            v = g[v].second;
        }
        if (cur > n) {
            cout << "NO\n";
            return 0;
        }
        dfs(1, 0, h[0]);
        if (cur == n) {
            cout << "YES\n";
            print();
        } else {
            cout << "NO\n";
        }
    } else if (h[2] == h[1] - 1) {
        dfs(1, 0, h[0]);
        if (cur == n) {
            cout << "YES\n";
            print();
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "NO\n";
    }
    return 0;
}
