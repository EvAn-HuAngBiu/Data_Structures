//
// Created by Evan on 19/05/2018.
//

#include <iostream>

bool isLegeal(int *pos, int i, int j) {
    // 判断在第i行第j列放置棋子是否合法
    for (int k = 1; k < i; k++) {
        if (abs(pos[k] - j) == abs(k - i) || pos[k] == j)
            return false;
    }
    return true;
}

void Queens(int *pos, int i, int n) {
    // pos为结果数组，0号单元不存放数据
    // i指示当前处理的行数, n指示总行数
    if (i > n) {
        for (int j = 1; j <= n; j++) {
            std::cout << pos[j] << " ";
        }
        std::cout << std::endl;
    }
    else {
        for (int j = 1; j <= n; j++) {
            // 在第i行第j列放置棋子
            if (isLegeal(pos, i, j)) {
                // 当前布局合法, 进入下一行
                pos[i] = j;
                Queens(pos, i+1, n);
            }
        }
    }
}