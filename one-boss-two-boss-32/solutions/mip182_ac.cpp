#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout << #x << "=" << x << ", ";}

template<class T>
bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }

template<class T>
bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<typename T>
vector<T> &operator--(vector<T> &v) {
    for (auto &i: v) --i;
    return v;
}

template<typename T>
vector<T> &operator++(vector<T> &v) {
    for (auto &i: v) ++i;
    return v;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i: v) is >> i;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto &i: v) os << i << ' ';
    return os;
}

template<typename T, typename U>
pair<T, U> &operator--(pair<T, U> &p) {
    --p.first;
    --p.second;
    return p;
}

template<typename T, typename U>
pair<T, U> &operator++(pair<T, U> &p) {
    ++p.first;
    ++p.second;
    return p;
}

template<typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}

template<typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> p) {
    os << p.first << ' ' << p.second;
    return os;
}

template<typename T, typename U>
pair<T, U> operator-(pair<T, U> a, pair<T, U> b) { return mp(a.first - b.first, a.second - b.second); }

template<typename T, typename U>
pair<T, U> operator+(pair<T, U> a, pair<T, U> b) { return mp(a.first + b.first, a.second + b.second); }

const ll INFLL = 1e18;
const int MAXN = 1e6 + 100;
const int INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;

void solve() {
    int n;
    vector<int> d(3);
    vector<int> l(3, -1), r(3, -1);
    cin >> n >> d;
    n -= 3;
    if (d[0] - 1 != d[1] || d[1] < d[2] || abs(d[1] - d[2]) > 1) {
        cout << "NO\n";
        return;
    }
    vector<pii > ans;
    int cur = 3;
    auto add_l = [&](int x) {
        n--;
        assert(l[x] == -1);
        d.pb({d[x] - 1});
        ans.pb({x, cur++});
        l[x] = cur - 1;
        l.pb(-1);
        r.pb(-1);
        return l[x];
    };
    auto add_r = [&](int x) {
        n--;
        assert(r[x] == -1);
        d.pb({d[x] - 1});
        ans.pb({x, cur++});
        r[x] = cur - 1;
        l.pb(-1);
        r.pb(-1);
        return r[x];
    };
    function<void(int)> dfs = [&](int s) {
        if (d[s] == 0)
            return;
        if (n >= 2) {
            if (l[s] == -1 && r[s] == -1) {
                int L = add_l(s);
                int R = add_r(s);
                dfs(L);
                dfs(R);
            } else if (l[s] && r[s]) {
                dfs(l[s]);
                dfs(r[s]);
            } else
                assert(false);
        }
    };
    if (d[1] == d[2]) {
        ans.pb(mp(0, 1));
        ans.pb(mp(0, 2));
        l[0] = 1;
        r[0] = 2;
        int now_l = 1;
        int now_r = 2;
        while (d[now_l] > 0) {
            add_r(now_l);
            now_l = add_l(now_l);
        }
        while (d[now_r] > 0) {
            add_r(now_r);
            now_r = add_l(now_r);
        }
    } else {
        if (d[1] - 1 != d[2]) {
            cout << "NO\n";
            return;
        }
        ans.pb(mp(0, 1));
        l[0] = 1;
        add_r(0);
        d[r[0]]--;
        ans.pb(mp(1, 2));
        l[1] = 2;
        add_r(1);
        int now_l = 2;
        while (d[now_l] > 0) {
            add_r(now_l);
            now_l = add_l(now_l);
        }
    }
    dfs(0);
    if (n != 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n" << ans.size() << '\n';
    for (auto to: ans) {
        ++to;
        cout << to << '\n';
    }
}

int main() {
#ifdef Mip182
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int _t;
    _t = 1;
//    cin >> _t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}
