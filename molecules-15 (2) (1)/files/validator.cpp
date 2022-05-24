#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt();
    inf.readEoln();
    for (int exp = 0; exp < t; ++exp) {
        int n = inf.readInt(1, 1000000, "n");
        inf.readEoln();
        inf.readInt(0, 1000000, "a[0]");
        for (int i = 1; i < n; ++i) {
            inf.readSpace();
            inf.readInt(0, 1000000, "a[i]");
        }
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}