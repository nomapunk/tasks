#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    inf.readInt(3, 1000000, "n");
    inf.readSpace();
    int h1 = inf.readInt(0, 1000000, "h1");
    inf.readSpace();
    int h2 = inf.readInt(0, 1000000, "h2");
    inf.readSpace();
    int h3 = inf.readInt(0, 1000000, "h3");
    ensuref(h1 >= h2 && h2 >= h3, "must be h1 >= h2 >= h3");
    inf.readEoln();
    inf.readEof();
    return 0;
}
