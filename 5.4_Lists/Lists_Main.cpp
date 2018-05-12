#include <iostream>
#include "Lists.h"
using namespace std;


int main() {
    Lists l("(a,(b,c,d))");
    cout << l.depth() << endl;
    Lists t("()");
    l.copy(t);
    cout << t.depth() << endl;
    return 0;
}