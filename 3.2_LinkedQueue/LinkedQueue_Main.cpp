#include <iostream>
#include "LinkedQueue.cpp"
using namespace std;

int main() {
    LinkedQueue<int> queue;
    cout.setf(ios_base::boolalpha);
    cout << queue.length() << " " << queue.isEmpty() << endl;
    for (int i = 1; i <= 5; i++) {
        queue.enqueue(i * 3);
    }
    cout << queue.length() << " " << queue.isEmpty() << endl;
    cout << queue.getHead() << endl;
    cout << queue.dequeue() << endl;
    cout << queue.getHead() << endl;
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    cout << queue.isEmpty() << endl;
    try {
        queue.getHead();
    } catch (const char *e) {
        cerr << e << endl;
    }
    return 0;
}