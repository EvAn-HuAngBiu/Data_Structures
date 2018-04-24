#include <iostream>
#include "ArrayStackInheritance.cpp"

using namespace std;

int main() {
    ArrayStack<int> stack;
    cout.setf(ios_base::boolalpha);
    cout << stack.isEmpty() << endl;
    cout << stack.size() << endl;
    for (int i = 0; i < 5; i++) {
        stack.push(i);
    }
    cout << stack << endl;
    cout << stack.getTop() << endl;
    cout << stack.pop() << endl << stack << endl;
    cout << stack.getTop() << endl;
    stack.push(10);
    cout << stack << endl << stack.getTop() << endl;
    cout << stack.size() << endl;
    return 0;
}