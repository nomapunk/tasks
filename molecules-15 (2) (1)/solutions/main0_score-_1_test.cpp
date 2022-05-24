#include <iostream>
#include <vector>

using namespace std;

int dfs(int u, vector<vector<int>>& g, vector<int>& p) {
    int maxRes = 0;
    for (auto v : g[u]) {
        maxRes = max(maxRes, dfs(v, g, p));
    }
    p[maxRes]++;
    return maxRes + 1;
}

bool correct(vector<vector<int>>& g, int m, vector<int>& a, int n) {
    vector<int> p(n);
    dfs(0, g, p);
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

int main() {
    int t;
    cin >> t;
    for (int exp = 0; exp < t; ++exp) {
        int n;
        cin >> n;
        vector<int> a(n), aCopy;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        aCopy = a;
        int m = a[0];
        vector<vector<int>> g(m);
        int root = 0, currentNumber = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (a[i] != 0) {
                for (int d = 1, j = i, pr = root; j >= 0; --j, ++d, pr = currentNumber++) {
                    a[j] -= d;
                    if (j != n - 1) {
                        g[pr].push_back(currentNumber);
                    }
                }
            }
        }
        if (!correct(g, m, aCopy, n)) {
            cout << m << '\n';
            for (int u = 0; u < m; ++u) {
                for (auto v: g[u]) {
                    cout << u << " " << v << '\n';
                }
            }
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}
