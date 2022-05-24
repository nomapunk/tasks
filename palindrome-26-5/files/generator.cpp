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
 
int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
 
    int n = opt<int>(1);
    int t = opt<int>(2);
    string res;
    if (t == 0) {
        for (int i = 0; i < n; i++) res += "a";
    } else if (t == 1) {
        for (int i = 0; i + 52 < n; i += 52) {
            string left;
            for (char x = 'a'; x <= 'z'; x += 1) {
                left += x;
            }
            string right = left;
            reverse(right.begin(), right.end());
            res += left;
            res += right;
        }
        while (res.size() != n) {
            res += char(rnd.next(26) + 'a');
        }
    } else if (t == 2) {
        for (int i = 0; i < n; i++) {
            res += char(rnd.next(26) + 'a');
        }
    } else if (t == 3) {
        for (int i = 0; i + 51 < n; i += 51) {
            string left;
            for (char x = 'a'; x <= 'z' - 1; x += 1) {
                left += x;
            }
            string right = left;
            reverse(right.begin(), right.end());
            res += left;
            res += 'z';
            res += right;
        }
        while (res.size() != n) {
            res += char(rnd.next(26) + 'a');
        }
    } else if (t == 4) {
        while (res.size() != n) {
            if (n - res.size() == 1) {
                res += char(rnd.next(26) + 'a');
            } else {
                string left;
                for (int i = 0; i < min(int(n - res.size()) / 2, 26); i++) {
                    left += char(rnd.next(26) + 'a');
                }
                string right = left;
                reverse(right.begin(), right.end());
                res += left;
                res += right;
            }
        }
    }
    cout << res << '\n';
    return 0;
}
