#include "testlib.h"
#include <vector>
#include <algorithm>
#include <iostream>
std::vector<int> res;
 
const int MAX_N = 1e6 + 1;
 
std::pair<int, int> g[MAX_N];

bool used[MAX_N];

bool empty(int v) {
    return g[v].first == 0;
}
 
int dfs(int v) {
    if (empty(v)) {
        return 0;
    }
    used[v] = true;
    if (used[g[v].first]) {
        quitf(_wa, "expected tree");
    }
    if (used[g[v].second]) {
        quitf(_wa, "expected tree");
    }
    int L = dfs(g[v].first);
    int R = dfs(g[v].second);
    res.push_back(L);
    res.push_back(R);
    return std::max(L, R) + 1;
}
 
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
 
    int n, h1, h2, h3;
    n  = inf.readInt();
    h1 = inf.readInt();
    h2 = inf.readInt();
    h3 = inf.readInt();
    
    std::string ja = ans.readWord();
    std::string ca = ouf.readWord();
    
    
    if (ja != ca) {
        if (ja == "NO") {
            int m = ouf.readInt(n - 1, n - 1, "number of edges");
            for (int i = 0; i < m; ++i) {
		int u, v;
		u = ouf.readInt(1, n, "u");
		v = ouf.readInt(1, n, "v");
		if (g[u].first == 0) {
		    g[u].first = v;
		} else if (g[u].second == 0){
		    g[u].second = v;
		} else {
		    quitf(_pe, "binary-tree, but exists edge: %d -> %d", u, v);
		}
	     }
		 
             res.push_back(dfs(1));
	     std::sort(res.begin(), res.end());
		 
             if (res.size() != n) {
            	quitf(_wa, "expected: NO");
	     }	 
	     if (res[res.size() - 1] != h1) {
            	quitf(_wa, "expected: NO");
	     }
	     if (res[res.size() - 2] != h2) {
            	quitf(_wa, "expected: NO");
	     }
	     if (res[res.size() - 3] != h3) {
            	quitf(_wa, "expected: NO");
	     }	 
    	     quitf(_fail, "jury no part yes");
        } else {
            quitf(_wa, "expected: YES");
        }
    }
    
    if (ja == "NO") {
        quitf(_ok, "OK");
    }
    
    int m = ouf.readInt(n - 1, n - 1, "number of edges");
 
    for (int i = 0; i < m; ++i) {
        int u, v;
        u = ouf.readInt(1, n, "u");
        v = ouf.readInt(1, n, "v");
        if (g[u].first == 0) {
            g[u].first = v;
        } else if (g[u].second == 0){
            g[u].second = v;
        } else {
            quitf(_pe, "binary-tree, but exists edge: %d -> %d", u, v);
        }
    }
 
    res.push_back(dfs(1));
 
    std::sort(res.begin(), res.end());
 
    if (res.size() != n) {
        quitf(_wa, "The number of vertices is wrong: expected = %d, found = %d", n, int(res.size()));
    }
 
    if (res[res.size() - 1] != h1) {
        quitf(_wa, "The h-boss1 is wrong: expected = %d, found = %d", h1, res[res.size() - 1]);
    }
    if (res[res.size() - 2] != h2) {
        quitf(_wa, "The h-boss2 is wrong: expected = %d, found = %d", h2, res[res.size() - 2]);
    }
    if (res[res.size() - 3] != h3) {
        quitf(_wa, "The h-boss3 is wrong: expected = %d, found = %d", h3, res[res.size() - 3]);
    }
 
    quitf(_ok, "OK");
    return 0;
}
