#include <iostream>
#include "HuffmanTree.h"

int main() {
    unsigned int arr[] = {7, 19, 2, 6, 32, 3, 21, 10};
    HuffmanTree ht(arr, 8);
    //std::cout << ht << std::endl;
    unsigned  int arr2[] = {5, 29, 7, 8, 14, 23, 3, 11};
    HuffmanTree ht2(arr2, 8);
    ht2.huffmanCode(8);
    //std::cout << ht2 << std::endl;
    unsigned int arr3[] = {7, 5, 2, 4};
    HuffmanTree ht3(arr3, 4);
    ht3.huffmanCode_FromRoot(4);
    std::cout << ht3 << std::endl;
    return 0;
}