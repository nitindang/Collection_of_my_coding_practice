// https://open.kattis.com/problems/sifferprodukt
//
#include <bits/extc++.h>

using namespace std;

int solve(int n) {
    if (n < 10) return 0;
    int k;
    string s;
    while (n >= 10) {
        k = 1;
        s = to_string(n);
        for (const char &ch : s) {
            if (ch != '0') {
                k = k * (ch - '0');
            }
        }
        n = k;
    }
    return n;
}

constexpr int MAXLEN = 1005;
constexpr array<int, MAXLEN> A = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 3, 4,
                                  5, 6, 7, 8, 9, 2, 2, 4, 6, 8, 1, 2, 4, 6, 8,
                                  3, 3, 6, 9, 2, 5, 8, 2, 8, 4, 4, 4, 8, 2, 6,
                                  2, 8, 6, 6, 8, 5, 5, 1, 5, 2, 1, 3, 5, 4, 2,
                                  6, 6, 2, 8, 8, 3, 8, 8, 6, 2, 7, 7, 4, 2, 6,
                                  5, 8, 8, 3, 8, 8, 8, 6, 8, 6, 4, 6, 3, 8, 4,
                                  9, 9, 8, 4, 8, 2, 2, 8, 4, 8, 1, 1, 2, 3, 4,
                                  5, 6, 7, 8, 9, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                                  2, 2, 4, 6, 8, 1, 2, 4, 6, 8, 3, 3, 6, 9, 2,
                                  5, 8, 2, 8, 4, 4, 4, 8, 2, 6, 2, 8, 6, 6, 8,
                                  5, 5, 1, 5, 2, 1, 3, 5, 4, 2, 6, 6, 2, 8, 8,
                                  3, 8, 8, 6, 2, 7, 7, 4, 2, 6, 5, 8, 8, 3, 8,
                                  8, 8, 6, 8, 6, 4, 6, 3, 8, 4, 9, 9, 8, 4, 8,
                                  2, 2, 8, 4, 8, 2, 2, 4, 6, 8, 1, 2, 4, 6, 8,
                                  2, 2, 4, 6, 8, 1, 2, 4, 6, 8, 4, 4, 8, 2, 6,
                                  2, 8, 6, 6, 8, 6, 6, 2, 8, 8, 3, 8, 8, 6, 2,
                                  8, 8, 6, 8, 6, 4, 6, 3, 8, 4, 1, 1, 2, 3, 4,
                                  5, 6, 7, 8, 9, 2, 2, 8, 8, 6, 6, 4, 6, 2, 8,
                                  4, 4, 6, 8, 3, 7, 6, 4, 2, 2, 6, 6, 6, 6, 8,
                                  8, 2, 2, 6, 6, 8, 8, 8, 2, 4, 9, 8, 2, 6, 2,
                                  3, 3, 6, 9, 2, 5, 8, 2, 8, 4, 3, 3, 6, 9, 2,
                                  5, 8, 2, 8, 4, 6, 6, 2, 8, 8, 3, 8, 8, 6, 2,
                                  9, 9, 8, 4, 8, 2, 2, 8, 4, 8, 2, 2, 8, 8, 6,
                                  6, 4, 6, 2, 8, 5, 5, 3, 2, 6, 5, 9, 5, 2, 5,
                                  8, 8, 8, 2, 4, 9, 8, 2, 6, 2, 2, 2, 8, 8, 6,
                                  5, 2, 6, 6, 4, 8, 8, 6, 4, 2, 2, 6, 6, 8, 2,
                                  4, 4, 2, 8, 8, 5, 2, 4, 2, 8, 4, 4, 8, 2, 6,
                                  2, 8, 6, 6, 8, 4, 4, 8, 2, 6, 2, 8, 6, 6, 8,
                                  8, 8, 6, 8, 6, 4, 6, 3, 8, 4, 2, 2, 8, 8, 6,
                                  6, 4, 6, 2, 8, 6, 6, 6, 6, 8, 8, 2, 2, 6, 6,
                                  2, 2, 4, 6, 8, 1, 2, 4, 6, 8, 8, 8, 6, 4, 2,
                                  2, 6, 6, 8, 2, 6, 6, 3, 6, 2, 4, 6, 2, 6, 2,
                                  6, 6, 8, 2, 6, 6, 8, 6, 6, 6, 8, 8, 4, 8, 6,
                                  8, 2, 2, 6, 8, 5, 5, 1, 5, 2, 1, 3, 5, 4, 2,
                                  5, 5, 1, 5, 2, 1, 3, 5, 4, 2, 1, 1, 2, 3, 4,
                                  5, 6, 7, 8, 9, 5, 5, 3, 2, 6, 5, 9, 5, 2, 5,
                                  2, 2, 4, 6, 8, 1, 2, 4, 6, 8, 1, 1, 5, 5, 1,
                                  1, 5, 5, 2, 2, 3, 3, 6, 9, 2, 5, 8, 2, 8, 4,
                                  5, 5, 7, 5, 4, 5, 2, 4, 6, 5, 4, 4, 8, 2, 6,
                                  2, 8, 6, 6, 8, 2, 2, 9, 5, 8, 2, 4, 5, 8, 2,
                                  6, 6, 2, 8, 8, 3, 8, 8, 6, 2, 6, 6, 2, 8, 8,
                                  3, 8, 8, 6, 2, 2, 2, 8, 8, 6, 6, 4, 6, 2, 8,
                                  8, 8, 8, 2, 4, 9, 8, 2, 6, 2, 8, 8, 6, 4, 2,
                                  2, 6, 6, 8, 2, 3, 3, 6, 9, 2, 5, 8, 2, 8, 4,
                                  8, 8, 4, 8, 6, 8, 2, 2, 6, 8, 8, 8, 6, 2, 6,
                                  2, 2, 4, 2, 6, 6, 6, 2, 6, 8, 8, 6, 2, 2, 8,
                                  2, 2, 8, 2, 2, 4, 8, 6, 8, 8, 7, 7, 4, 2, 6,
                                  5, 8, 8, 3, 8, 7, 7, 4, 2, 6, 5, 8, 8, 3, 8,
                                  4, 4, 6, 8, 3, 7, 6, 4, 2, 2, 2, 2, 8, 8, 6,
                                  5, 2, 6, 6, 4, 6, 6, 3, 6, 2, 4, 6, 2, 6, 2,
                                  5, 5, 7, 5, 4, 5, 2, 4, 6, 5, 8, 8, 6, 2, 6,
                                  2, 2, 4, 2, 6, 8, 8, 4, 6, 2, 4, 4, 8, 2, 6,
                                  3, 3, 2, 6, 6, 6, 2, 2, 6, 2, 8, 8, 2, 4, 2,
                                  5, 6, 6, 2, 2, 8, 8, 6, 8, 6, 4, 6, 3, 8, 4,
                                  8, 8, 6, 8, 6, 4, 6, 3, 8, 4, 6, 6, 6, 6, 8,
                                  8, 2, 2, 6, 6, 8, 8, 6, 4, 2, 2, 6, 6, 8, 2,
                                  6, 6, 8, 2, 6, 6, 8, 6, 6, 6, 4, 4, 8, 2, 6,
                                  2, 8, 6, 6, 8, 6, 6, 2, 6, 8, 8, 6, 2, 2, 8,
                                  3, 3, 2, 6, 6, 6, 2, 2, 6, 2, 8, 8, 6, 8, 6,
                                  6, 2, 6, 1, 2, 4, 4, 6, 2, 6, 8, 8, 2, 2, 8,
                                  9, 9, 8, 4, 8, 2, 2, 8, 4, 8, 9, 9, 8, 4, 8,
                                  2, 2, 8, 4, 8, 8, 8, 8, 2, 4, 9, 8, 2, 6, 2,
                                  4, 4, 2, 8, 8, 5, 2, 4, 2, 8, 8, 8, 4, 8, 6,
                                  8, 2, 2, 6, 8, 2, 2, 9, 5, 8, 2, 4, 5, 8, 2,
                                  2, 2, 8, 2, 2, 4, 8, 6, 8, 8, 8, 8, 2, 4, 2,
                                  5, 6, 6, 2, 2, 4, 4, 6, 2, 6, 8, 8, 2, 2, 8,
                                  8, 8, 2, 8, 8, 2, 8, 2, 8, 2, 1};


int main() {

    int n;
    cin >> n;
    cout << A.at(n) << '\n';

    return 0;
}
