#include "testlib.h"
#include <vector>
#include <algorithm>
#include <iostream>
 
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int ja = ans.readInt();
    int ca = ouf.readInt();
    if (ja != ca) {
        quitf(_wa, "expected: %d, find: %d", ja, ca);   
	}
    quitf(_ok, "OK");
    return 0;
}