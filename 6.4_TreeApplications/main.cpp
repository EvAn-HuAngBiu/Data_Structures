#include <iostream>

void Queens(int *pos, int i, int n);

int main() {
    int pos[6] = {0};
    Queens(pos, 1, 5);
    return 0;
}