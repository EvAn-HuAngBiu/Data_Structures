#include <iostream>
#include "SqList.cpp"
using namespace std;

int main() {
    SqList<int> ls;
    for(int i = 1; i < 8; i++) {
        ls.listInsert(i, i * 3);
    }
    ls.display();
    cout << ls.listDelete(3) << endl;
    ls.display();
    return 0;
}