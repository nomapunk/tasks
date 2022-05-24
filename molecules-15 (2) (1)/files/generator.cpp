#include "testlib.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int dfs(int u, vector<vector<int>>& g, vector<int>& p) {
    int maxRes = 0;
    for (auto v : g[u]) {
        maxRes = max(maxRes, dfs(v, g, p));
    }
    p[maxRes]++;
    return maxRes + 1;
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int t = opt<int>(1);
    printf("%d\n", t);
    for (int exp = 0; exp < t; ++exp) {
        int n = opt<int>(exp + 2);

        vector<int> p(n);

        vector<int> perm(n);
        vector<vector<int>> g(n);
        
        if (exp == 6) {
            for (int i = 1; i < n; ++i) {
                g[i - 1].push_back(i);
            }
        } else {
            for (int i = 1; i < n; ++i)
                if (rnd.next(10) >= 4)
                    g[rnd.next(i / 2 + 1)].push_back(i);
                else
                    g[rnd.next(i)].push_back(i);
        }
        dfs(0, g, p);
        int m = n;
        for (int i = n - 1; i >= 0; --i) {
            if (i != 0) {
                p[i - 1] += p[i];
            }
            if (p[i] == 0) {
                m--;
            }
        }
        printf("%d\n", m);
        printf("%d", p[0]);
        for (int i = 1; i < m; ++i) {
            printf(" %d", p[i]);
        }
        printf("\n");
    }
    return 0;
}
