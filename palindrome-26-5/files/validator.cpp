#include "testlib.h"
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    std::string t = inf.readWord();
    inf.readEoln();
    if (t.size() > 100000) {
        return 1;
    }
    for (int i = 0; i < t.size(); ++i) {
        if (t[i] > 'z' || t[i] < 'a') {
            return 1;
        }
    }
    inf.readEof();
    return 0;
}