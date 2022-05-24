#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int exp = 0; exp < t; ++exp) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int root = 0, currentNumber = 0;
        cout << a[0] << '\n';
        for (int i = n - 1; i >= 0; i--) {
            while (a[i] != 0) {
                for (int d = 1, j = i, pr = root; j >= 0; --j, ++d, pr = currentNumber++) {
                    a[j] -= d;
                    if (j != n - 1) {
                        cout << pr << " " << currentNumber << '\n';
                    }
                }
            }
        }
    }
    return 0;
}
