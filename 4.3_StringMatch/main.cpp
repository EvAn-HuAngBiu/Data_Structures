#include <iostream>
#include <string>
using namespace std;

int Index_KMP(const string &src, const string &pat, int pos = 0);

int *getNext(const string &pat);

int main() {
    string src = "ababcabcacbab", pat = "cacba";
    cout << Index_KMP(src, pat) << endl;
    return 0;
}

int Index_KMP(const string &src, const string &pat, int pos) {
    auto next = getNext(pat);
    int i = pos, j = 0;
    int sLen = src.size(), pLen = pat.size();
    while (i < sLen && j < pLen) {
        if (j == -1 || src[i] == pat[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    return (j == pat.size() ? i - pat.size() : -1);
}

int *getNext(const string &pat) {
    int i = 0, k = -1;
    auto next = new int[pat.size()];
    next[0] = -1;
    while (i < pat.size() - 1) {
        if (k == -1 || pat[i] == pat[k]) {
            next[++i] = ++k;
        } else {
            k = next[k];
        }
    }
    return next;
}
