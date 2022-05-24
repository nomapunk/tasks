#include <bits/stdc++.h>
using namespace std;

inline bool is_palindrome(const string& s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) {
            return false;
        }
        ++l; --r;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    for (size_t i = 0; i < s.size(); ++i) {
        s[i] -= 'a';
    }

    size_t ans = s.size();
    for (size_t l = 0; l < s.size(); ++l) {
        uint64_t first = 1 << s[l], second = 0;
        for (size_t r = l + 1; r < s.size(); ++r) {
            if (second & (1 << s[r])) {
                break;
            } else if (first & (1 << s[r])) {
                second |= 1 << s[r];
            } else {
                first |= 1 << s[r];
            }
            ans += is_palindrome(s, l, r);
        }
    }
    cout << ans;
}