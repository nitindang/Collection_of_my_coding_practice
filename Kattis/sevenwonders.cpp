// https://open.kattis.com/problems/sevenwonders

#include <bits/extc++.h>

using namespace std;

const double eps = 1e-8;

inline int sgn(double a) {
    if (a < -eps) return -1;
    if (a > eps) return 1;
    return 0;
}

int main() {
    unordered_map<char, int> A;
    A['T'] = 0;
    A['C'] = 0;
    A['G'] = 0;

    string s;
    cin >> s;
    for (const auto &ch : s) {
        ++A[ch];
    }
    int cnt = 0;
    int minVal = 55;
    for (const auto &it : A) {
        cnt += it.second * it.second;
        minVal = min(minVal, it.second);
    }

    cnt += minVal * 7;
    cout << cnt << endl;
    return 0;
}
